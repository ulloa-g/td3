// Ejercicio 1 de TP Procesos

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid

int main (){
	
	printf ("Proceso unico: Mi pid es %d y el pid de papa es %d\n", getpid(),getppid());

	return 0;  // la forma más recomendada para terminar main() es return 0;   
}

/* 
Respuestas al ejercicio:

Process ID (Identificador de Proceso). Es un número entero único que el kernel 
del sistema operativo asigna a cada proceso que se está ejecutando.
El PID del hijo es siempre diferente y menor al PID del padre, ya que el padre 
es el proceso que crea al hijo.
*/