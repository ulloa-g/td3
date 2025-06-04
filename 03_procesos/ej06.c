// Ejercicio 6 de TP Procesos

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid

int main ()
{
	int x = 100;
	
	printf("Soy el proceso: %d \n ",getpid());
    pid_t pid = fork();

    if (pid == -1)
    {
        perror ("Error. No se crea proceso hijo");
        return 1;
    }
    else if (pid == 0)
    {
        printf ("Soy el hijo, pid: %d, x = %d, direccion X=%li\n", getpid(), --x, (&x));
        exit(0);
    }
    else
    {
        // para imprimir direcciones de memoria (punteros), el especificador de formato correcto es %p
        // cuando usas %p, el argumento correspondiente debe ser de tipo void *. 
        // debes hacer un "cast" a tipo (void *)
        printf ("Soy el padre, pid: %d, x = %d, direccion X=%p\n", getpid(), ++x, (void *)&x);
        return 0;
    }

}

/*
Respuestas al ejercicio:

El padre y el hijo tienen su propia copia de la variable x,
por lo que cada uno puede modificar su valor sin afectar al otro.

En cuanto a las direcciones:  
direcciones virtuales pueden ser numéricamente idénticas para variables locales, 
pero aún así apuntan a memoria física diferente debido a la forma en que el kernel 
maneja los espacios de direcciones
*/