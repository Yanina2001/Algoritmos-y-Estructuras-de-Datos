#include <stdio.h>
#define TAM 5

int laberinto[TAM][TAM] = {
    //LABERINTO CON SOLUCION
    {0,1,0,1,1},
    {0,0,0,0,0},
    {1,0,1,0,1},
    {0,0,1,0,0},
    {1,0,0,1,0}

    //LABERINTO SIN SOLUCION
    /*{0,0,0,1,1},
    {0,0,0,1,0},
    {0,1,0,1,0},
    {1,1,0,1,1},
    {0,1,1,0,1}*/
};

int solucion[TAM][TAM];

void impSolucion(){
    int i,j;
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            printf("%d",solucion[i][j]);
        }
        printf("\n");
    }
}

//backtraking
int resuelve(int a, int b){
    if((a==TAM-1) && (b==TAM-1)){
        solucion[a][b] = 1;
        return 1;
    }
    if(a>=0&&b>=0&&a<TAM&&b<TAM&&solucion[a][b]==0&&laberinto[a][b]==0){
        solucion[a][b] = 1;
        if(resuelve(a+1,b))
            return 1;
        if(resuelve(a,b+1))
            return 1;
        if(resuelve(a-1,b))
            return 1;
        if(resuelve(a,b-1))
            return 1;
        solucion[a][b] = 0;
        return 0;
    }
    return 0;
}

int main(){
    int i,j;
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++)
            solucion[i][j] = 0;
    }
    if (resuelve(0,0))
        impSolucion();
    else
        printf("No hay solucion para este laberinto");
    return 0;
}
