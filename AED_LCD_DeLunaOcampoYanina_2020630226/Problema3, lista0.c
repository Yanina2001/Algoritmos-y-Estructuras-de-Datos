/*
Excursión enlos aires. Día 3, 10:00 hrs. Conduzca su avión a la pista de despegue, 
alceel vuelo  y cruce  los  aires  para  localizar  y  clasificar  nubes cirros,  
cirrocúmulos,  cirrostratos, altoestratos, altocúmulos, estratos, estratocúmulos, 
nimbostratos, cúmulos y cumulonimbos.Asigne un número a cada categoría y realice 
una búsqueda binaria dentro de un arreglo de N nubes, indicando la dirección en 
memoria en hexadecimal de la celda conforme va avanzando en la búsqueda. Tenga 
cuidado de lluvias, tormentas, perdigones de hielo y del granizo. 
*/

#include <stdio.h>
#include <math.h>

//DE LUNA OCAMPO YANINA

//funcion
int busquedaBire(int arreglo[], int busqueda, int izq, int der);

int main(){

    //declaramos varibales
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int buscar;
    //imprimimos la lista de asignacion a los nombres dados
    printf("Clasificacion de nubes: \n 1. Cirros\n 2. Cirrocumulos\n 3. Cirrostratos\n 4. Altoestratos\n 5. Altocumulos\n 6. Estratos\n 7. Estratocumulos\n 8. Nimboestratos\n 9. Cumulos\n 10. Cumulonimbos\n");
	printf("\n");
    //pedimos y almacenamos el valor del numero digitado
    printf("Digite el numero del tipo de nube que desea: ");
	scanf("%d",&buscar);
    int longArr = sizeof(numeros) / sizeof(numeros[0]);
    int resulBure = busquedaBire(numeros, buscar, 0, longArr - 1);
    //se imprime la direccion de memoria en hexadecimal
    printf("Numero %d encontrado en la posicion: %p\n", buscar, resulBure);
}

//funcion desglosada 
int busquedaBire(int arreglo[], int buscar, int izq, int der){
    if (izq > der) return -1;
    int mitad = floor((izq + der) / 2);
    int valorMedio = arreglo[mitad];
    if (buscar == valorMedio)
        return mitad;
    if (buscar < valorMedio){
        der = mitad - 1;
    }else{
        izq = mitad + 1;
    }
    return busquedaBire(arreglo, buscar, izq, der);
}

