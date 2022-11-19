# Punteros

_Un puntero es solo una variable que tiene una dirección de memoria 🎈 , un puntero doble es un puntero que guarda la dirección de otro apuntador 🎈🎈 y ambos apuntadores sirven para manipular, cambiar o realizar alguna operación_

![P](/00.-Sources/Images/Ptr.png)

## Paso por referencia

_En el paso por referencia se pasa la dirección de memoria de una variable, en lugar de pasar el valor de la variable, esto permite que la función pueda modificar el valor de la variable original_

![PR](/00.-Sources/Images/PR.png)

_En este ejemplo podemos observar que el primer valor impreso es el de la variable `num` que es igual a 5 al iniciar el programa, despues se hace un llamado a la función `ReferenciaDoble` **pasandole por referencia** la dirección de memoria de la variable `numPunteroSimple` que esta apuntando a la dirección de memoria de la variable `num`, la tarea de la función es pedir un número al usuario para asignarle ese numero a la variable `num`, al final podemos observar que se imprimio el nuevo valor de la variable `num`_

## Parámetro de dirección

_Cuando usamos el símbolo `&` estamos indicando la dirección, la **dirección de memoria es el lugar donde se guarda el dato**, entonces cuando escribimos `&x` estamos diciendo la dirección de la variable x_

![PD](/00.-Sources/Images/PD.png)

_En este primer dibujo podemos observar que el entero `a` vale 5 y está alojado en la dirección de memoria 102, al asignarle al entero `b` la dirección de memoria del entero `a`, obtenemos que el valor del entero `b` es la dirección de memoria del entero `a` que en este caso 102_

## Parámetro de indirección

_Cuando usamos el símbolo `*` estamos indicando el **valor que hay en la dirección**, no la dirección de memoria y este solo **señala** el valor de la dirección de memoria, usualmente usada para el paso por referencia en las funciones_

![PI](/00.-Sources/Images/PI1.png)

_En este segundo dibujo podemos observar que el entero `a` vale 5 y está alojado en la dirección de memoria 102, al asignarle al entero `b` la dirección de memoria del entero `a`, obtenemos que el valor del entero `b` es la dirección de memoria del entero `a`  que en este caso 102, pero si además le asignamos a un nuevo entero llamado `c` el valor de lo que hay en la dirección de memoria del entero `b`, obtenemos el valor 5 que es el valor de `a`_

### Todo el rollo de los punteros y el paso por referencia fue pensado para NO copiar objetos innecesariamente, y hacer un uso optimo de la memoria RAM 😉

## Referencias

- [Punteros y paso por referencia en Medium por Jonas Lara](https://medium.com/@jonas_lara/punteros-y-paso-por-referencia-4e4d52370b66)


## Expresiones de gratitud

Escrito con ❤️ por [Jonas Lara](https://www.linkedin.com/in/jonas1ara/) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/) para quien sea que este interesado
