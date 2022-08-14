 /*
Campo Aéreo. Ensamblaje de pala cargadora. Día 0, 11:00 hrs. Dirija su avión a los talleres e 
implemente  una  pala  cargadora  cuya  función  sea  remover  N  elementos  contiguos  de  un 
arreglo bidimensional dinámico, guardarlos en un arreglo lineal dinámico y trasladarlos a una 
nueva matriz dinámica, donde los verterá al azar. Emplee apuntadores sencillos, dobles y/o triples
y realice paso de parámetros por referencia,según sea el caso. Una vez que el módulo se encuentre 
funcionandocorrectamente, incorpore la herramienta a su aeronave
*/

#include <stdlib.h> 
#include <stdio.h>
#include <math.h>

//DE LUNA OCAMPO YANINA

int main(void) { 

	//declaramos variables
	int filas, columnas;	
	int *var2, **var1, **var3;	
	int arr;

	arr = filas * columnas;

	//pedimos al usuario que digite el numero que desee
	printf("Digite el numero de filas para la matriz: ");
	scanf("%d",&filas);
	printf("Digite el numero de columnas para la matriz: ");
	scanf("%d",&columnas);

	int i, j;	

	//reservamos memoria con la respectiva cantidad de apuntadores usada
	var1 = (int **)malloc(filas*sizeof(int*)); 
	var2 = (int *)malloc(arr*sizeof(int));
	var3 = (int **)malloc(filas*sizeof(int*)); 

	for (i=0;i<filas;i++){
		var1[i] = (int*)malloc(columnas*sizeof(int));
		var3[i] = (int*)malloc(columnas*sizeof(int)); 
	}

	//asignamos valores a la matriz
	for (i=0; i<filas; i++){ 
		printf("\n"); 
		for (j=0; j<columnas; j++){
			printf("Digite los numeros que desea para la posicion [%d][%d]: ",i,j);
			scanf("%d",&var1[i][j]);
		}
	} 	
	//mostramos en pantalla
	printf("\nAreglo bidimensional: ");
	for (i=0; i<filas; i++){ 
		printf("\n"); 
		for (j=0; j<columnas; j++)
			printf(" %d", var1[i][j] );  
	}
	//en este for guardamos la matriz en un arreglo ld
	for (i=0; i<filas; i++) { 
		for (j=0; j<columnas; j++)
			var2[j+filas*i]=var1[i][j];
	} 
	//imprimimos el arreglo u	
	printf("\nArreglo unidemensional: \n");
	for (i=0; i<arr; i++){
		printf("%d - ",var2[i]);
	}
	//Esta sera nuestra nueva matriz pero con valores aleatorios
	for (i=0; i<filas; i++){ 
		for (j=0; j<columnas; j++)
			var3[i][j]=var2[j+filas*i];
	} 
	//imprimimos nuevamente el arreglo bidimensional con sus nuevos valores
	printf("\nArreglo bidimensional con sus valores nuevos: ");
		for (i=0; i<filas; i++){ 
		printf("\n"); 
			for (j=0; j<columnas; j++) 
				printf(" %d", var3[rand()%filas][rand()%columnas]); 
		}
	free(var1); free(var2);	

	return 0; 
} 