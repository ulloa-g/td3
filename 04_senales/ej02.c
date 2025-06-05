#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main ()
{
    signal(SIGKILL, SIG_IGN);
    //signal(SIGSTOP, SIG_IGN);  //Ctrl + Z
    printf("Proceso PID = %d\n", getpid());   
    while(1);
   
    return 0;
}

/*
La función signal() en C se usa para establecer cómo un proceso debe manejar una señal 
específica del sistema (SIGINT, SIGSTOP, SIGTERM, etc.).

Sintaxis:
void (*signal(int signum, void (*handler)(int)))(int);
signum: El número de la señal que quieres manejar
handler: Un puntero a una función definida por usuario que actuará como manejador de la señal, 
o una de las constantes especiales:
    SIG_IGN: Ignora la señal.
    SIG_DFL: Usa el comportamiento por defecto.

No todas las señales pueden ser capturadas o ignoradas
por ejemplo: SIGKILL y SIGSTOP.
*/