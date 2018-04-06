#include<stdio.h>
#include<stdlib.h>

struct elemento{  
	int dato; 
	struct elemento *sig; 
};
typedef struct elemento elemento;
typedef elemento *ptr; 

struct Cola{  
	ptr inicio; 
	ptr fin; 
};

typedef struct Cola Cola; 

Cola crearCola();
void encolar(Cola cola,int dat);
void vacia(Cola cola);
void sacar(Cola cola);

int main(){

}
Cola crearCola(){
	Cola nuevacola;
	nuevacola.inicio=NULL;
	nuevacola.fin=NULL;
	return nuevacola;
}

int primerItem(Cola a){
	return a.fin->dato;
}
void encolar(Cola cola,int dat){
	if(cola.inicio==NULL){
		ptr nuevo= malloc(sizeof(elemento));
        	nuevo->dato=dat;
        	nuevo->sig=NULL;
		cola.fin=nuevo;
		cola.inicio=nuevo;
	}
	else{
		ptr nuevo= malloc(sizeof(elemento));
		nuevo->dato=dat;
		nuevo->sig=cola.inicio;
		cola.inicio=nuevo;
	}
}

void sacar(Cola cola){
	ptr ptractual=cola.inicio;
	ptr ptranterior=NULL;
	while(ptractual!=NULL){
		ptranterior=ptractual;
		ptractual=ptractual->sig;
	}
	cola.fin=ptranterior;
}

void vacia(Cola cola){
	if(cola.inicio==NULL){
		printf("La cola esta vacia");
	}
	else{
		printf("La cola tiene elementos");
	}
}
