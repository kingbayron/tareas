#include <stdlib.h>
#include <stdio.h>

void makeheap ( int [ ], int ) ;
void heapsort ( int [ ], int ) ;

int main(){
	int numeros,i;
	printf("ingrese la cantidad de numeros \n");
	scanf("%i",&numeros);
	int arbol[numeros];
	for(i=0;i<numeros;i++){
		scanf("%i",&arbol[i]);
	}
	for(i=0;i<numeros;i++){
		if(2*i+2==numeros){
			printf("%i,%i\n",arbol[i],arbol[2*i+1]);
		}
		if(2*i+2<numeros){
			printf("%i,%i,%i\n",arbol[i],arbol[(2*i)+1],arbol[(2*i)+2]);
		}
		if(2*i+1>=numeros){
			printf("%i\n",arbol[i]);
		}
	}
	printf("fin");
	makeheap(arbol,numeros);
	heapsort(arbol,numeros);
	for(i=0;i<numeros;i++){
		printf("%i\n",arbol[i]);
	}
}

void makeheap ( int x[ ], int n )
{
    int i, val, s, f ;
    for ( i = 1 ; i < n ; i++ )
    {
        val = x[i] ;
        s = i ;
        f = ( s - 1 ) / 2 ;
        while ( s > 0 && x[f] < val )
        {
            x[s] = x[f] ;
            s = f ;
            f = ( s - 1 ) / 2 ;
        }
        x[s] = val ;
    }
}

void heapsort ( int x[ ], int n )
{
    int i, s, f, ivalue ;
    for ( i = n - 1 ; i > 0 ; i-- )
    {
        ivalue = x[i] ;
        x[i] = x[0] ;
        f = 0 ;

        if ( i == 1 )
            s = -1 ;
        else
            s = 1 ;

        if ( i > 2 && x[2] > x[1] )
            s = 2 ;

        while ( s >= 0 && ivalue < x[s] )
        {
            x[f] = x[s] ;
            f = s ;
            s = 2 * f + 1 ;

            if ( s + 1 <= i - 1 && x[s] < x[s + 1] )
                s++ ;
            if ( s > i - 1 )
                s = -1 ;
        }
        x[f] = ivalue ;
    }
}
