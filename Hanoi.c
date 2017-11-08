/*
AUTOR: Dominguez Moran Joaquín, García Ibañez Diego, Rosas Sánchez Paloma. Noviembre 2017.
VERSIÓN: 1

DESCRIPCIÓN: Programa que lograr apilar los cincos aros en el mismo orden pero en la torre C

OBSERVACIONES: El programa utiliza una 5 funciones, una de ellas es recursiva, utiliza tambien una estructura

COMPILACIÓN: 
			Windows: gcc Hanoi.c -o Hanoi
			Linux: gcc Hanoi.c -o Hanoi

EJECUCIÓN: 
			Windows: Hanoi.exe
			Linux: ./Hanoi
*/  
  
//MACROS DEL PREPROCESADOR
#include <stdio.h>          
#include "presentacion.h"   
  
/*Estructura que contiene los discos, es similar a una pila*/ 
typedef struct torre 
{
  int Array[100];
   int ind;
 } torre;
 
/***void ColocarDiscos(int dis,torre*T)**
DESCRIPCIÓN: Función que recibe un disco y una torre para poner el disco hasta arriba de la torre
ENTRADA: Recibe un número entero dis y un apuntador a torre T
*/ 
  void
ColocarDiscos (int dis, torre * T) 
{
  T->Array[++T->ind] = dis;	//Coloca el disco en el tope de algun indice( torre(A, B, C))
}  

/**int QuitarDisco(torre*T)**
DESCRIPCIÓN: Función que recibe una torre y quita el disco que esta en el tope de esa torre
ENTRADA: Recibe un apuntador a torre T
SALIDA: Un entero o sea, el disco del tope que fue removido
*/ 
  int
QuitarDisco (torre * T) 
{
  return T->Array[T->ind--];	//Quita el tope de alguna de las torres
}

 
/**char*TipoTorre(int aux)**
DESCRIPCIÓN: Función que indica el tipo de torre
ENTRADA: Recibe un entero indice
SALIDA: Una cadena que indica el nombre de la torre 
OBSERVACIONES: el indice es de 0 a 2
*/ 
char *
TipoTorre (int ind) 
{
  switch (ind)			//Coloca los nombres de las torres 
    {
    case 0:
      return "A";		//Torre origen
    case 1:
      return "B";		//Torre auxiliar
    case 2:
      return "C";		//Torre destino
    default:
      return "";
    }
}

 
/**void Mostrar(torre * torres, int tiempo)**
DESCRIPCIÓN: Función que imprime en pantalla de manera grafica las torres de hanoi. El enesimo disco tiene un ancho en pantalla de 2n-1
ENTRADA: Recibe un arreglo de torres y el tiempo
OBSERVACIONES: El tiempo es en milisegundos
*/ 
  void
Mostrar (torre * torres, int tiempo) 
{
  int alto = 0;		//Se inicializa variable de tipo entero
  int nivel, i, j, n;		//Variables de tipo entero
  for (i = 0; i < 3; i++)	//Ciclo For que va desde 0 hasta 3, que es el numero de torres.
    {
      
	//Por medio de este ciclo se determina el alto, mediante la torre que tiene más discos.
	if (torres[i].ind > alto)
	
	{
	  alto = torres[i].ind;	// Alto va ser igual al numero de discos de la torre en la posicion i.
	}
    }
   for (nivel = alto; nivel >= 0; nivel--)	// Ciclo For que va desde el alto, es decir la torre que tiene más discos hasta 0.
    {
      for (i = 0; i < 3; i++)	// Ciclo For que va desde 0 hasta 3, que es el numero de torres.
	{
	  
	    // Se valida que la diferencia entre alto y nivel sea menos o igual a la torre con mayor numero de discos.
	    if (alto - nivel <= torres[i].ind)
	    
	    {
	      
		//n Es igual al numero de discos de la torre i en la posicion de la diferencia entre alto y nivel
		n = torres[i].Array[alto - nivel];
	        for (j = 11 - n + 25 * i; j <= 9 + n + 25 * i; j++)	// Ciclo For que dibuja las torres, segun las dimensiones de la pantalla.
		{
		  MoverCursor (j + 5, nivel + 5);
		  printf ("*");	//Imprime * para formar las torres
		}
	    }
	}
    }
  EsperarMiliSeg (tiempo);	//Llama funcion de la libreria presentacion
  MoverCursor (1, 1);		//Llama funcion de la libreria presentacion
}

 
/**void Mover(int dis, int A, int C, torre * torres, int * movi, char opc, int tiempo)**
DESCRIPCIÓN: Dado un numero de discos, los indices de las torres (el tipo(A,B,C)), arreglo de torres, 
     		 apuntador al numero de movimientos, un char opc('G' o 'T') y un entero tiempo
			 Esta funcion mueve el enesimo disco desde A hasta C, incrementando en 1 el numero de movimientos. 
			 Si en una de las condiciones del main, el usuario pone 'T', solo se mostrara los movimientos requeridos
			 para la solucion del problema. Si pone 'G', mostrara arriba el numero de movimiento junto con el
			 movimiento que se esta realizando y al mismo tiempo se anima en pantalla la representacion grafica del movimiento.
ENTRADA: Enteros: dis, A, C, tiempo, Apuntador de tipo entero a los movimientos
		 Char: Opc
		 Struct: torre*torres
OBSERVACIONES: El tiempo es en milisegundos.
*/ 
  void
