// jercicio 1 de TP PIPE

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h> 
#include <signal.h>

#define WRITE 1
#define READ 0

int main (){
    pid_t pid;
    int fd[2];
    int leido;
    char buff[80];

   
    pipe(fd);
    //printf ("fd[0] = %d fd[1] = %d \n ", fd[0], fd[1]);

    pid = fork();
    if (pid == 0 ){
        close(fd[WRITE]);  // cierro el lado de escritura del proceso hijo
        leido = read(fd[READ], buff, sizeof(buff));
        if(leido < 1)
        {
            printf("Hijo, tuberia vacía\n");
            exit(0);
        }
        else 
        {
            write (STDOUT_FILENO, "Hijo, leido de la tuberia \"", sizeof("Hijo, leido de la tuberia \""));
            write (STDOUT_FILENO, buff, leido);  // STDOUT_FILENO = 1 es una constante que representa la salida estándar (consola)
            printf("\" por el proceso hijo, pid %d \n", getpid());
        }
        close(fd[READ]);
        exit(0);

   }
   else {
       close(fd[READ]);  // Se cierra el lado de lectura del proceso padre
	   printf("Ingrese una cadena de caracteres por consola: \n");
	   leido = read(STDIN_FILENO, buff, sizeof(buff));  // STDIN_FILENO = 0 es una constante que representa la entrada estándar (teclado)
	   write(fd[WRITE], buff, leido-1);
	   close(fd[WRITE]);
	   wait(NULL);
	   write (STDOUT_FILENO, "Padre, escrito en la tuberia \"", sizeof("Padre, Escrito en la tuberia \""));
	   write (STDOUT_FILENO, buff, leido-1);
	   printf("\" por el proceso padre, pid %d \n", getpid());
	
	   exit(0);
    }

}
