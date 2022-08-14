#include <stdio.h>
#include <stdlib.h>

int *crearArreglo(int N);
void destruirArreglo(int *arr);

int main(){
	
	
	*crearArreglo(10); //se crea un arreglo de tamano 10
	destruirArreglo(crearArreglo(10));//destruye el arreglo

	printf("\n");
	
	*crearArreglo(100);//se crea un arreglo de tamano 100
    destruirArreglo(crearArreglo(100));//destruye el arreglo
	
	*crearArreglo(1000);//se crea un arreglo de tamano 1000
	destruirArreglo(crearArreglo(1000));//destruye el arreglo
	
    return 0;
}

int *crearArreglo(int N){
   int *arr= NULL;
   int k;
   
   if (N<=0){
    return(NULL); //si no hay tamano en el arreglo regresara un NULL
   }
    
   arr= (int *) malloc(N*sizeof(int)); //asigna memoria dinamica al arreglo
   
   for ( k=0; k<N; k++)
	printf("arr[%d]= %d\n", k, arr[k]); //imprime el arreglo
   
   return(arr);
}


void destruirArreglo(int *arr)
{
  free(arr); //free hara que el arreglo se destruya
}
