#include <stdio.h>
#include <stdlib.h>

void ordenarArreglo(int *arreglo, int N);
void desordenarArreglo(int *arr, int N);

int main(){
	
   int *arr= NULL;
   int N, i;
   
   	printf("Ingrese el tamano del arreglo ");
	scanf("%d", &N);//se le asigna tamano al arreglo
   
   if (N<=0){
        return(NULL); //si el tamando es igual o menor que 0 sera invalido
       }
     
   arr= (int *) malloc(N*sizeof(int)); //se le asigna memoria dinamica al arreglo
   
   for(i=0; i<N; i++){
   	
   	    printf("Ingrese un numero: ");
   	    scanf("%d", &arr[i]); //el usuario introduce numeros al arreglo
   	
		}
		
	for(i=0; i<N; i++){ 
        printf("arr[%d]= %d \n", i, arr[i]);//se imprime el arreglo ingresado
        }
	
	printf("\n");

	ordenarArreglo(arr, N);//funcion para ordenar arreglo
	
	desordenarArreglo(arr, N);//funcion para desordenar arreglo
	
	return 0;
}

void ordenarArreglo(int *arr, int N){
	
	int i,j, auxiliar;
	
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			
			if(arr[j]> arr[j+1]){ //se hace cambio de variable
				
				auxiliar=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=auxiliar;
			}
		}
	}
	
	printf("Arreglo ordenado:");
	for(i=0; i<N; i++){
		printf(" %d-> ", arr[i]);//se imprime el arreglo ordenado
	}
	printf("\n");
}

void desordenarArreglo(int *arr, int N){
	int i, j, auxiliar;
	
		for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			
			if(arr[j]> arr[j-1]){ //se hace cambio de variables
				
				auxiliar=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=auxiliar;
			}
		}
	}
	printf("arreglo desordenado:");
	for(i=0; i<N; i++){
		printf(" %d-> ", arr[i]); //se imprime el arreglo desordenado
	}
	printf("\n");
}
