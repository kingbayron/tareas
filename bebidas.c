#include<stdio.h>
#include<stdlib.h>

typedef struct diccionario{
int key;
char texto[51];
}diccionario;

void cambiarlugar(int cambiar,int pivote,int a[],int cantidad){
	int i;
	int lugar1;
	int lugar2;
	char nuevo[cantidad];
	for(i=0;i<cantidad;i++){
		if(a[i]==pivote){
			lugar1=i;
		}
	}
	for(i=0;i<cantidad;i++){
                if(a[i]==cambiar){
                        lugar2=i;
                }
        }

	for(i=0;i<lugar1;i++){
		nuevo[i]=a[i];
	}
	nuevo[lugar1]=cambiar;
	for(i=lugar1+1;i<lugar2+1;i++){
		nuevo[i]=a[i-1];
	}
	for(i=lugar2+1;i<cantidad;i++){
		nuevo[i]=a[i];
	}
	for(i=0;i<cantidad;i++){
		a[i]=nuevo[i];
	}
}

int main(){
	printf("Ingrese la cantidad de bebidas");
	int cantidad;
	int i;
	scanf("%i",&cantidad);
	diccionario dict[cantidad];
	char bebidas[cantidad][51];
	for(i=0;i<cantidad;i++){
		printf("Ingrese la bebida %i",i);
		dict[i].key=i;
		scanf("%s",bebidas[i]);
		printf("Ingrese la bebida nuevamente %i",i);
		scanf("%s",dict[i].texto);
	}
	int beb[cantidad];
	for(i=0;i<cantidad;i++){
		beb[i]=i;
	}
	int cantidad2;
	printf("Ingrese la cantidad de relaciones");
	scanf("%i",&cantidad2);
	int relaciones[cantidad2*2];
	printf("Usando la sgte tabla de numero bebida ingrese el numero de bebida que corresponda para las relaciones\n");
	for(i=0;i<cantidad;i++){
		printf("Bebida numero %i -> %s\n",dict[i].key,dict[i].texto);
	}
	for(i=0;i<=(cantidad2*2)-1;i=i+2){
		printf("Ingrese el numero de la bebida mas debil para la relacion %i ",i+1);
		scanf("%i",&relaciones[i]);
		printf("Ingrese el numero de la bebida mas fuerte para la relacion %i ",i+1);
		scanf("%i",&relaciones[i+1]);
	}
	int j;
	for(i=0;i<3;i++){
		for(j=0;j<(cantidad2*2)-1;j=j+2){
			cambiarlugar(relaciones[j],relaciones[j+1],beb,cantidad);
		}
	}
	printf("Deberia tomar las bebidas en el siguiente orden\n");
	for(i=0;i<cantidad;i++){
		printf("%s ->",bebidas[beb[i]]);
	}
	printf("\n");

}
