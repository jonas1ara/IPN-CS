#!/bin/bash

echo "Este script instala las librerías para trabajar con este repositorio"
echo " "

sudo apt update && sudo apt upgrade -y

echo " "
echo "Herramientas y compiladores: "
echo " "

sudo apt install build-essential gdb clang make

echo " "
echo "Librerías para ncurses: "
echo " "

sudo apt-get install libncurses5-dev libncursesw5-dev -y

echo " "
echo "Librerías para GTK4: "
echo " "

sudo apt install libgtk-4-1 libgtk-4-dev -y
