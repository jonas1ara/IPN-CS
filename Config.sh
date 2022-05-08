#!/bin/bash



echo "Este script instala las librerías para trabajar con este repositorio"

sudo apt update && sudo apt upgrade -y

sudo apt-get install libncurses5-dev libncursesw5-dev

sudo apt install libgtk-4-1 libgtk-4-dev
