//Colas

#include<iostream>
#include<stdlib.h>

using namespace std;



class Cola{
	
	int dato;
	Cola *sig;
	
	public:
		
		void IniciarCola(Cola *&cab1, Cola *&cab2){
			
			//Primera cabeza
			cab1=new Cola;
			cab1->dato=-1;
			
			//Segunda cabeza
			cab2=new Cola;
			cab2->dato=-1;
			
			//conexion
			cab1->sig=cab2;
			cab2->sig=NULL;
		}
		
		void agregarElemento(Cola *&cab1,Cola *&cab2, int dato){
			Cola *aux=cab1; 
			Cola *aux2=cab2;
			while(aux->sig!=cab2){
				aux=aux->sig;
			}
			
			while(aux2->sig!=NULL){
				aux2=aux2->sig;
			}
			
			cout<<"A Cual Cola Desea Agregar El dato, Elija Una Opcion \n";
			cout<<"\t 1) Agregar Un Nodo Para La Primera Cola \n";
			cout<<"\t 2) Agregar Un Nodo Para La Segunda Cola \n";
			int c;
			cout<<"Opcion: ";cin>>c;
			cout<<" "<<endl;
			if(c==1){
				aux->sig=new Cola;
				aux->sig->dato=dato;
				aux->sig->sig=cab2;	
			}else{
              if(c==2){
                aux2->sig=new Cola;
				aux2->sig->dato=dato;
				aux2->sig->sig=NULL;
            }else{
                cout<<"Opcion Invalida"<<endl;
                cout<<"Intente De Nuevo\n"<<endl;
                agregarElemento(cab1,cab2,dato);
                }
		    }
			
		}
		
		void CrearCola(Cola *&cab1, Cola *&cab2){
			int dato=666;
			while(dato>0){
				cout<<"Numero = ";
		        cin>>dato;
		        if(dato>0){
		        	if(!cab1&&!cab2){
		        		IniciarCola(cab1,cab2);
					}else{
						agregarElemento(cab1,cab2,dato);
					}
				}
			}	
		}
		
		bool ColaVacia1(Cola *cab1,Cola *cab2){ //Verificar si la cola esta vacia, la cola estara vacia si su cabeza en su parte siguiente es igual a nulo (La cabeza nunca desaparece)
			if(cab1->sig==cab2){
				return true;
			}else{
				return false;
			}
		}
		
		bool ColaVacia2(Cola *cab2){ //Verificar si la cola esta vacia, la cola estara vacia si su cabeza en su parte siguiente es igual a nulo (La cabeza nunca desaparece)
			if(cab2->sig==NULL){
				return true;
			}else{
				return false;
			}
		}
		
		void MostrarCola(Cola *cab1, Cola *cab2){
			Cola *aux1=cab1; 
			Cola *aux2=cab2;
			cout<<"\nLas Colas Son\n"<<endl;
			aux1=aux1->sig;
			if(ColaVacia1(cab1,cab2)==true){
			    cout<<"La Primera Cola Esta Vacia"<<endl;
			}else{
				if(ColaVacia1(cab1,cab2)==false){
				while(aux1->sig!=cab2){
				cout<<"Primera Cola : "<<aux1->dato<<endl;
				aux1=aux1->sig;
			    }
				cout<<"Primera Cola : "<<aux1->dato<<endl;
			    cout<<" "<<endl;	
				}
			}
			aux2=aux2->sig;
			if(ColaVacia2(cab2)==true){
				cout<<"La Segunda Cola Esta Vacia"<<endl;
			}else
			if(ColaVacia2(cab2)==false){
				while(aux2->sig!=NULL){
				cout<<"Segunda Cola: "<<aux2->dato<<endl;
				aux2=aux2->sig;
			    }
				cout<<"Segunda Cola: "<<aux2->dato<<endl;
				cout<<" "<<endl;
			}				
		}	
		
		void RetirarElemento(Cola *&cab1, Cola *&cab2){
			Cola *aux1;
			Cola *aux2;
			
			
			
			int op;
			int me;
			do{
				cout<<"EN CUAL COLA DESEA RETIRAR NODOS"<<endl;
				cout<<"\t 1) Cola 1"<<endl;
				cout<<"\t 2) Cola 2"<<endl;
				cin>>me;
				
				if(me==1){
					if(ColaVacia1(cab1,cab2)==true){
						cout<<"La cola (1) esta vacia, no se pueden retirar nodos \n";
						//break;
					}else{
						aux1=cab1->sig;
						cab1->sig=aux1->sig;
						cout<<"Dato eliminado : "<<aux1->dato<<endl;
						delete aux1;
					}
				}else if(me==2){
					if(ColaVacia2(cab2)==true){
						cout<<"La cola (2) esta vacia, no se pueden retirar nodos \n";
						//break;
					}else{
						aux2=cab2->sig;
						cab2->sig=aux2->sig;
						cout<<"Dato eliminado : "<<aux2->dato<<endl;
						delete aux2;
					}
					
				}else{
					cout<<"OPCION INCORRECTA***"<<endl;
				}
				
				cout<<"Desea continuar elimando nodos \n";
				cout<<"\t 1)Si"<<endl;
				cout<<"\t 2)No"<<endl;
				cin>>op;
				
				
			}while(op!=2);	
		}
		
};

	int main(){
		
		Cola c1, *cab1=NULL, *cab2=NULL;
		
			c1.IniciarCola(cab1,cab2);
			c1.CrearCola(cab1,cab2);
			c1.MostrarCola(cab1,cab2);
			c1.RetirarElemento(cab1,cab2);
			c1.MostrarCola(cab1,cab2);
			/*Cola c1, *cab1=NULL, *cab2=NULL;
			c1.IniciarCola(cab1,cab2);
			c1.CrearCola(cab1,cab2);
			c1.MostrarCola(cab1,cab2);
			c1.RetirarElemento(cab1,cab2);*/
			/*cout<<"Verificacion de la cola vacia : "<<c1.ColaVacia(cab1,cab2)<<endl;*/
			
					
			return 0;
		}
