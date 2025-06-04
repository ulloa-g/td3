#!/bin/bash

mkdir ejercicio_bash_avanzado
cd ejercicio_bash_avanzado
echo "Descargando un archivo desde internet"
wget https://github.com/td3-frm/practica/raw/master/01-linea-de-comando/hola.zip

echo "Descomprimiendo el archivo descargado"
unzip hola.zip
mv hola.c hola-mundo.c
nano hola-mundo.c
gcc hola-mundo.c -o hola-mundo

echo "listando el contenido del directorio <ejercicio_bash_avanzado>:"
ls -l

echo "Ejecutando el programa compilado:"
./hola-mundo

# ¿porque es necesario "./" para ejecutar mi archivo?

# Explicación:
# En Linux (Unix), es necesario ejecutar cualquier ejecutable con el prefijo ./
# Cuando escribes un comando como ls, mkdir o gcc en la terminal, el sistema no sabe 
# inmediatamente dónde encontrar el programa correspondiente. 
# Para eso, utiliza una variable de entorno llamada PATH
# la variable PATH contiene una lista de directorios donde el shell debe buscar los ejecutables.
# El directorio actual (./) no está en el PATH por defecto por razones de seguridad
# Garantiza que solo ejecutes programas desde tu directorio actual cuando explícitamente lo indicas
# evitando la ejecución accidental de archivos maliciosos con nombres idénticos a comandos del sistema 
# que puedan estar presentes en tu directorio de trabajo. 
# Es una buena práctica que contribuye a la robustez y seguridad de tu sistema.