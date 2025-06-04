#!/bin/bash

# En Linux, hay tres tipos de "flujos" de datos estándar:
# 0. stdin (entrada estándar): teclado.
# 1. stdout (salida estándar): terminal.
# 2. stderr (error estándar): terminal.
gcc ej04.c -o ej04  # compilo el archivo ej04.c
echo "Ejecutando el programa en C compilado:"
./ej04

echo "ejecuto comando ls -l y redirijo stdout a stdout.txt"
ls -l > stdout.txt  # > o 1> es lo mismo, redirige stdout a stdout.txt
echo "Mostrando información del archivo stdout.txt"
cat stdout.txt

echo "ejecuto nuevamente programa en C compilado"
echo "pero esta vez, redirigiendo stderr a err.txt"
./ej04 2> err.txt  # 2> redirige stderr a err.txt
# notar que por terminal muestra stdout, pero stderr se redirige a err.txt
echo "Mostrando información del archivo err.txt"
cat err.txt
