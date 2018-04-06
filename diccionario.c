#include <stdlib.h>
#include <stdio.h>

typedef struct diccionario{
int key;
char texto[51];
}diccionario;

//Claro, puede parecer burdo llamar a estra estructura para devolver una palabra,
//porque es lo mismo que podr�as hacer con un arreglo de char,
//Pero si en vez de que tu key sea un INT, y es una palabra... y puedes devolver
//arreglos de nodos, otras palabras, palabra a numero.
// por ejemplo, podr�a ser la key el trago y en vez de el texto, la lista
//de tragos que son mas fuertes que �l.

char *traerValor(int key, diccionario* dict,int largo){
	int i;
	for(i=0;i<largo;i++){
		if(dict[i].key == key){
			return dict[i].texto;
		}
	}
	return "Palabra No encontrada";
}

void main(){
	diccionario dict[2];
	int i,llave;
	//DIVIDO EL TAMAÑO QUE USA EN MEMORIA EN BYTES, POR EL TIPO DE DATO EN BYTES
	int largoArreglo = sizeof(dict)/sizeof(dict[0]);
	printf("EL LARGO DE UN ARREGLO ESTÁTICO ES: %d\n",largoArreglo);
	for(i=0 ; i<largoArreglo ; i++){
		dict[i].key=i;
		printf("Ingrese bebida\n");
		scanf("%s",dict[i].texto);
	}
	printf("Ingrese número de bebida a buscar:\n");
	scanf("%d",&llave);
	printf("El el texto de %d es %s\n",traerValor(llave,dict,largoArreglo));
}