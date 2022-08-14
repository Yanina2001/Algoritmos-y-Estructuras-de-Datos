/*
Recombinación y selección. Día 4, 17:00 hrs. Regrese a la base aérea y 
cargue materiales de construcción a su avión. Cada material tiene un número, 
al azar, que lo identifica. Implemente de forma iterativa o recursiva un 
algoritmo híbrido que ordene subarreglos de números por las técnicas  de 
mezcla  y  selección.  Su  programa  debe  utilizar  exclusivamente  aritmética  
de apuntadores  para  desplazarse  a  través  del  arreglo.  Calcule  la  
complejidad  computacional temporal de su algoritmo.
*/

#include <stdio.h>
#include <stdlib.h>
#define VERDADERO	1
#define FALSO		0

//DE LUNA OCAMPO YANINA

void OrdenamientoSeleccion(int *arr, int N);
void OrdenamientoMezcla(int *arr, int N);
void ImprimirArreglo(int *arr, int N);

int main(int argc, char *argv[]){
	int arr[10]= {8,6,3,9,4,7,2,5,1,10};
	int N = 10, k=0,numero;
	//hacemos impresion del arreglo dado previamente
	printf("Su arreglo es el siguiente: \n");
	ImprimirArreglo(arr, N);
	printf("\n");
	//una lista de los materiales elegidos
    printf("Materiales: \n 1. Material1\n 2. Material2\n 3. Material3\n 4. Material4\n 5. Material5\n 6. Material6\n 7. Material7\n 8. Material8\n 9. Material9\n 10. Material10\n");
	printf("\n");
	//los dos ordenamientos pedidos, a eleccion del usuario
	printf("\tOrdenamientoSeleccion-> 1 \n\tOrdenaminetoMezcla-> 2 \n\n");
	//pedimos al usuario digitar el ordenamiento que desee elegir
	printf("Por favor digite el numero para el metodo que quiera utilizar: ");
	scanf("%d",&numero);
	printf("\n");
	//dirigira al metodo que se haya seleccionado
	switch(numero){ 
		case 1:
			OrdenamientoSeleccion(arr, N);
			break;
		case 2:
			OrdenamientoMezcla(arr, N);
			break;
		default:
			printf("Por favor ingrese una opcion valida");
	}
	return 0;
}
//funcion para imprimir arreglo
void ImprimirArreglo(int *arr, int N){ 
	int k=0;

	for (k=0; k<N; k++)
	   printf("%d ", arr[k]);
	   
	printf("\n");
}
//funciones desglosadas
//funcion para imprimir arreglo
void OrdenamientoSeleccion(int *arr, int N){
	int i=0, j=0;
	int aux=0;
	//recorre el pivote
	for (i=0; i<N; i++){		
	   	for (j=i+1; j<N; j++){
			//compara de forma ascendente, si entra en IF permutara 	
	   		if (arr[i] > arr[j]){ 
	   		   	aux= arr[j];
	   		   	arr[j]= arr[i]; 
	   		   	arr[i]= aux;		 
			}
		}
	}
	//imprime el arreglo
	printf("El arreglo se ordeno por seleccion:\n");
	ImprimirArreglo(arr, N);
}
//funcion para imprimir arreglo
void OrdenamientoMezcla(int *arr, int N){
	//declaramos variables a utilizar
	int *nuevo= NULL;
	int k=0, h=0, q=0, c=0;
	int L= 2*N, corte=0, medio=0;
	int i=0, j=0;
	//asigna de forma dinamica el tamanio del arreglo
	nuevo= (int *) malloc(N*sizeof(int)); 
	//alacenara en todo el arreglo un 0
	for (q=0; q<N; q++) 
	   nuevo[q]= 0;
	
	for (k=2, h=1; k<L; k*=2, h*=2){
	   		for (q=0; q<N; q+=k){
				    //corta el arreglo		
	   		   		corte= q+k;
	   		   		if (corte>N) 
	   		   		  corte= N;
	   		   		medio= q+h; 
	   		   		if (medio>N) 
	   		   		  medio= N;
	   		   		
	   		   		i= q;
	   		   		j= medio;
	   		   		//se hara cortes hasta terminar de ordenar el arreglo
	   		   		for (c=q; c<corte; c++){ 
					   		if (arr[i]<arr[j] && i<medio || j>=corte){
								//se almacena las variables en un nuevo arreglo
					   		  	nuevo[c]= arr[i]; 
					   		  	i++;
							}
							else{							
								if (arr[i]>=arr[j] && j<corte || i>=medio){
									//se almacena las variables en un nuevo arreglo
							  		nuevo[c]= arr[j]; 
					   		  		j++;
							  	}
							}
					}					
			   }   
			for (q=0; q<N; q++)
				//se almacena las variables de nuevo en arr
			   arr[q]= nuevo[q]; 
	}
	printf("el arreglo se ordeno por mezcla:\n");
	ImprimirArreglo(arr, N);
	//libera la memoria	
	free(nuevo); 
}