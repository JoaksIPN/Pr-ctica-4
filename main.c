#include <stdio.h>
#include <stdlib.h>
#include"presentacion.h"

/*
AUTOR: Dominguez Moran Joaquín, García Ibañez Diego, Rosas Sánchez Paloma. Agosto 2017.
VERSIÓN: 1.0.

DESCRIPCIÓN: Programa que calcula el elemento n de Fibonnaci y Tribonacci.

OBSERVACIONES: Calcula el Fibonnaci del elemento 47.
COMPILACIÓN: 
			Windows: gcc main.c presentacionWin.c
			Linux: gcc main.c presentacionLin.c

EJECUCIÓN: 
			Windows: a.exe
			Linux: ./a.out
*/


typedef unsigned long long int u;

/*Se hace uso de dos arreglos, para consultar los elementos de
la sucesion de Fibonaaci y Tribonacci ya calculados, 
para optimizar el calculo */

u elementosFibonacci[1000];
u elementosTribonacci[1000];
/*
**u Fibonacci( int n);**
DESCRIPCIÓN: Calcula el elemento n de Fibonnacci Recursivamente.
ENTRADA: El elemento n que se desea calcular.
SALIDA: El valor en la sucesion de Fibonacci del elemento.
*/
u Fibonacci( int n)
	if(n==0)
	{
		elementosFibonacci[n]=0;
		return elementosFibonacci[n] ;
	}

	if(n==1)
	{
		elementosFibonacci[n]=1;
		return elementosFibonacci[n] ;
	}

	if (elementosFibonacci[n]!=0)
	{
		return elementosFibonacci[n];
	}

	else
	{
		elementosFibonacci[n] = Fibonacci(n-2) + Fibonacci(n-1);
		return elementosFibonacci[n];
	}
	
};

/*
**u Tribonacci( int n);**
DESCRIPCIÓN: Calcula el elemento n de Tribonnacci Recursivamente.
ENTRADA: El elemento n que se desea calcular.
SALIDA: El valor en la sucesion de Tribonacci del elemento.
*/

u Tribonacci(int n)
{
	if(n==0)//Condicional que evalua los casos base anteriores
	{
		elementosTribonacci[n]=1;
		return elementosTribonacci[n] ;
	}
	
	if(n==1)//Condicional que evalua los casos base anteriores
	{
		elementosTribonacci[n]=1;
		return elementosTribonacci[n] ;
	}
	
	if(n==2)//Condicional que evalua los casos base anteriores
	{
		elementosTribonacci[n]=2;
		return elementosTribonacci[n] ;
	}

	if (elementosTribonacci[n]!=0)
	{
		return elementosTribonacci[n];
	}

	else
	{
		elementosTribonacci[n] = Tribonacci(n-1)+Tribonacci(n-2)+Tribonacci(n-3);;
		return elementosTribonacci[n];
	}
	
};

void wait()
{
	
	while(getchar() != '\n');
}

void menu()
{
	char aux[2];
	int n=0;
	int opcion=0;
	
	do 
	{
	printf("Menu:\n");
	printf("1.Fibonacci\n" );
	printf("2.Tribonacci\n" );
        printf("3.Salir\n" );
	printf("Seleccione Opcion\t" );

	fgets (aux, 2, stdin);
	sscanf (aux, "%d", &opcion);

	switch(opcion) 
	{
        case 1: 
		BorrarPantalla();
        	printf("Bienvenido a Fibonacci:\n");
        	printf("Ingrese n a calcular :\t");
        	scanf("%d",&n);
        	printf ("El termino %d es: %u \n", n, Fibonacci(n));
            break; 
        case 2:
		BorrarPantalla();
        	printf("Bienvenido a Tribonacci:\n");
        	printf("Ingrese n a calcular :\t");
        	scanf("%d",&n);
        	printf ("El termino %d es: %u \n", n, Tribonacci(n));
            break; 
	case 3:	
		 printf("Bye :D\n");
        default: printf("Error"); 

	}

	wait();

	}while(opcion!=3);
	
		
}

// Raiz del programa
int main(void)
{
	
	int i=2;
	int j=3;
	

	
	while(i<1000)
	{
		elementosFibonacci[i]=0;
		i++;
	}

	while(j<1000)
	{
		elementosTribonacci[i]=0;
		j++;
	}

	menu();

	
}
	
	
