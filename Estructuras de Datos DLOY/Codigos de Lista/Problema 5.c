#include <stdio.h>
#include <stdlib.h>

int ******CrearHiper(int L, int M, int N, int O, int P, int Q); 
void ImprimirHiper(int ******Hiper, int L, int M, int N, int O, int P, int Q);
void DestruirHiper(int ******Hiper, int L, int M, int N, int O, int P, int Q);

int main(int argc, char *argv[]){
	int ******Hipercubo= NULL; 
	int L=2, M=3, N=4, O=5, P=6, Q=7; 
	
	Hipercubo= CrearHiper(L, M, N, O, P, Q); 
	ImprimirHiper(Hipercubo, L, M, N, O, P, Q); 
	DestruirHiper(Hipercubo, L, M, N, O, P, Q);
		
	return 0;
}

//Crea un hipercubo
int ******CrearHiper(int L, int M, int N, int O, int P, int Q)
{
	int ******Hiper= NULL; 
	int i=0, j=0, k=0, x=0, y=0, z=0; 
	
	Hiper=(int ******) malloc(L*sizeof(int *****)); //reserva espacio de memoria de forma dinamina 
	for (i=0; i<L; i++)
	    {

		Hiper[i]= (int *****) malloc(M*sizeof(int ****));//reserva espacio de memoria de forma dinamina 
		
		for (j=0; j<M; j++)
		    {
			Hiper[i][j]= (int ****) malloc(N*sizeof(int ***)); //reserva espacio de memoria de forma dinamina 
			
			for (k=0; k<N; k++)
			    {
				Hiper[i][j][k]= (int ***) malloc (O* sizeof(int **)); //reserva espacio de memoria de forma dinamina 
				
				for (x=0; x<O; x++)
				    {
					Hiper[i][j][k][x]= (int **) malloc(P* sizeof(int *)); //reserva espacio de memoria de forma dinamina 
					
					for (y=0; y<P; y++)
					    {
						Hiper[i][j][k][x][y]= (int *) malloc(Q* sizeof (int)); //reserva espacio de memoria de forma dinamina 
						
						for (z=0; z<Q; z++)
						    {
							Hiper[i][j][k][x][y][z]=i*j*k*z*y*z; //realiza una multiplicacion entre valores de ciclos y se almacenan
					    }
			        }
			    }
		    }
	    }	
    }
	return(Hiper); 
}

//función para imprimir hipercubo
void ImprimirHiper(int ******Hipercubo, int L, int M, int N, int O, int P, int Q){
    int i=0, j=0, k=0, x=0, y=0, z=0; 
    
    for(i=0; i<L; i++)
	   {
        printf("\nHipercubo  de 6 [%d]:\n", i); 
        for(j=0; j<M; j++)
		   {
            printf("\n\tHipercubo de 5 [%d]:\n", j); 
            for(k=0; k<N; k++)
			   {
                printf("\n\t\tHipercubo de 4 [%d]:\n", k); 
                for(x=0; x<O; x++)
				   {
                    printf("\n\t\t\tVolumen [%d]:\n", x); 
                    for(y=0; y<P; y++)
					   {
                        printf("\n\t\t\t\t Matriz [%d]:", y); 
                        for(z=0; z<Q; z++)
						   {
                            printf("%d\t", Hipercubo[i][j][k][x][y][z]); 
                        }
                    }  
                } 
            }
        }
    }
}

//Libera la memoria para cada dimensión 
void DestruirHiper(int ******Hiper, int L, int M, int N, int O, int P, int Q)
{
	int i=0, j=0, k=0, x=0, y=0, z=0; 
	
	for (i=0; i<L; i++){		
		for(j=0; j<M; j++){
			for (k=0; k<N; k++){
				for (x=0; x<O;x++){
					for (y=0; y<P; y++){
						for (z=0; z<Q; z++){
							free(Hiper[i][j][k][x][y]);//hipercubo de 6
							
						}
						free(Hiper[i][j][k][x]);//hipercubo de 5
					}
					free(Hiper[i][j][k]);//hipercubo de 4
				}
				free(Hiper[i][j]);//volumen
			}
			free(Hiper[i]);//Matriz
		}
		free(Hiper);//vector
	}
}

