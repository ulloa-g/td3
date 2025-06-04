#!/bin/bash

mkdir ejercicio_rutas
cd ejercicio_rutas
mkdir fotos videos documentos
wget https://github.com/td3-frm/practica/raw/master/01-linea-de-comando/Paul-Cezanne_Still-Life-With-Apples.jpeg
mv Paul-Cezanne_Still-Life-With-Apples.jpeg ./fotos
echo "Contenido de mi archivo" > 1342-0.txt
mkdir /home/gabriel/repos/td3/01_cli/ejercicio_rutas/backup
cp 1342-0.txt /home/gabriel/repos/td3/01_cli/ejercicio_rutas/backup
