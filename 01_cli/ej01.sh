#!/bin/bash

#¿Cómo ejecutar este script?
# 1. Abre una terminal. Ctrl + Alt + T en Ubuntu.
# 2. Navega al directorio donde se encuentra este script.
# 3. Dar permisos de ejecución al script con el comando: chmod +x ej01.sh
# 4. Ejecuta el script con el comando: ./ej01.sh

mkdir ejercicio_bash
cd ejercicio_bash
touch ejercicio.txt
echo "Listando el contenido del directorio <ejercicio_bash>:"
ls
echo "Escribiendo información en archivo <ejercicio.txt>:"
echo "Hola Mundo!" > ejercicio.txt # > redirige la salida al archivo
echo "El contenido del archivo <ejercicio.txt> es:"
cat ejercicio.txt

mkdir subcarpeta
cp ejercicio.txt subcarpeta/

echo "Listando el contenido de la subcarpeta <subcarpeta>:"
ls subcarpeta
