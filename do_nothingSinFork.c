#include <stdio.h>  //incluimos la libreria de estandar input/output
#include <unistd.h> //para hacer sleep
#include <stdlib.h> //para libreria de numeros random: srand, rand 
#include <time.h>   //para inicializar el tiempo
#include <sys/types.h>
#include <sys/wait.h>

void do_nothing(int microseconds, char* mensaje){
  usleep(microseconds); //dormir el thread, simula que esta haciendo alguna tarea
  printf("\n %s \n",mensaje); 
}

void do_nothing_random(char* mensaje){
  srand(time(NULL));                    //inicializar la semilla del generador random:
  int microseconds = rand() % 1000 + 1; //generar un numer random entre 1 y 1000:
  usleep(microseconds);                 //dormir el thread, simula que esta haciendo alguna tarea
  printf("\n %s \n",mensaje); 
}


int main() {
	char* msg1= ""; 
  char* msg2= "";
	printf("\n pid del proceso=  %d \n",getpid());	

	printf("\n %s","Llamada a do_nothing");
	do_nothing(2000000, msg1);

	printf("\n %s","Llamada a do_nothing");
	do_nothing(2000000, msg1);

	printf("\n %s","Llamada a do_nothing");
	do_nothing(2000000, msg1);

	printf("\n %s","Llamada a do_nothing");
	do_nothing(2000000,msg2); //esperar 2 segundos, 1 millon de microsegundos en 1 segundo

	printf("\n %s","Llamada a do_nothing");
	do_nothing(2000000,msg2);

	printf("\n %s \n","Llamada a do_nothing");
	do_nothing(2000000,msg2); 
	return 0;

}

//para compilar: gcc do_nothing.c -o ejecutable
//para ejecutar: ./ejecutable

 
