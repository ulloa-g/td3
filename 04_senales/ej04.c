#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void mi_manejador(){
	write(STDOUT_FILENO, "Me rehuso a terminar\n", sizeof("Me rehuso a terminar\n"));
}

int main(){
	signal(SIGKILL, mi_manejador);  // SIGKILL no puede ser ignorada o manejada
	printf("Soy el proceso con ID: %d\n", getpid());
	while(1);
	
	return 0;
}
