# Snake 🐍

## El clásico juego de los teléfonos nokia

## Controles 

Se juega con las teclas `W = Arriba` , `S = Abajo`, `D = Derecha`, `A = Izquierda`

_Compila y ejecuta_

```
gcc Snake.c -o Snake -lncurses && ./Snake
```

<img src=/00.-Sources/Gifs/Snake.gif alt="#"/>

## Explicación

El código es bastante simple, se utilizan las funciones de ncurses para dibujar en la terminal, se utilizan las funciones `getch()` y `getch()` para obtener la tecla presionada por el usuario y se utilizan las funciones `mvprintw()` y `mvaddch()` para dibujar en la terminal pero lee el código maldita sea >.<

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/), para quien sea que este interesado_





