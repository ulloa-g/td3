// Ejercicio 5 de TP Procesos

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid
#include <sys/wait.h>    // Define wait

int main (){

    printf ("Unico proceso antes del fork(), con pid %d \n ",getpid());
	pid_t pid = fork();  // pid_t tipo de dato entero con signo, creamos un nuevo proceso

	if (pid == -1) {
        // código para manejar el error de fork
        perror("Error al crear el proceso hijo");
        return 1;

	}
    else if (pid == 0) {
        // --- CÓDIGO DEL HIJO ---
        printf("Soy el hijo: %d, mi papa es: %d, fork() devolvio %d\n", getpid(),getppid(),pid);
        exit(0);  // garantiza que el proceso hijo termina inmediatamente en esa línea
    }
    else {
        // --- CÓDIGO DEL PADRE ---
		printf("Soy el padre: %d, mi papa es: %d, fork() devolvio %d\n", getpid(),getppid(),pid);
        wait(NULL);  // Espera a que el hijo termine
        printf("Padre: El hijo ha terminado. Mi tarea podria continuar desde aqui.\n");
        return 0;  // finaliza la función mail del padre
    }

}
