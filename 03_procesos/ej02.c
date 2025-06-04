// Ejercicio 2 de TP Procesos

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid

pid_t pid;  // pid_t tipo de dato entero con signo
int i;

int main (){

	printf ("Proceso unico: Mi pid es %d\n", getpid());
	
	pid = fork();  // devuelve el pid del hijo al padre y 0 al hijo

    // El siguiente bloque se ejecuta dos veces: una en el padre y otra en el hijo
    // EL kernel crea una copia casi identica del proceso padre, incluyendo el código.
    // tanto el proceso padre como el hijo continuan ejecutando el código a partir de la llamada a fork().
    // por eso se imprmen valores diferentes de pid en cada uno de los procesos.
	printf ("Mi pid es %d y el pid de papa es %d. fork() devolvio %d\n", getpid(), getppid(), pid);
		
	// Ejecute pstree en otra consola para ver la jerarquía de procesos
    // pstree -s -p PID muestra el árbol de procesos con el PID especificado
	sleep(30); 
	
	return 0;

}