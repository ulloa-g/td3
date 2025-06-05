#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void mi_manejador(){
	write(STDOUT_FILENO, "Me rehuso a terminar\n", sizeof("Me rehuso a terminar\n"));
}

int main(){
	signal(SIGUSR1, mi_manejador);  // SIGKILL no puede ser ignorada o manejada
	printf("Soy el proceso con ID: %d\n", getpid());
	while(1);
	
	return 0;
}

/*
Explicación de:
ssize_t write(int fd, const void *buf, size_t count);
write(STDOUT_FILENO, "Me rehuso a terminar\n", sizeof("Me rehuso a terminar\n"));

write() es una llamada al sistema que escribe datos en un descriptor de archivo.
STDOUT_FILENO: constante que representa el descriptor de archivo (fd) estándar de salida (stdout) = 1
sizeof(): Calcula el tamaño en bytes a escribir
*/
