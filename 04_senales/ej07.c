#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

pid_t chld;

void manejador(int sig_num) {
	if (sig_num == SIGCHLD) {
		int status;
		pid_t pid = wait(&status);
		printf("Se ha recibido la señal SIGCHLD en el proceso padre PID: %d\n", getpid());
		printf("wait() devolvió PID: %d\n", pid);
		printf("El hijo terminó con estado de salida: %d\n", status);
	}
}

int main() {
	signal(SIGCHLD, manejador); // Registrar el manejador para SIGCHLD
	chld = fork();
	if(chld < 0){
		perror("Falla al crear proceso hijo\n");
		exit(0);
	}
	else if(chld == 0){
		printf("Proceso hijo PID: %d\n", getpid());
		sleep(2);
		exit(0);  // cuando el hijo termina, el sistema operativo envía automaticamente SIGCHLD al padre
	}
	else{
		printf("Proceso padre PID: %d\n", getpid());
		sleep(60);
		printf("P -> Hijo ha sido recolectado. Finalizando el padre.\n");
	}
	return 0;
}
