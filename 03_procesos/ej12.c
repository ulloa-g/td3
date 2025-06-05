//TP Procesos, Ejercicio 11

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define PS_MACRO execl("/bin/sh", "sh", "-c", "ps -ef | grep proc_09", NULL);

int main()
{
    pid_t pid, ppid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork falló\n");
        exit(1);
        
    } else if (pid == 0) { // proceso hijo
        printf("Proceso hijo  (PID=%d) está corriendo.\n", getpid());
        
        sleep(30); 
        
        printf("Proceso hijo  (PID=%d) está saliendo.\n", getpid());

        exit(0);
    
    } else { // proceso padre
        
        printf("Proceso padre (PID=%d) está corriendo.\n", getpid());
        
        sleep(15); 
                
        printf("Proceso padre (PID=%d) está saliendo.\n", getpid());
        
        wait(NULL);  // Espera a que el hijo termine antes de salir
    }
    
    return 0;
}

/*
Debido al uso de wait() en el proceso padre, este esperará a que el proceso hijo termine antes de continuar.
Garantiza que el hijo siempre se ejecute antes de que el padre termine independientemente de los tiempos de slee().
Esto asegura que el proceso hijo no se quede zombie y que el padre pueda recoger su estado de salida correctamente.
*/