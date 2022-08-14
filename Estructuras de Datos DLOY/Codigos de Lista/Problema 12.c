#include <stdio.h>
#include <stdlib.h>

int BusquedaBinaria(int Arr[], unsigned int TamArr, int x);
int main(){
	
	int Arr[]= {1,2,4,16,28,29,33,40,52,54,55,58,59,64,65,75,83,89,90,94,95};
	unsigned int TamArr= sizeof Arr / sizeof Arr[0]; //tamano del arreglo
	int x;//numero que se busca
	printf("Ingrese el numero a buscar:   ");
	scanf("%d",&x);//usuario ingresa el dato
	
	int numero=BusquedaBinaria(Arr,TamArr,x);//se llama a la funcion para buscar el numero por busqueda binaria
	
	if(numero==-1){
		printf("el numero no se encontro");
	} else {
		printf("\n el numero esta en la celda: %d",numero);
	}
	return 0;
}
int BusquedaBinaria(int Arr[], unsigned int TamArr, int x){
	int izquierda=0, derecha = TamArr-1;
	while(izquierda<derecha){
		int mitad= (derecha+izquierda)/2;
		if(Arr[mitad]==x){
			return mitad;
		} else if(Arr[mitad]<x){
			izquierda = mitad+1;
		} else {
			derecha = mitad-1;
		}
	}
	return -1;//regresa -1 si el numero no se encontro
}

