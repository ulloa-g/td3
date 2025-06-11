#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

pid_t chld;

void manejador(int sig) {
	if (sig == SIGCHLD) {
		int status = wait(&status);
		printf("Se ha recibido la señal SIGCHLD en el proceso padre PID: %d\n", getpid());
		printf("El hijo terminó con estado: %d\n", status);
		pid_t pid = wait(NULL);
		printf("La señal wait() devuelve: %d\n", pid);
		wait(NULL); // Espera a que el hijo termine
	}
	return 0;
}

int main() {
	chld = fork();
	if(chld < 0){
		perror("Falla al crear proceso hijo\n");
		exit(0);
	}
	else if(chld == 0){
		printf("Proceso hijo PID: %d\n", getpid());
		sleep(2);
		exit(0);
	}
	else{
		printf("Proceso padre PID: %d\n", getpid());
		sleep(15);
	}
	return 0;
}
