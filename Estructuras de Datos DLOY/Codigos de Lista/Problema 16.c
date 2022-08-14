#include <stdio.h>
#include <stdlib.h>

void moverDisco(char destino, char auxiliar, char fuente, int N, int *contador);

int main(){
    char fuente= 'A', auxiliar= 'B', destino= 'C'; //nombres para los 3 pivotes de hanoi
	int N= 0; //inicializamos numero de discos
	int contador= 1; //contara el numero de movimientos, siempre iniciliza en movimiento 1
	printf("Bienvenidos al programa de Torres de Hanoi \n");
	printf("Ingrese el numero de discos: ");
	scanf("%d",&N);
	moverDisco(destino, auxiliar, fuente, N, &contador); //funcion recursiva que resolvera hanoi
	return 0;
	}
	
void moverDisco(char destino, char auxiliar, char fuente, int N, int *contador){
	
    if (N==0) //cuando N sea 0 terminara la recursion 
	return;
    
	moverDisco(auxiliar, destino, fuente, N-1, contador);
	printf("%d. Mover disco %d: de %c a %c\n",*contador, N, fuente, destino);//imprimira el movimiento
	(*contador)++; //sumara 1 el contador para cada movimiento que se tenga 
	moverDisco(destino, fuente, auxiliar, N-1, contador);
}
