/*
Surcos del nivelador. Nivelación y trazando líneas de gradientes de superficie. Día 2, 18:00 hrs. 
Modele e implemente un módulo de gradiente de superficies matriciales dinámicas el cual trace  
aleatoriamente  curvas  en  la  superficie  y  colecte  el  contenido  en  arreglos  lineales dinámicos  
y  viceversa,  que  el  contenido  de  un  arreglo  dinámico  lineal  lo  vierta  en  curvas aleatorias 
dentro de la matriz. Emplee apuntadores sencillos, dobles y/o triples y realice paso de  parámetros  por  
referencia,  según  sea  el  caso.  Una  vez  que  el  módulo  se  encuentre funcionando correctamente, 
incorpore la herramienta a su aeronave.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//DE LUNA OCAMPO YANINA

int main(){
	//declaramos las varibales a utilizar 
	int **var1=NULL, *var2=NULL, **var3=NULL, i, j, dim, arr;
	arr=pow(dim, 2);
	
	//reservamos la memoris a utilizar
	var1 = (int **)malloc(dim*sizeof(int*)); 
	var2 = (int *)malloc(arr*sizeof(int));
	var3 = (int **)malloc(dim*sizeof(int*)); 
	
	for (i=0;i<dim;i++){
		var1[i] = (int*)malloc(dim*sizeof(int));
		var3[i] = (int*)malloc(dim*sizeof(int));
	}
			
	//inicializamos la matriz
	printf("Digite el valor de la dimension matricial: ");
	scanf("%d",&dim);
	printf("\n");
	//pedimos valores para llenar la matriz
	for (i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			printf("Digite el valor para [%d][%d]: ",i,j);
			scanf("%d",&var1[i][j]);
		}
	}
	//hacemos impresion de la matriz
	printf("\n\nMatriz digitado\n");
	for (i=0; i<dim; i++) { 
		printf("\n"); 
		for (j=0; j<dim; j++){
			printf("\t%d", var1[i][j] ); 
		} 
	}	
	//guardamos la matriz en el arreglo
	for (i=0; i<dim; i++) { 
		for (j=0; j<dim; j++){
			var2[i*dim+j]=var1[i][j]; 
		}
	}
	//imprimimos el arreglo
	printf("\n\nArreglo Unidimensional\n");
	for(i=0; i<pow(dim, 2); i++){
		printf("%d, ",var2[i]);
	}
	//rehacemos la matriz
	for (i=0; i<dim; i++) { 
		for (j=0; j<dim; j++){
			var3[i][j]=var2[i*dim+j]; 
		}
	}
	//imprimimos la nueva matriz	
	printf("\n\nMatriz 'nueva'\n");
	for (i=0; i<dim; i++) { 
		printf("\n"); 
		for (j=0; j<dim; j++){
			printf("\t%d", var3[i][j] ); 
		} 
	}
	
	free(var1); free(var2);
	return 0;	
}
