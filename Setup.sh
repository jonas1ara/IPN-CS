#!/bin/bash

echo "Este script instala las herramientas, librerías y compiladores para trabajar con este repositorio"
echo " "

sudo apt update && sudo apt upgrade -y

echo " "
echo "Herramientas, debugger y compiladores: "
echo " "

sudo apt install build-essential gdb clang make -y

echo " "
echo "Librerías para ncurses: "
echo " "

sudo apt-get install libncurses5-dev libncursesw5-dev -y

echo " "
echo "Librerías para GTK4: "
echo "Nota: solo trabajan si usas WSLg o Linux Desktop ..."
echo " "

sudo apt install libgtk-4-1 libgtk-4-dev -y

echo "Compilando aplicaciones de consola ..."

cd ~/IPN-CS/08.-Consola/02.-Hanoi/

gcc Hanoi.c -o hanoi

sudo mv hanoi /usr/bin/

cd ~/IPN-CS/08.-Consola/03.-Dona/

gcc Dona.c -o dona -lm

sudo mv dona /usr/bin

cd ~/IPN-CS/08.-Consola/04.-Snake/

gcc Snake.c -o snake -lncurses

sudo mv snake /usr/bin

cd ~/IPN-CS/08.-Consola/05.-Matrix/

make

sudo mv matrix /usr/bin

make clean

echo "Para probar los ejecutables, escriba en terminal: "
echo " "
echo "hanoi"
echo "dona"
echo "snake"
echo "matrix"