#!/bin/bash

FILE_NAME="ej10.c"

echo "Compilando " $FILE_NAME
gcc ej10.c -o ej10

echo "Ejecutando " $FILE_NAME
./ej10

echo "Programa finalizado."

