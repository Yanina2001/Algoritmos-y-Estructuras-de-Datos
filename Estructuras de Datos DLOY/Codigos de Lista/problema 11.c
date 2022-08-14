#include <stdio.h>
#include <stdlib.h>
#define VERDADERO	1
#define FALSO		0

void OrdenamientoSeleccion(int *arr, int N);
void OrdenamientoInsercion(int *arr, int N);
void OrdenamientoBurbuja(int *arr, int N);
void OrdenamientoMezcla(int *arr, int N);
void ImprimirArreglo(int *arr, int N);

int main(int argc, char *argv[]){
	int arr[9]= {8,4,1,6,0,3,25,7,9};
	int N= 9, k=0,numero;
	
	printf("Bienvenido al programa de ordenamineto\n");
	printf("Su arreglo es el siguiente: \n");
	ImprimirArreglo(arr, N);
	printf("\n");
	printf("\tOrdenamientoSeleccion-> 1 \n\tOrdenamientoInsercion-> 2\n\tOrdenamientoBurbuja-> 3 \n\tOrdenaminetoMezcla-> 4 \n\n");
	printf("Por favor digite el numero para el metodo que quiera utilizar:");
	scanf("%d",&numero);
	printf("\n");
	
	switch(numero){ //dirigira al metodo que se haya seleccionado
		case 1:
			OrdenamientoSeleccion(arr, N);
			break;
		case 2:
			OrdenamientoInsercion(arr, N);
			break;
		case 3:
			OrdenamientoBurbuja(arr, N);
			break;
		case 4:
			OrdenamientoMezcla(arr, N);
			break;
		default:
			printf("Por favor ingrese una opcion valida");
	}
	return 0;
}

void ImprimirArreglo(int *arr, int N){ //funcion para imprimir arreglo
	int k=0;

	for (k=0; k<N; k++)
	   printf("%d ", arr[k]);
	   
	printf("\n");
}

void OrdenamientoSeleccion(int *arr, int N){
	int i=0, j=0;
	int aux=0;
	
	for (i=0; i<N; i++){	//recorre el pivote	
	   	for (j=i+1; j<N; j++){	
	   		if (arr[i] > arr[j]){ //compara de forma ascendente, si entra en IF permutara 
	   		   	aux= arr[j];
	   		   	arr[j]= arr[i]; 
	   		   	arr[i]= aux;		 
			}
		}
	}
	printf("El arreglo se ordeno por seleccion:\n");
	ImprimirArreglo(arr, N);//imprime el arreglo
}

void OrdenamientoInsercion(int *arr, int N){
	int i=0, j=0;
	int ref=0;
	//compara de forma lineal considerando un elemento con el que esta delente, pasando al lado izq. el menor 
	for (i=0; i<N; i++){
	   	ref= arr[i];
	   	for (j= i-1; j>=0 && ref<arr[j]; j--) //consiciones necesarios para analizar los valores a la derecha
	   	    arr[j+1]= arr[j]; //intercambia numeros	   	    	
	   		arr[j+1]= ref;
	}
	printf("el arreglo se ordeno por insercion:\n");
	ImprimirArreglo(arr, N);
}


void OrdenamientoBurbuja(int *arr, int N){
	int i=0, j=0,auxiliar=0;
	int intercambio= VERDADERO; 
	int L= N-1;
	
	while(intercambio!=FALSO){	
		intercambio= FALSO;	
		
		for (i=0; i<L; i++){
		   	if (arr[i] > arr[i+1]){
				auxiliar= arr[i+1]; //se guarda en auxiliar
		   	   	arr[i+1]= arr[i]; //intercambio de variables
		   	   	arr[i]= auxiliar; //dentro de arr se vuelve almacenar las variables
		   	   	intercambio= VERDADERO;
			}
		}
	}
	printf("el arreglo se ordeno por burbuja:\n");
	ImprimirArreglo(arr, N);//imprime el arreglo
}

void OrdenamientoMezcla(int *arr, int N){
	int *nuevo= NULL;
	int k=0, h=0, q=0, c=0;
	int L= 2*N, corte=0, medio=0;
	int i=0, j=0;
	
	nuevo= (int *) malloc(N*sizeof(int)); //asigna de forma dinamica el tamaño del arreglo
	
	for (q=0; q<N; q++) //alacenara en todo el arreglo un 0
	   nuevo[q]= 0;
	
	for (k=2, h=1; k<L; k*=2, h*=2){
	   		for (q=0; q<N; q+=k){		
	   		   		corte= q+k; //corta el arreglo
	   		   		if (corte>N) 
	   		   		  corte= N;
	   		   		medio= q+h; 
	   		   		if (medio>N) 
	   		   		  medio= N;
	   		   		
	   		   		i= q;
	   		   		j= medio;
	   		   		
	   		   		for (c=q; c<corte; c++){ //se hara cortes hasta terminar de ordenar el arreglo
					   		if (arr[i]<arr[j] && i<medio || j>=corte){
					   		  	nuevo[c]= arr[i]; //se almacena las variables en un nuevo arreglo
					   		  	i++;
							}
							else{							
								if (arr[i]>=arr[j] && j<corte || i>=medio){
							  		nuevo[c]= arr[j]; //se almacena las variables en un nuevo arreglo
					   		  		j++;
							  	}
							}
					}					
			   }   
			for (q=0; q<N; q++)
			   arr[q]= nuevo[q]; //se almacena las variables de nuevo en arr
	}
	printf("el arreglo se ordeno por mezcla:\n");
	ImprimirArreglo(arr, N);	
	free(nuevo); //libera la memoria
}

