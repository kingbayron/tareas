#include<stdio.h>
#include "tarea11.c"
#include<stdlib.h>

int main(){
        ptrNodo ptrInicial =NULL;
        int opcion;
        int id=1;
	printf("Ingrese un 1 si quiere agregar una persona un 2 si quiere ver la libreta o un  0 si quiere salir\n");
        scanf("%i",&opcion);
        while(opcion!=0){
                switch(opcion){
                        case 1:
                                printf("Ingrese el nombre, con un maximo de 30 caracteres, sin espacios\n");
                                char nombre[500];
                                scanf("%s",nombre);
                                agregar(&ptrInicial,id,nombre);
                                id=id+1;
                                printf("Ingrese un 1 para agregar telefono o un 0 para salir\n");
                                int opcion2;
                                scanf("%i",&opcion2);
                                while(opcion2!=0){
                                        int numero;
                                        printf("Ingrese el numero que desae agregar\n");
                                        scanf("%i",&numero);
                                        agregarnum(&(ptrInicial->ptrTelefonos),numero);
                                        printf("Ingrese un 1 para agregar un numero o un 0 para salir\n");
                                        scanf("%i",&opcion2);
                                }
                                printf("Ingrese un 1 para agregar un email o un 0 para salir\n");
                                int opcion3;
                                scanf("%i",&opcion3);
                                while(opcion3!=0){
                                        char buffer[500];
                                        printf("Ingrese el email, con un maximo de 36 caracteres, sin espacios\n");
                                        scanf("%s",buffer);
                                        agregarnom(&(ptrInicial->ptrCorreos),buffer);
                                        printf("Ingrese un 1 para agregar un email o un 0 para salir\n");
                                        scanf("%i",&opcion3);
                                }
                                printf("Ingrese un 1 si quiere agregar una persona un 2 si quiere ver la libreta o un  0 si quiere salir\n");
                                scanf("%i",&opcion);
                                break;
                        case 2:
                                imprimir(ptrInicial);
                                printf("Ingrese un 1 si quiere agregar una persona un 2 si quiere ver la libreta o un  0 si quiere salir\n");
                                scanf("%i",&opcion);
                                break;
			default:
				printf("Ingrese una opcion valida \n");
				printf("Ingrese un 1 si quiere agregar una persona un 2 si quiere ver la libreta o un  0 si quiere salir\n");
                                scanf("%i",&opcion);
                                break;

                }
        }

}


