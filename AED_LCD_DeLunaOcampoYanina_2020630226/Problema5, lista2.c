/*
Construcción  de  base  acuática. Día  5, 23:00  hrs.Los  materiales  recolectados  
tienen indicaciones de ensamblado para conformar módulos, señalando las piezas con 
las que son compatibles  los  componentes, conformando  un símil  con  un rompecabezas.  
Además, cada componente  tiene  un  nivel  de  prioridad  y  un  costo  por  su  uso.  
Arme  el  rompecabezas utilizando técnicas iterativas, recursivas y/o de backtracking, 
genere los planos, identificando cuántos  módulos  están  contenidos  en  su  avión  
(número  no  especificado).  Optimice  el ensamblado  de  tal  forma  que  maximice  
la  utilidad  total  y  minimice  el  costo.Realice  las maniobras  y  acrobacias  de  
vuelo  necesarias,  utilizando  las  herramientas  y  técnicas  de construcción  
incorporadas  en  los  problemas  anteriores,  para  ensamblar  los  módulos  e  
ir construyendo la  base  acuática.  Nota:  todas  las  operaciones deben  estar  
únicamente  en términos de las estructuras/módulos definidos en los puntos 0 al 4.
*/

#include <stdio.h>
#include <stdlib.h>

//DE LUNA OCAMPO YANINA

void posibleTamanio(int n);

int main (){
	//cantidad para dar
	int tamanio; 
	
	printf("Digite el peso de materiales a utilizar (kg) para la base acuatica: ");
	scanf("%d",&tamanio);
    //funcion que determina el tamanio a ingresar
	posibleTamanio(tamanio); 
	
	return 0;
}

void posibleTamanio(int tamanio){
	//posibles pesos en las piezas
    // peso de 100 kg
	int t100 = 0; 
    // peso de 50 kg
	int t50 = 0; 
    // peso 20 kg
	int t20 = 0; 
    // peso 10 kg
	int t10 = 0; 
    // peso 5 kg
	int t5 = 0; 
    // peso 2 kg
	int t2 = 0;
    // peso 1 kg 
	int t1 = 0; 
	int n = 0; //variable f
	
	while(tamanio != n){
		if(tamanio >= 100){
            t100++;
            tamanio-=100;
        } else if(tamanio >= 50){
            t50++;
            tamanio-=50;
        } else if(tamanio >= 20){
            t20++;
            tamanio-=20;
        } else if(tamanio >= 10){
            t10++;
            tamanio-=10;
        } else if(tamanio >= 5){
            t5++;
            tamanio-=5;
        } else if(tamanio >= 2){
            t2++;
            tamanio-=2;
        } else if(tamanio >= 1){
            t1++;
            tamanio-=1;
        }
	} //fin de While

	printf("El peso total a ingresar es: \n");
	printf(" %d kg(s) de 100 \n",t100);
	printf(" %d kg(s) de 50 \n",t50);
	printf(" %d kg(s) de 20 \n",t20);
	printf(" %d kg(s) de 10 \n",t10);
	printf(" %d kg(s) de 5 \n",t5);
	printf(" %d kg(s) de 2 \n",t2);
	printf(" %d kg(s) de 1 \n",t1);
	
}

