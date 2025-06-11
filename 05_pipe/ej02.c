// Ejercicio 2 de TP PIPE

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include<sys/wait.h> 

#define MSG "INFORMACION IMPORTANTE"
#define BUFF_SIZE 80

int main (){
    int fd[2];
    int leido;
    char buff[BUFF_SIZE] = {0};

    if (pipe(fd) == -1) {  // comprobar si se pudo crear la tubería
        exit(-1);
    }

    switch (fork()){
        case 0:  // Proceso hijo
            printf("Hijo escribiendo en tuberia, pid %d... \n", getpid());
            // Linea agregada - se cambia df[1] por fd[0]
            close(fd[0]);  // fd[1] Cierra el extremo de escritura de la tubería en el hijo
            strncpy(buff, MSG, sizeof(MSG)); 
            write(fd[1], buff, sizeof(MSG)); // df[1] es el extremo de escritura de la tubería (está cerrado en el hijo)
            close(fd[1]);  // Linea agregada - Cierra el extremo de escritura después de escribir
            exit(0);
            
        default:  // Proceso padre
            printf("Padre leyendo tuberia, pid %d... \n", getpid());
            // Aquí se debería cerrar el extremo de escritura de la tubería en el padre
            close(fd[1]);  // Linea agregada - 
            leido = read(fd[0], buff, sizeof(buff));	
            if(leido < 1){
                write (STDOUT_FILENO, "Error al leer tuberia\n", sizeof("Error al leer tuberia\n"));
            }else {
                write (STDOUT_FILENO, "Leido de la tuberia \"", sizeof("Leido de la tuberia \""));
                write (STDOUT_FILENO, buff, leido-1);
                printf("\" por el proceso padre.\n");
            }
            close(fd[0]);  // Linea agregada - Cierra el extremo de lectura después de leer
            wait(NULL);

            exit(0);
    }
}
