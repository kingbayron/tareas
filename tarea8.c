#include <stdlib.h>
#include <stdio.h>
void mayor(int n,int recorrido[][3],int mayores[][2]);
void recorrer(int n,int recorrido[][3],int matriz[][26]);
int dist(int nousar[],int matriz[][26],int punto,int pos);
void nousar(int a[],int b);


int main(){
	int n,i,j;
	printf("Ingrese la cantidad de nodos");
	scanf("%i",&n);
	int matriz[n+1][n+1];
	for(i=0;i<n+1;i++){
		for(j=0;j<=n;j++){
			matriz[i][j]=0;
		}
	}
	for(i=1;i<=n;i++){
		matriz[i][0]=64+i;
		matriz[0][i]=64+i;
	}
	char a,b;
	int numero;
	scanf("%c",&a);
	while(a!='0'){
		int ii=(int)a-45;
		scanf("%c",&b);
		int jj=(int)b-45;
		scanf("%i",&numero);
		matriz[ii][jj]=numero;
		matriz[jj][ii]=numero;
		scanf("%c",&a);
	}
	int ii,jj;
	scanf("%c",&a);
	scanf("%c",&b);
	ii=(int)a-65;
	jj=(int)b-65;
	int matriz2[n][n+1];
        for(i=0;i<n;i++){
                for(j=0;j<=n;j++){
                        matriz[i][j]=0;
                }
        }
	matriz2[0][0]=(int)a;
	matriz2[n][0]=(int)b;
        for(i=1;i<n;i++){
		if(64+i!=(int)a && 64+i!=(int)b){
                	matriz2[i][0]=64+i;
                }
	}
	int distancia=0;
	int menor=100;
	int nousa[1];
	nousa[0]=0;
	for(j=1;j<=n;j++){
		for(i=1;i<n;i++){
			matriz2[i][j]=distancia+dist(nousa,matriz,ii,i);
		}
		int lugar;
		for(i=0;i<n;i++){
			if(matriz2[i][j]!=0 && matriz2[i][j]<menor && matriz2[i][j]!=distancia){
				menor=matriz2[i][j];
				lugar=i;
			}
		}
		matriz2[lugar][2]=menor;
		distancia=distancia+menor;
		nousar(nousa,lugar);
	}
	int recorrido[n][3];
	recorrer(n,recorrido,matriz2);
	int mayores[n][2];
	mayor(n,recorrido,mayores);
	int menors=mayores[0][1];
	int lugarfinal;
	for(i=1;i<n;i++){
		if(menors>mayores[i][1]){
			lugarfinal=i;
			menors=mayores[i][1];
		}
	}
	char qaz=(char)64+lugarfinal;
	printf("Deben encontrarce en la punto %c",qaz);
}
int dist(int nousar[],int matriz[][26],int punto,int pos){
	int i;
	for(i=0;i<sizeof(nousar)/sizeof(nousar[0]);i++){
		if(nousar[i]==punto){
			return 0;
		}
	}
	return matriz[punto][pos];
}
void nousar(int a[],int b){
	int l=sizeof(a)/sizeof(a[0]);
	int c[l+1];
	int i;
	for(i=0;i<l;i++){
		c[i]=a[i];
	}
	c[l]=b;
	a=c;
}
void recorrer(int n,int recorrido[][3],int matriz[][26]){
	int contador=0,i,j;
	for(i=0;i<n;i++){
		recorrido[i][0]=matriz[i][0];
	}
	recorrido[0][1]=0;
	recorrido[n][2]=0;
	recorrido[n-1][1]=matriz[n-1][n+1];
	recorrido[0][2]=recorrido[n-1][1];
	for(i=1;i<n-1;i++){
		for(j=1;j<=n;j++){
			if(matriz[i][j+1]==0){
				recorrido[i][1]=matriz[i][j];
			}
		break;
		}
	}
	for(i=1;i<n-1;i++){
		recorrido[i][2]=recorrido[0][2]-recorrido[i][1];
	}
}
void mayor(int n,int recorrido[][3],int mayores[][2]){
	int i;
	for(i=0;i<n;i++){
		mayores[i][0]=recorrido[i][0];
		if(recorrido[i][1]>recorrido[i][2]){
			mayores[i][1]=recorrido[i][1];
		}
		else{
			mayores[i][1]=recorrido[i][2];
		}
	}
}

