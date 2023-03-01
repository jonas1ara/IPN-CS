# Fundamentos del lenguaje C

![](/00.-Sources/Images/C.png)

_Dennis Ritchie, creador del lenguaje C_

## ¿Qué es C?

C es un lenguaje de programación de propósito general, desarrollado en 1972 por Dennis Ritchie en Bell Labs. Es un lenguaje de bajo nivel, es decir, que se acerca más a la forma en que el computador interpreta los datos. Es un lenguaje de programación imperativo, estructurado, compilado y de tipado estático.

## ¿Por qué C?

C es un lenguaje de programación muy popular, y es el lenguaje de programación más utilizado en la actualidad. Es un lenguaje de programación muy potente, y es usado para crear sistemas operativos, compiladores, editores de texto, etc. C es un lenguaje de programación muy rápido, y es usado para crear programas que requieren un alto rendimiento, además es el lenguaje que se enseña en la mayoría de las universidades incluido el [plan de estudios del IPN](https://www.escom.ipn.mx/docs/oferta/uaLCD2020/fundamentosProgramacion_LCD2020.pdf), quiza la razón o una de las razones sea porque todos los lenguajes actuales son derivados de C, por ejemplo:

-  [C++](https://es.wikipedia.org/wiki/C%2B%2B) 
-  [Java](https://es.wikipedia.org/wiki/Java_(lenguaje_de_programaci%C3%B3n)) 
-  [C#](https://es.wikipedia.org/wiki/C_Sharp) 
-  [Go](https://es.wikipedia.org/wiki/Go_(lenguaje_de_programaci%C3%B3n)) 
-  [Rust](https://es.wikipedia.org/wiki/Rust_(lenguaje_de_programaci%C3%B3n)) y no, no va a matar a C :smile:
- Etc.

## ¿Cómo funciona C?

- C es un lenguaje de programación compilado, es decir, que primero se escribe el código fuente, y después se compila para generar el código objeto, que es el que se ejecuta en el computador. 

- C es un lenguaje de programación imperativo, es decir, que se escribe el código de forma secuencial, y se ejecuta de forma secuencial. 

- C es un lenguaje de programación estructurado, es decir, que se estructuran tipos de datos, y se estructuran las operaciones que se pueden realizar con esos tipos de datos. 

- C es un lenguaje de programación de tipado estático, es decir, que se declara el tipo de dato de las variables en tiempo de compilación y no se puede cambiar el tipo de dato de las variables en tiempo de ejecución.

## ¿Cómo se compila C?

Basta con ejecutar el siguiente comando en la terminal:

```
gcc test.c -o test
```

Donde gcc es el compilador, test.c es el nombre del archivo fuente, -o es el flag para indicar el nombre del archivo ejecutable, y test es el nombre del archivo ejecutable.

## ¿Cómo se ejecuta C?

Basta con ejecutar el siguiente comando en la terminal:

Unix o Linux:

```
./test
```

Windows:

```
.\test
```

## ¿Dónde se ocupa C?

C es un lenguaje de programación muy popular, y es usado para crear sistemas operativos, compiladores, editores de texto, etc. Por ejemplo:

- [GNU](https://www.gnu.org/) herramientas de desarrollo de software libre mayormente escritas en C
- [Linux](https://www.kernel.org/) es un sistema operativo de código abierto, mayormente escrito en C
- [Bash](https://www.gnu.org/software/bash/) es un intérprete de comandos, escrito en C
- [WSL](https://docs.microsoft.com/en-us/windows/wsl/about) es un subsistema de Linux para Windows, escrito en C
- [Windows Kernel](https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/) es el núcleo del sistema operativo Windows, escrito en C
- [Mac OS X](https://www.apple.com/macos/) es un sistema operativo de Apple, escrito en C
- [GCC](https://gcc.gnu.org/) es un compilador de lenguaje C, escrito en C
- [VIM](https://www.vim.org/) es un editor de texto, escrito en C
- [Emacs](https://www.gnu.org/software/emacs/) es un editor de texto, escrito en C
- [Git](https://git-scm.com/) es un sistema de control de versiones, escrito en C
- [Python](https://www.python.org/) es un lenguaje de programación, escrito en C
- [Ruby](https://www.ruby-lang.org/) es un lenguaje de programación, escrito en C
- [Node.js](https://nodejs.org/) es un entorno de ejecución de JavaScript, escrito en C y C++
- [MySQL](https://www.mysql.com/) es un sistema de base de datos, escrito en C y C++

## Estructura de esta sección del repositorio

### _[Fundamentos](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos); esta sección es para que conozcas la sintaxis básica, impresión por terminal, guardar variables, tipos de datos, condicionales, etc._

1. [HolaMundo.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/01-Hola-Mundo.c)
2. [Directivas.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/02-Directivas.c)
3. [Suma.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/03-Suma.c)
4. [Aritmética.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/04-Aritm%C3%A9tica.c)
5. [Variables.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/05-Variables.c)
6. [Conversión.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/06-Conversi%C3%B3n.c)
7. [Condicionales.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/07-Condicionales.c)
8. [Casos.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/08-Casos.c)
9. [Band.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/09-Band.c)
10. [Vector.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/10-Vector.c)
11. [Matriz.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/01.-Fundamentos/11-Matriz.c)

### _[Bucles](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/02.-Bucles); usados para repetir una o más instrucciones un número determinado de veces_

1. [For.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/02.-Bucles/01-For.c)
2. [While.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/02.-Bucles/02-While.c)
3. [Do-while.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/02.-Bucles/03-Do-while.c)

### _[Funciones](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/03.-Funciones); son fragmentos de código que se pueden reutilizar en diferentes partes de un programa_

1. [Funciones.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/03.-Funciones/01-Funciones.c)

2. [Función-rand.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/03.-Funciones/02-Funci%C3%B3n-rand.c)

3. [Retornar-función.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/03.-Funciones/03-Retornar-funci%C3%B3n.c)

4. [Funciones-tipo-void.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/03.-Funciones/04-Funciones-de-tipo-void.c)

5. [Función-vector.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/03.-Funciones/05-Funci%C3%B3n-vector.c)

6. [Función-recursiva.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/03.-Funciones/06-Funci%C3%B3n-recursiva.c)

### _[Estructuras](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/04.-Estructuras); son tipos de datos que permiten agrupar datos de diferentes tipos en una sola variable_

1. [Typedef-struct.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/04.-Estructuras/01-Typedef-struct.c)

2. [Formulario-typedef-struct.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/04.-Estructuras/02-Formulario-typedef-struct.c)

3. [Vectores-a-structs.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/04.-Estructuras/03-Vectores-a-structs.c)

4. [Structs-de-structs.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/04.-Estructuras/04-Struct-de-structs.c)

5. [Punteros-a-structs.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/04.-Estructuras/05-Punteros-a-structs.c)

### _[Punteros](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/05.-Punteros); son variables que almacenan direcciones de memoria_

1. [Punteros.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/05.-Punteros/01-Punteros.c)

2. [Sizeof.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/05.-Punteros/02-Sizeof.c)

3. [Numero-par-o-impar.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/05.-Punteros/03-Numero-par-o-impar.c)

4. [Arreglos-y-punteros.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/05.-Punteros/04-Arreglos-y-punteros.c)

5. [Numeros-pares-de-un-arreglo.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/05.-Punteros/05-Numeros-pares-de-un-arreglo.c)


### _[Cadenas](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/06.-Cadenas); son arreglos de caracteres_

1. [Cadena.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/06.-Cadenas/01-Cadena.c)

2. [Acceder-a-caracter.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/06.-Cadenas/02-Acceder-a-caracter.c)

3. En el README.md de la carpeta de cadenas se encuentran ejemplos de como usar las funciones más importantes de la librería `string.h`

### _[Archivos](); en esta sección se verá la forma de trabajar con archivos_

1. [Lectura-de-archivos.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/07.-Archivos/01-Lectura-de-archivos.c)

2. [Leer-y-meter-datos-en-un-struct.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/07.-Archivos/02-Leer-y-meter-datos-en-struct.c)

3. [Escribir-en-un-archivo.c](https://github.com/Jonas-Lara/IPN-CS/blob/master/01.-B%C3%A1sicos-del-lenguaje-C/07.-Archivos/03-Escribir-archivo-con-fprintf.c)

### _[Modularidad](https://github.com/Jonas-Lara/IPN-CS/tree/master/01.-B%C3%A1sicos-del-lenguaje-C/08.-Modularidad); en esta sección se verá la forma de modularizar el código_
## Para terminar

Quiza la razón más importante para aprender C es que es un lenguaje de programación que te obliga a pensar más y mejor, cuándo aprendes a programar con Python o Javascript es muy fácil que te olvides de los detalles de la memoria, y que te olvides de los detalles de la computación, pero cuando aprendes a programar en C, te das cuenta de que no es tan fácil, y que tienes que pensar más y mejor, y eso es bueno, porque te hace un mejor programador. Por supuesto no es necesario que aprendas C, pero si quieres aprender a programar, y quieres aprender a programar bien, entonces C es un buen lenguaje sin caer en la exageración como C++

## Expresiones de gratitud

_Escrito con ❤️ por [Jonas Lara](https://medium.com/@jonas_lara) estudiante de ingeniería en IA en la [UPIIT](https://www.upiit.ipn.mx/) para quien sea que este interesado_
