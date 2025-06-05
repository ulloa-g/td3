#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main ()
{
    signal(SIGSTOP, SIG_IGN);  //Ctrl + Z  -> Es otra de las señales que no se pueden ignorar
    printf("Proceso PID = %d\n", getpid());   
    while(1);
   
    return 0;
}
