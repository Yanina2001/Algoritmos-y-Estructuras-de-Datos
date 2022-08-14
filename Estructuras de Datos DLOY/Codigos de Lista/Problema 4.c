#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5

int ** createMatrix(int n);
int * createArray(int m);
void destroy(int** p, int n);

int main(){
    int** dinosaurio = createMatrix(N);
    srand(time(0));
    for(int i=0; i<N; i++){
        if(i%2!=0){
            dinosaurio[i] = createArray(i);
            for(int j=0; j<i; j++)
                dinosaurio[i][j] = rand()%((i+1)*10);
        }
    }

    for(int i=0; i<N; i++){
        if(i%2==0)
            dinosaurio[i]=&dinosaurio[(i+1)%N][i];
    }

    for(int i=0; i<N; i++){
        if(i%2!=0){
            printf("dinosaurio[%d] : {",i);
            for(int j=0; j<i; j++)
                printf("%d",dinosaurio[i][j]);
        printf("}\n");
        } else {
            printf("*dinosaurio[%d]: %d\tdireccion: %x\n",i, *dinosaurio[i],dinosaurio[i]);
        }
    }
    destroy(dinosaurio,N);
    return 0;
}

int** createMatrix(int n){
    return (int**)malloc(n*sizeof(int*));
}

int* createArray(int m){
    return (int*)malloc(m*sizeof(int));
}

void destroy(int** p, int n){
    for(int i=0; i<N; i++)
        free(p[i]);
    free(p);
}