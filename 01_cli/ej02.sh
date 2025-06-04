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
# porque el ejecutable está en el directorio actual
# entonces es necesario prefijarlo con "./"
