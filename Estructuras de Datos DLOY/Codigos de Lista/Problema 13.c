//Codifique un algoritmo recursivo para calcular el factorial mayor igual para 0 y menor o igual que 13
#include <stdio.h>

int funcion_factorial(int numero);

int main(){
    int dato_numero,resultado;
    printf("Recursividad\nFactorial de un numero.\n");
    printf("Digite un numero, este debe ser mayor igual que 0 pero menor igual que 13: \n");
    scanf("%d",&dato_numero);
    
    while(dato_numero>13 || dato_numero<0){ //si el numero no esta dentro del rango, hara un ciclo para ingresar uno valido
    	printf("Por favor digita un numero que este dentro del rango: \n");
    	scanf("%d",&dato_numero);
	}
	
    resultado=funcion_factorial(dato_numero); //hara el proceso de recursion y se almacenara el resultado
	printf("\nEl resultado es:%d",resultado);
}

int funcion_factorial(int numero){ //funcion para calcular el factorial de manera recursiva
    if(numero==0){
        return 1; 
    }
    else{
        return numero*funcion_factorial(numero-1);
    }
}
