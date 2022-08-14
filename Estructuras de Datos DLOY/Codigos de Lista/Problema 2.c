#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

int main(){
	char cadena[TAM];// cadena
	char nueva[TAM];
	char longitud;//almacenara el tamaño de la palabra
	char *array= cadena;
	
    printf("Digita una palabra de menos de 10 caracteres: ");
    scanf("%s",cadena);//el usuario ingresa la palabra que invertira

    longitud=strlen(cadena);//se almacen en tamaño de la cadena de caracteres 
    printf("%d \n",longitud);// imprime cuantos caracteres ingresamos
	array+=longitud;
	int i =0, j=0;
    for(i=longitud;i>=0;i--){
    	for(j=0;j<longitud;j++){
	        array-=1; 
			nueva[j]= (*array);// almacenara los caracteres invertidos del arreglo inicial
            printf("%c",nueva[j]); //imprime la cadena invertida del nuevo arreglo
	    }
    }
    
	printf("\n");
    for(i=0;i<longitud;i++){
    	printf("%c",cadena[i]);//imprime la cadena inicial 
	}
    return 0;
}
