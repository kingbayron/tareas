#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct telefono{
        int numero;
        struct telefono *sgte;
};

typedef struct telefono Telefono;
typedef Telefono *ptrTelefono;

struct correo{
        char *email;
        struct correo *sgte;
};

typedef struct correo Correo;
typedef Correo *ptrCorreo;

struct nodo{
        int id;
        char *Nombre;
        ptrCorreo ptrCorreos;
        ptrTelefono ptrTelefonos;
        struct nodo *sgte;
};

typedef struct nodo Nodo;
typedef Nodo *ptrNodo;

void agregar(ptrNodo *ptrS,int num,char nombre[]);
void agregarnum(ptrTelefono *ptrS,int num);
void agregarnom(ptrCorreo *ptrS, char a[]);
void imprimir(ptrNodo ptrS);

void imprimir(ptrNodo ptrS){
        while(ptrS != NULL){
                printf("ID : ");
                printf("%i \n ",ptrS->id);
                printf("Nombre: ");
                printf("%s \n",ptrS->Nombre);
                printf("Telefonos: \n");
                ptrTelefono ptrtel=ptrS->ptrTelefonos;
                while(ptrtel != NULL){
                        printf("%i \n",ptrtel->numero);
                        ptrtel=ptrtel->sgte;
                }
                printf("Correos: \n");
                ptrCorreo ptrco=ptrS->ptrCorreos;
                while(ptrco != NULL){
                        printf("%s \n",ptrco->email);
                        ptrco=ptrco->sgte;
                }

                ptrS = ptrS->sgte;
        }
}
void agregar(ptrNodo *ptrS,int num, char nombre[]){
        ptrNodo ptrNuevo;
        ptrNodo ptrAnterior;
        ptrNodo ptrActual;
        ptrNuevo=malloc(sizeof(Nodo));
        if(ptrNuevo!=NULL){
                ptrNuevo->id=num;
                int i;
                int contador = 0;
                for (i=0;i<30;i++){
                        if(nombre[i]=='\0'){
                                break;
                        }
                        contador++;
                }
                ptrNuevo->Nombre= malloc(sizeof(char)*contador);
                for (i=0;i<contador;i++){
                        ptrNuevo->Nombre[i] = nombre[i];
                }

                ptrNuevo->ptrTelefonos=NULL;
                ptrNuevo->sgte=NULL;
                ptrAnterior= NULL;
                ptrActual=*ptrS;
                while(ptrActual!=NULL){
                ptrAnterior=ptrActual;
                ptrActual=ptrActual->sgte;
                }
                if(ptrAnterior==NULL){
                        ptrNuevo->sgte=*ptrS;
                        *ptrS=ptrNuevo;
                }
                else{
                        ptrAnterior->sgte=ptrNuevo;
                        ptrNuevo->sgte=ptrActual;
                }
        }
        else{
                printf("No hay memoria disponible");
        }

}

void agregarnum(ptrTelefono *ptrS,int num){
        ptrTelefono ptrNuevo;
        ptrTelefono ptrAnterior;
        ptrTelefono ptrActual;
        ptrNuevo=malloc(sizeof(Telefono));
        if(ptrNuevo!=NULL){
                ptrNuevo->numero=num;
                ptrNuevo->sgte=NULL;
                ptrAnterior= NULL;
                ptrActual=*ptrS;
                while(ptrActual!=NULL){
                ptrAnterior=ptrActual;
                ptrActual=ptrActual->sgte;
                }
                if(ptrAnterior==NULL){
                        ptrNuevo->sgte=*ptrS;
                        *ptrS=ptrNuevo;
                }
                else{
                        ptrAnterior->sgte=ptrNuevo;
                        ptrNuevo->sgte=ptrActual;
                }
        }
        else{
                printf("No hay memoria disponible");
        }

}

void agregarnom(ptrCorreo *ptrS,char a[]){
        ptrCorreo ptrNuevo;
        ptrCorreo ptrAnterior;
        ptrCorreo ptrActual;
        ptrNuevo=malloc(sizeof(Nodo));
        if(ptrNuevo!=NULL){
                int i;
                int contador = 0;
                for (i=0;i<36;i++){
                        if(a[i]=='\0'){
                                break;
                        }
                        contador++;
                }
                ptrNuevo->email = malloc(sizeof(char)*contador);
                for (i=0;i<contador;i++){
                        ptrNuevo->email[i] = a[i];
                }
                ptrNuevo->sgte=NULL;
                ptrAnterior= NULL;
                ptrActual=*ptrS;
                while(ptrActual!=NULL){
                ptrAnterior=ptrActual;
                ptrActual=ptrActual->sgte;
                }
                if(ptrAnterior==NULL){
                        ptrNuevo->sgte=*ptrS;
                        *ptrS=ptrNuevo;
                }
                else{
                        ptrAnterior->sgte=ptrNuevo;
                        ptrNuevo->sgte=ptrActual;
                }
        }
	else{
                printf("No hay memoria disponible");
        }

}

