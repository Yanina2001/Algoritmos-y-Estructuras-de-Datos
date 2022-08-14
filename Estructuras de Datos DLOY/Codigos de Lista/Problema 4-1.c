#include<stdio.h>
#include<stdlib.h>

double *arreglo (double N);
double suma (double *arrg, int lon);
double promedio (double p, int num);
void liberarMemoria(double *m);

int main(){
	
	double N, *arr,resultado, prom; 
	int i=0;
	
	
	printf("ingrese el tamano del arreglo: ");
	scanf("%lf", &N);//se le asigna tamano al arreglo
	
	printf("\n");
	
	arr=arreglo(N); //se creara el arreglo
	
	for(i=0; i<N; i++){
   
        printf("arr[%d]= %lf \n", i, arr[i]);
   }
	
	resultado=suma (arr, N);//funcions para la suma
	printf("la suma es= %lf \n", resultado);
	
	prom=promedio (resultado, N);//funcion para calcular el promedio
	printf("El promedio es: %lf", prom); //imprime promedio
	
	liberarMemoria(arr); //libera la memoria del arreglo

	return 0;
}


double *arreglo (double N) { //crea al arreglo
   double *arr= NULL;
   int i; 
   
   if (N<=0){
   return(NULL); //si el tamano del arreglo es menor o igual que 0 no sera valido
   }
   arr= (double *) malloc(N*sizeof(double)); //asigna al arreglo memoria dinamica
   
   for(i=0; i<N; i++){
   	
   	printf("Ingrese un numero: ");
   	scanf("%lf", &arr[i]); //Se llena el arreglo con numeros 
   	
		}
   
  return arr;
}

double suma (double *arr, int lon){ //funcion para la suma
	
	double resultado=0;
	int i=0;
	
	for(i=0; i<lon; i++){
		
		resultado= resultado+ arr[i]; //se suman todos los numeros
	}

	return resultado;
}

double promedio (double p, int num){
	
	double resultado=0;
	
	resultado= p/num; //se hace el promedio de la suma de los numeros
	return resultado;
}

void liberarMemoria(double *m){ //libera la memoria del arreglo
	
	free(m);
}


