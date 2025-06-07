#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main (){
	pid_t chd1, chd2, chd3;
	printf("Soy proceso padre con PID: %d\n", getpid());
	chd1 = fork();
	chd2 = fork();
	chd3 = fork();
	if (chd1 == 0){
		printf("Soy chd1: %d\n", getpid());
		while(1);
	}
	else {
		sleep(10);
		printf("Soy P: Matando chd1 PID: %d\n", chd1);
	}
	return 0;
}
