#include <stdio.h>
#include <stdlib.h>

char *crearCadena(int N);

void desplegarCadena(char *cadena);
void destruirCadena(char *cadena);

int main(){
	
	int N=10;//tamaño de la cadena
	char *cadena;
	
	cadena = crearCadena(N);//funcion que crea cadena y se almacena 
	
	desplegarCadena(cadena);//funcion que despliega cadena
	destruirCadena(cadena);//funcion para destruir cadena

	return 0;
}

char *crearCadena(int N){
	
   char *cadena;
   

   cadena=(char *) malloc(N*sizeof(char));//se le asigna memoria dinamica a la cadena
   
   return cadena;
	
}

void desplegarCadena(char *cadena){
	
	printf("Ingrese una palabra: \n");
	scanf("%s", cadena); //el usuario ingresa datos a la cadena
	printf("La palabra es: %s", cadena); //se imprime la cadena
}

void destruirCadena(char *cadena){
	
	free (cadena);//se destruye la cadena
}
