# Ejercicio 8 de TP Procesos

import os
import multiprocessing

def proceso_hijo():
    # Función que será ejecutada por el proceso hijo

    print("Proceso hijo ejecutándose con ID:", os.getpid())
    for i in range(5) :
        # Incrementar la variable compartida en el proceso hijo
        suma.value += 10

    print('Hijo, valor de suma : ' , suma.value)
    
# Función principal que creará el proceso hijo y esperará a que termine
if __name__ == "__main__":

    # Crear una variable compartida de tipo int con valor inicial 0
    suma = multiprocessing.Value('i', 0)
    
    # Crear proceso hijo
    hijo = multiprocessing.Process(target=proceso_hijo)
    hijo.start()

    for i in range(5) :
         # Incrementar la variable compartida en el proceso hijo
        suma.value += 1
    
    print('PID del proceso padre : ' , os.getpid())
    print('PID del proceso hijo  : ' , hijo.pid)
    print('Nombre del proceso hijo : ' , hijo.name)
    print('Padre, valor de suma : ' , suma.value)

    # Esperar a que termine el proceso hijo
    hijo.join()
    # hijo.terminate()

    print("Proceso hijo finalizado")


"""
Respuesta a la pregunta del ejercicio:

multiprocessing.Value(tipo_dato, valor_inicial) crea una ubicación de memoria compartida que puede ser accedida por múltiples procesos.
es una forma de que los procesos puedan compartir datos de manera segura y eficiente.


La variable compartida `suma` e este caso, se utiliza para almacenar un entero que se inicializa en 0.
El proceso hijo incrementa `suma.value` en 10 durante su ejecución
el proceso padre lo incrementa en 1. 
Al final, ambos procesos acceden a la misma variable compartida, lo que permite ver el valor final de `suma` 
después de que ambos procesos hayan realizado sus operaciones.
El resultado final de `suma.value` será 55, ya que el padre incrementa en 1 cinco veces (5) y el hijo incrementa en 10 cinco veces (50), sumando un total de 55.
El uso de `multiprocessing.Value` permite que ambos procesos accedan y modifiquen la misma variable de manera segura, evitando problemas de concurrencia.   
"""