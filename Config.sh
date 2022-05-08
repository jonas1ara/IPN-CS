#!/bin/bash

echo "Este script instala las librerías para trabajar con este repositorio"


sudo apt update && sudo apt upgrade -y

echo "Herramientas y compiladores"

sudo apt instal build-essential gdb clang make

echo "Librerías para ncurses"

sudo apt-get install libncurses5-dev libncursesw5-dev -y

echo "Librerías para GTK4"

sudo apt install libgtk-4-1 libgtk-4-dev -y

