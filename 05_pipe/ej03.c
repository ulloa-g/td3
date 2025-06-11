// Ejercicio 3 de TP PIPE

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h> 

#define FRASE_A "INFORMACION A"
#define FRASE_B "INFORMACION IMPORTANTE B"
#define BUFF_SIZE 80

int main (){

   int fd[2];
   char buff[BUFF_SIZE] = {0};
   int tamaño_frase;
   pipe(fd);

   switch (fork()){ 
      
      case 0:
	   close(fd[0]);
       tamaño_frase = strlen(FRASE_A) + 1; // +1 para incluir el carácter nulo "\0" al final de la cadena
	   write(fd[1], &tamaño_frase, sizeof(int));  // Escribe el tamaño de FRASE_A en la tubería
       write(fd[1], FRASE_A, tamaño_frase);  // Escribe FRASE_A en la tubería
	   close(fd[1]);
	   exit(0);
      break;
      
      default:
      switch (fork()){ 
            
         case 0:
            close(fd[0]);    
            tamaño_frase = strlen(FRASE_B) + 1;           
            write(fd[1], &tamaño_frase, sizeof(int));  // Escribe el tamaño de FRASE_A en la tubería
            write(fd[1], FRASE_B, tamaño_frase);  // Escribe FRASE_A en la tubería
            close(fd[1]);
            exit(0);      
         break;
         
         default:
         close(fd[1]);
         int i;
         int largo_mensaje_actual;
         ssize_t bytes_leidos;
         ssize_t bytes_leidos_mensaje;
         sleep(1);
         
         for(i=0; i<2; i++){
               bytes_leidos = read(fd[0], &largo_mensaje_actual, sizeof(int)); // lee la longitud del siguiente mensaje antes de leer el mensaje en sí.
               bytes_leidos_mensaje = read(fd[0], buff, largo_mensaje_actual);  // esta línea se encarga de leer los bytes del mensaje en sí.
               buff[bytes_leidos_mensaje - 1] = '\0'; // Aseguramos que el buffer sea una cadena válida
               if(largo_mensaje_actual < 1){
                  write (STDOUT_FILENO, "Padre, Error al leer tuberia\n", sizeof("Padre, Error al leer tuberia\n"));
               }else {
                   printf("Padre (PID: %d): Leído mensaje #%d de longitud %d: \"%s\"\n", getpid(), i + 1, largo_mensaje_actual, buff);
                }

            }

            close(fd[0]);
            wait(NULL);
            wait(NULL);
            exit(0);
         break;
      }
   }   
}

/*
Algunas aclaraciones:

bytes_leidos = read(fd[0], &largo_mensaje_actual, sizeof(int));
    &largo_mensaje_actual es un puntero a la variable donde se va a guardar el tamaño del mensaje que se va a leer.
    byes_leidos es el número de bytes leídos, que debería ser igual a sizeof(int)
    sizeof(int) es el tamaño del tipo de dato int, que es 4 bytes
bytes_leidos_mensaje = read(fd[0], buff, largo_mensaje_actual);
    buff es el buffer donde se va a guardar el mensaje/información.
    largo_mensaje_actual es el tamaño del mensaje.
    bytes_leidos_mensaje es el número de bytes leídos, que debería ser igual a largo_mensaje_actual

Nota:

printf("bytes_leidos: %zd", bytes_leidos);  --------> 4
printf("sizeof(): %zd", sizeof(bytes_leidos)); -----> 8
Esto es porque bytes_leidos es de tipo ssize_t, que en sistemas de 64 bits ocupa 8 bytes, mientras que sizeof(int) es 4 bytes.
*/
