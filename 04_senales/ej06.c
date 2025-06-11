#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (){
	pid_t chld1, chld2, chld3;
	//printf("Soy proceso padre con PID: %d\n", getpid());
	chld1 = fork();
	if (chld1 == 0){
		printf("Soy chld1: %d\n", getpid());
		while(1);
		exit(0);
	}

	chld2 = fork();
	if (chld2 == 0){
		printf("Soy chld2: %d\n", getpid());
		while(1);
		exit(0);
	}

	chld3 = fork();
	if (chld3 == 0){
		printf("Soy chld3: %d\n", getpid());
		while(1);
		exit(0);
	}
	printf("Soy proceso padre con PID: %d\n", getpid());
	printf("P -> Esperando 10 segundos...\n");
	sleep(10);
	printf("P -> matando chld1 PID: %d\n", chld1);
	kill(chld1, SIGKILL);
	printf("P -> matando chld2 PID: %d\n", chld2);
	kill(chld2, SIGKILL);
	printf("P -> matando chld3 PID: %d\n", chld3);
	kill(chld3, SIGKILL);
	printf("P -> Esperando a que los hijos terminen...\n");
	// Espera a que los hijos terminen
	waitpid(chld1, NULL, 0);
	waitpid(chld2, NULL, 0);
	waitpid(chld3, NULL, 0);
	exit(0);
}