Mover (int dis, int A, int C, torre * torres, int *movi, char opc,
       int tiempo) 
{
  (*movi)++;			//Se incrementa en 1 el numero de movimientos
  ColocarDiscos (QuitarDisco (&torres[A]), &torres[C]);	//Se llaman dos funciones
  if (opc == 'G')		//Condicion que representa la opcion que desea el usuario
    BorrarPantalla ();		//Se limpia pantalla
  printf ("Movimiento %d: Mover el disco %d desde %s hasta %s.\n", *movi, dis, TipoTorre (A), TipoTorre (C));	//Se imprime el numero de movimiento y la descripcion del mismo
  if (opc == 'G')		//Misma condicion anterior
    Mostrar (torres, tiempo);	//Llama la funcion Mostrar 
}

 
/**void Hanoi(int dis, int A, int B, int C, torre * torres, int * movi, char opc, int tiempo)**
DESCRIPCIÓN: Dado el numero de discos, los indices de las torres (el tipo(A, B, C)), un arreglo de torres, 
			 el apuntador al numero de movimintos, el char de la opcion al usuario y el tiempo.
			 Esta Función resuelve de manera recursiva el problema de las torres de hanoi.
			 Si en una de las condiciones del main, el usuario pone 'T', solo se mostrara los movimientos 
			 requeridos para la solucion del problema. Si pone 'G', mostrara arriba el numero de movimiento 
			 junto con el movimiento que se esta realizando y al mismo tiempo se anima en pantalla la representacion grafica del movimiento.
ENTRADA: Enteros: dis, A, B, C, tiempo, Apuntador de tipo entero a los movimientos
		 Char: Opc
		 Struct: torre*torres
OBSERVACIONES: Tiempo en milisegundos
*/ 
  void
Hanoi (int dis, int A, int B, int C, torre * torres, int *movi, char opc,
       int tiempo) 
{
  if (dis == 1)		//Caso base: si solo debemos mover un disco, lo movemos directamente de A hasta C
    {
      Mover (dis, A, C, torres, movi, opc, tiempo);	//Llama funcion Mover 
    }
  
  else				//Si no
    {
      Hanoi (dis - 1, A, C, B, torres, movi, opc, tiempo);	//Movemos los n-1 discos arriba del enesimo disco desde A hasta B pero pasando por C 
      Mover (dis, A, C, torres, movi, opc, tiempo);	//Movemos el enesimo disco directo desde A hasta C
      Hanoi (dis - 1, B, A, C, torres, movi, opc, tiempo);	//Ahora movemos los n-1 discos desde B Hasta C pero pasando por A
    }
}

 
//PROGRAMA PRINCIPAL
  int
main () 
{
  system ("color 4F");		//Cambia el color
  int dis, x;			//Variables de tipo entero 
  int movi = 0;			//Variable de tipo entero inicializada en 0
  int tiempo = 0;		//Variable de tipo entero inicializada en 0
  char opc;			//Variable de tipo char que representa la opcion
  torre torres[3];		//Inicializamos un arreglo de torres
  for (x = 0; x < 3; x++)	//Ciclo For que va desde 0 hasta 3, que es el numero de torres
    {
      torres[x].ind = -1;	//debe ser menos o igual a -1 porque es similar a una pila y se inicializa igual que una pila
    }
   printf ("Introduce el numero de discos: ");	//Pide el numero de discos
  scanf ("%d", &dis);		//Guarda eso en la variable entera dis
   
    //esto con el Ãºnico fin de lograr la animaciÃ³n
    for (x = dis; x >= 1; x--)	//Ciclo for y se agrega los n discos en la torre de origen,
    {
      ColocarDiscos (x, &torres[0]);	//Se llama funcion que pone discos
    }
   printf ("Introduce G para modo grafico o T para modo texto: ");	//Imprime en pantalla la opcion de ver los movimientos de forma grafica o solo en texto
  scanf (" %c", &opc);		//Guarda 'T' o 'G' en la variable entera opc
   if (opc == 'G')		//Condicion que tiene las instrucciones para animar las torres
    {
      printf ("Introduce el tiempo de transicion entre cada movimiento (en milisegundos): ");	//Pide el tiempo en milisgundos
      scanf (" %d", &tiempo);	//Lo guarda en la variable entera tiempo
      //      printf("Estado inicial:\n");
      Mostrar (torres, tiempo);	//Llama la funcion que imprime las torres con *
    }
   Hanoi (dis, 0, 1, 2, torres, &movi, opc, tiempo);	//Llama la función recursiva para resolver el problema
  return 0;			//FIN
}


