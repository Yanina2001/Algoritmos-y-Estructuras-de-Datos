#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int *arr= NULL;  //arreglo 
	int N=0;	 
	int k;		//inicialización para los ciclos
	
	printf("Arreglo Dinamico \n");
    printf("\nIngrese tamano del arrelgo:");
    scanf("%d",&N);//tamaño para el arreglo
	
	arr= (int *) malloc(N*sizeof(int));//asigna la memoria de forma dinamica al arreglo
	printf("\nDireccion de la memoria del arreglo= %X\n\n", arr);//imprime la dirección de memoria 
	
	for (k=0; k<N; k++){
	   printf("arr[%d]= %d\n", k, arr[k]); //imprime el arreglo sin limpiar
    }
	printf("\n");
	   
	
	for (k=0; k<N; k++){
	   arr[k]= 0;//dará valor de 0 a cada celda del arreglo, se limpia el arreglo
    }
    printf("\n");
    
	for (k=0; k<N; k++){
	   printf("arr[%d]= %d\n", k, arr[k]); //impresion el arreglo
    }
	
	free(arr);	//liberará la memoria para el arreglo
	printf("\narr= %X\n", arr);	//arreglo antes de liberar memoria
	
	arr= NULL;
	printf("arr= %X\n", arr); 	//arreglo despues de liberar memoria
	
	return 0;
}
