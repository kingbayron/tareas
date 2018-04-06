#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	int N=0;
	int K=0;
	char *linea1;
	char *algo;
	char *algo2;
	char s2[4]=" \n";
	fgets(linea1,4,stdin);
	algo= strtok(linea1,s2);
	N=atoi(algo);
	while ((algo= strtok (NULL,""))!=NULL){
		algo2=algo;
	}
	K=atoi(algo2);
	int num[N];
	int i=0;
	for(i=0;i<N;i++){
		printf("Ingrese el numero %i de la serie \n", (i+1));
		scanf("%i",&num[i]);
	}
	int j=0;
	while(j<K){
		printf("Ingrese el comando, una C para cambiar un numero o una P para ver el producto\n");
		char comando;
		scanf("%c",&comando);
		if(comando=='c'){
			printf("Ingrese el primer numero\n");
			int lugar;
			scanf("%i",&lugar);
			lugar=lugar-1;
			printf("Ingrese el segundo numero\n");
                        int numero;
                        scanf("%i",&numero);
			num[lugar]=numero;


		}
		if(comando=='p'){
			printf("Ingrese el primer numero\n");
                        int lugar;
                        scanf("%i",&lugar);
			lugar=lugar-1;
                        printf("Ingrese el segundo numero\n");
                        int numero;
                        scanf("%i",&numero);
			int producto=1;
			for(i=lugar;i<=numero;i++){
				producto=producto*num[i];
			}
			if(producto>0){
				printf("+\n");
			}
			if(producto<0){
				printf("-\n");
			}
			if(producto==0){
				printf("0\n");
			}

		}

	j=j+1;
	}

}
