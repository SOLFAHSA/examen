#include <iostream>
using namespace std;

struct  Nodo{
int caja;
Nodo *avanzar;

};

void agregar1(Nodo *&,int);
void agregar2(Nodo *&,Nodo*&,int);
void sacar2(Nodo *&,int &);
bool lista_vacia(Nodo *);
void sacar1(Nodo *&,Nodo *&,int &);

int main(){

    Nodo *inicio = NULL;
    Nodo *fin = NULL;


    int caja;
    cout<<"Ingrese Codigo Caja 1:";
    cin>>caja;
    agregar2(inicio,fin,caja);
    cout<<"Ingrese Codigo Caja 2:";
    cin>>caja;
    agregar2(inicio,fin,caja);    
    cout<<"Ingrese Codigo Caja 3:";
    cin>>caja;
    agregar2(inicio,fin,caja);
    
    cout<<"Facturando Las Cajas: ";

    while(inicio!=NULL){
        sacar1(inicio,fin,caja);
        if(inicio!=NULL){
            cout<<caja<<" , ";
        }
        else{
            cout<<caja<<".";
        }
    }  
    return 0;
}
void agregar1(Nodo *&lista,int n)
{
Nodo *nuevo_nodo = new Nodo();
nuevo_nodo->caja=n;
nuevo_nodo->avanzar = lista;
lista=nuevo_nodo;
cout<<"\nElmento "<<n<<" Agregado correctamente"<<endl;

}
bool lista_vacia(Nodo *inicio){
return (inicio==NULL)? true : false;

}
void sacar2(Nodo *&lista,int &n){
Nodo *aux=lista;
n=aux->caja;
lista=aux->avanzar;
delete aux;
}

void agregar2(Nodo *&inicio,Nodo *&fin,int n){
Nodo *nuevo_nodo=new Nodo();
nuevo_nodo-> caja=n;
nuevo_nodo-> avanzar=NULL;
if(lista_vacia(inicio)){        inicio=nuevo_nodo; }
else{        fin->avanzar=nuevo_nodo; }
fin=nuevo_nodo;
cout<<"\tElemento "<<n<<" insertado correctamente"<<endl;
}

void sacar1(Nodo *&inicio,Nodo *&fin,int &n){

n =inicio->caja;
Nodo *aux=inicio;
if(inicio==fin){        inicio=NULL;        fin=NULL;    }
else{        inicio=inicio->avanzar;    }
delete aux;
}
