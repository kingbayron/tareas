#include <stdio.h>

void imprimir(int a[], int b[], int c[],int d);
void mover(int n, int a[], int b[], int c[],int d);
void creartorrevacia(int a[],int b);
void creartorre(int a[], int b);
int poop(int a[],int b);
void push(int a[], int b,int d);
void ingresar(int a[],int b,int d);
void sacar(int a[],int b);

int main(){
	int discos;
	scanf("%d",&discos);
	int torre1[discos];
	int torre2[discos];
	int torre3[discos];
	creartorre(torre1,discos);
	creartorrevacia(torre2,discos);
	creartorrevacia(torre3,discos);
        imprimir(torre1,torre2,torre3,discos);
	mover(discos,torre1,torre2,torre3,discos);
}
void imprimir(int a[], int b[], int c[],int d){
	int n;
        for(n = 0; n < d; ++n){
            printf("%u  %u  %u  \n", a[n],b[n],c[n]);
	}

	printf("\n");
	printf("\n");
}

void mover(int n, int a[], int b[], int c[],int d){
	if(n==1){
		int elem;
		elem=poop(a,d);
                push(c,elem,d);
		imprimir(a,b,c,n);
	}else{
                mover(n-1,a,b,c,d);
                int elem;
                elem=poop(a,d);
                push(c,elem,d);
		imprimir(a,b,c,n);
		mover(n-1,b,c,a,d);
		elem=poop(b,d);
                push(a,elem,d);
		imprimir(a,b,c,n);
        }
}


void creartorrevacia(int a[],int b){
        int i;
        for (i=0; i<b; i++){
        	a[i]=0;
        }
}


void creartorre(int a[],int b){
	int i;
	for (i=0; i<b; i++){
        	a[i]=i+1;
        }
}
int poop(int a[],int b){
	int elem;
	elem=a[0];
	sacar(a,b);
return elem;
}

void push(int a[], int b,int d){
	ingresar(a,b,d);

}
void ingresar(int a[],int b,int d){
        int c[d];
        int i;
        c[0]=b;
        for(i=1; i<d;i++){
                c[i]=a[i-1];
        }
        for(i=0; i<d;i++){
                a[i]=c[i];
        }
}

void sacar(int a[],int b){
        int c[b];
        int i;
        if(b==1){
            a[0]=0;
        }else{
            int aux=0;
            for(i=0;i<b;i++){
                aux=a[i+1];
                a[i]=aux;
            }
            a[b-1]=0;
        }
}
