#include <stdio.h>
#include <stdlib.h>

void QuickSort(int Arr[], unsigned int TamArr);
int main(){
    int k;
    int Arr[] = {8,4,1,6,0,3,25,7,9};
    unsigned int TamArr= sizeof Arr / sizeof Arr[0]; //tamano del arreglo

    printf("Arreglo \n");
    for (k= 0; k < TamArr; k++){ //imprime arreglo sin ordenar
  	    printf("%d ", Arr[k]);
    }

    printf("\n");
  
    QuickSort(Arr,TamArr); //ordena el arreglo mediante el metodo de QuickSort

    printf("Arreglo ordenado por QuickSort\n");
  	for (k = 0; k < TamArr; k++){ //imprime arreglo ordenado
  		printf("%d ", Arr[k]);
	  }

    return 0;
}


void QuickSort(int Arr[], unsigned int TamArr){
	if(TamArr >= 2){
        int pivote = Arr[TamArr/2]; //crea pivote
        int i, j, Auxiliar;
        for(i=0, j=TamArr-1; ; i++, j--){ //ciclo que ordenara 
            while(Arr[i] < pivote){
            	i++; //incrementa ya que recorrera 1 al lado izquierdo
			} 
            while(Arr[j] > pivote){
            	j--; //incrementa ya que recorrera 1 al lado derecho
			} 
            if(i >= j){ //Del lado izquierdo deben quedar todos los numeros menores 
            break;	
			} //permuta los numeros
            Auxiliar = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = Auxiliar;
        }
        QuickSort(Arr, i);
        QuickSort(Arr+i, TamArr-i);
    }
}
 
