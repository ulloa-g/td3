# Ejercicio 7 de TP Procesos

import os
import multiprocessing


def proceso_hijo():
    # Función que será ejecutada por el proceso hijo
    print("Proceso hijo ejecutándose con ID:", os.getpid())

    while True :
        pass
    
# Función principal que creará el proceso hijo y esperará a que termine
if __name__ == "__main__":

    # Crear proceso hijo
    # se crea un objeto Process y se indica al nuevo proceso qué función debe ejecutar al iniciar.
    hijo = multiprocessing.Process(target=proceso_hijo)
    hijo.start()  # el SO crea un nuevo proceso y ejecuta la función indicada.

    print('PID del proceso padre : ' , os.getpid())
    print('PID del proceso hijo  : ' , hijo.pid)
    print('Nombre del proceso hijo : ' , hijo.name)

    hijo.terminate()  # el padre le envía una señal al hijo para que termine su ejecución de forma abrupta

    print("Proceso hijo finalizado")
