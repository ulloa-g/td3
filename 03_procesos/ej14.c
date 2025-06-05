/*
 * Ejercicio 13 de TP Procesos
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid

int main(void) {
	
	int err;
	
	err = execl("/bin/ls", "ls", "-l", (char *)NULL);  // imprime el contenido del directorio actual
	//err = execl("/otro_directorio/ls", "ls", "-l", (char *)NULL);
	
	if (err == -1)
		printf("Este printf se ejecuta en caso de error. Por que?\n");
			
	exit(0);

}

/*
La función execl() es una llamada al sistema que reemplaza el proceso actual con un nuevo programa.
int execl(const char *path, const char *arg0, ..., (char *)NULL);
Si hay un error execl() devuelve -1

Otro ejemplo que podría ser útil:
msg = execl("/bin/echo", "echo", "Hola, mundo!", (char *)NULL);
*/
