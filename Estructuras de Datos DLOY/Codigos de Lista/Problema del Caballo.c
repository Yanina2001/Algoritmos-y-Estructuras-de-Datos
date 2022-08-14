#include <stdio.h>
#include <stdlib.h>
#define TAM 8 //tamaño para el tablero

void CargarTablero(int arry[][TAM]);
void ImprimirTablero(int arry[][TAM]);
void Recursividad(int Tablero[][TAM],int numero,int x, int y);
int final(int arry[][TAM]);
int iteraciones=0;
int main (){
    int Tablero[TAM][TAM];//tablero
    int columna = 0;//posicion inicial en X
    int fila = 0;//posicion inicial en Y
    
    CargarTablero(Tablero);//rellena el tablero con ceros
    Tablero[columna][fila]=1;//dando ubicacion inicial del caballo
    
    printf("Bienvenido a recorrido del caballo en un tablero de 8x8 \n");
    printf("La posicion inicial sera en la columna -> %d  fila -> %d \n",columna,fila);
    
    Recursividad(Tablero,2,columna,fila);//busqueda de solucion
    
    printf("SOLUCION \n   Numero de interaciones: %d\n\n",iteraciones);
    ImprimirTablero(Tablero);//funcion que imprime el tablero solucionado
    return 0;
}

void CargarTablero(int arry[][TAM]){ //esta funcion cargara el tablero de 0 en cada casilla
    int j,i;
    for(j=0; j<TAM; j++){
        for(i=0; i<TAM; i++){
	        arry[j][i] = 0; //la casilla se le dara un 0
		}
    }
}

int final(int arry[][TAM]){ //verifica que el tablero final este completado
    int i,j;

     for (i=0; i<TAM; i++)
     {
         for (j=0; j<TAM; j++)
         {
             if (arry[j][i] == 0)
             {
                 return 0;//no esta completado el tablero
             }

         }
     }
     return 1; //se completo el tablero
}

void Recursividad(int Tablero[][TAM],int numero,int x, int y){ //funcion para hallar la solucion del recorrido
    int Movx[]={  1, 2, 2, 1,-1,-2,-2,-1 }; //movimiento de caballo en X
    int Movy[]={ -2,-1, 1, 2, 2, 1,-1,-2 }; //movimiento de caballo en Y
    int NuevoX = 0; //nueva posicion en X
    int NuevoY = 0; //nueva posicion en Y
    int indice = 0;

    while(indice < 8 && final(Tablero) != 1){

        NuevoX = Movx[indice] + x;
        NuevoY = Movy[indice] + y;

          if ((Tablero[NuevoX][NuevoY] == 0) && (NuevoX < TAM && NuevoX >= 0 && NuevoY < TAM && NuevoY >= 0)){
              Tablero[NuevoX][NuevoY]=numero; //si se cumplen todas las condiciones, se almacenara el numero en la casilla 

              if (numero != TAM*TAM){ //verifica si el numero actual no supera el maximo de casillas
                Recursividad(Tablero,numero+1,NuevoX,NuevoY); //se vuelve a posicionar al caballo de forma recursiva 
              }
            } 
        indice+=1; //
        iteraciones+=1; //se cuentan el numero de intelaciones
    }
    if (final(Tablero) != 1){ //verifica que el tablero este completado
    Tablero[x][y]=0;
    }
}

void ImprimirTablero(int arry[][TAM]){ //funcion para imprimir tablero 
     int j,i;
     for (i=0; i<TAM; i++)
     {
        for(j=0; j<TAM; j++){
		   printf(" %2d |",arry[j][i]); //se imprime la casilla del tablero
		}
        printf("\n\n");
     }
}
