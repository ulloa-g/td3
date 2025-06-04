// Ejercicio 3 de TP Procesos

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid

pid_t pid1,pid2;  // pid_t tipo de dato entero con signo

int main (){

	printf ("0-Proceso unico: Mi pid es %d y voy a ejecutar 2 fork()\n", getpid());
	
	pid1=fork();
	printf ("1-Mi pid es %d y el pid de papa es %d. fork() devolvio %d\n", getpid(), getppid(), pid1);

	pid2=fork();
	printf ("2-Mi pid es %d y el pid de papa es %d. fork() devolvio %d\n", getpid(), getppid(), pid2);

	sleep(30); // Probar con el comando pstree -p o pstree -s -p PID para ser mas específico
	
	return 0;

}

/*
Respuestas al ejercicio:

Cuantos procesos ejecutan la linea 22?
Cada llamada a fork() crea un nuevo proceso, y cada uno de esos procesos ejecuta la línea 22.
La línea 22 se ejecuta en 4 procesos diferentes.
Con N llamadas a fork(), el número total de procesos creados es 2^N.
En este caso, con 2 llamadas a fork(), se crean 4 procesos en total (2^2 = 4).
*/
