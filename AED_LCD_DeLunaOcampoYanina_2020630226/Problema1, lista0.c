/*
.Brillo desierra. Discos de acero girando aalta velocidad. Día 1, 15:00 hrs. 
Diseñee implemente una  sierra  cuya  función  sea  cortar  y  dividir  una  
matriz  dinámica  en  dos  submatrices. Adicionalmente, pruebe la sierra para 
cortar la matriz en filas y en columnas, representadas por  arreglos  lineales  
dinámicos.  Emplee  apuntadores  sencillos,  dobles  y/o  triples  y  realice 
paso de parámetros por referencia, según sea el caso. Una vez que el módulo se 
encuentre funcionando correctamente, incorpore la herramienta a su aeronave.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//DE LUNA OCAMPO YANINA

//declaramos las funciones que vamos a utilizar
int **crearMatriz(int M, int N);
void destruirMatriz(int **matriz, int M);
void iniciaMatriz(int **matriz, int M, int N);
void imprimirMatriz(int **matriz, int M, int N);
void imprimirArreglo(int *matriz, int M);
void multiplicarMatrices(int **matC, int **matA, int **matB, int M, int N, int L);
double valorAbsoluto(double numero);

int main() {
	//declaramos varibales  y pasamos valores
    int **matriz = NULL, *arr = NULL;
    int M= 4, N= 4, sigueProg = 0, cont = 0, i = 0, j = 0, z = 0, ibn = 0, jbn = 0;

    //creamos la matriz
    matriz = crearMatriz(M, N);
    //iniciamos matriz
    iniciaMatriz(matriz, M, N);
    //imprimimos matriz
    imprimirMatriz(matriz, M, N);

    arr = (int*)malloc((M*N)*sizeof(int*));

    //pedimos le valor deseado
        printf("\nDigite la celda a cavar: ");
        scanf("%d %d",&i,&j);
        printf("\n");
        
        if (cont == 0)
            ibn=i,jbn=j;
            
        if(valorAbsoluto(ibn-i)<=1 && valorAbsoluto(jbn-j)<=1 && i<M && j<N){
            ibn=i;
            jbn=j;
            arr[z] = matriz[i][j];
            matriz[i][j] = 0;
            z++;
        } else{	
            printf("No se pudo cavar esa celda.\n"); 
        }
    
    imprimirArreglo(arr,z);

printf("\n");

    return 0;
}

//desglosamos todas las funciones declaradas
//creamos la matriz
int **crearMatriz(int M, int N){
    int **matriz = NULL;
    int i=0;

    matriz = (int **)malloc(M*sizeof(int *));

    for (i=0; i<M; i++)
        matriz[i] = (int *)malloc(N*sizeof(int));

    return(matriz);
}
//destruimos la matriz
void destruirMatriz(int **matriz, int M){
    int i=0;

    if (matriz == NULL)
        return;

    for (i=0; i<M; i++){
        if (matriz[i]!=NULL)
            free(matriz[i]);
    }

    free(matriz);
}
//iniciamos la matriz
void iniciaMatriz(int **matriz, int M, int N){
    int i=0, j=0;

    if (matriz==NULL)
        return;

    for (i=0; i<M; i++){
        for (j=0; j<N; j++)
            matriz[i][j]= i+j;
    }
}
//imprimimos la matriz
void imprimirMatriz(int **matriz, int M, int N){
    int i=0, j=0;

    if (matriz == NULL)
        return;

    for (i=0; i<M; i++){
        for (j=0; j<N; j++)
            printf(" %d ", matriz[i][j]);
        printf("\n");
    }
}
//imprimimos el arreglo
void imprimirArreglo(int *matriz, int M){
    int i=0;

    if (matriz == NULL)
        return;

    for (i=0; i<M; i++)
        printf("%d\t", matriz[i]);
}
//multiplicamos las matrices
void multiplicarMatrices(int **matC, int **matA, int **matB, int M, int N, int L){
    int i = 0, j = 0, k = 0;

    if (matC==NULL || matA==NULL || matB==NULL)
        return;

    for (i=0; i<M; i++){
        for (j=0; j<N; j++){
            matC[i][j] = 0;
            for (k=0; k<L; k++)
                matC[i][j] += matA[i][k] * matB[k][j];
        }
    }
}
//obtenemos el valor absoluto
double valorAbsoluto(double num){
    if (num < 0){
        return num * -1;
    }

    return num;
}

