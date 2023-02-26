# Interpolación cuadrática

_La interpolación consiste en hallar un dato dentro de un intervalo en el que conocemos los valores en los extremos._

_El problema general de la interpolación se nos presenta cuando nos dan una función de la cual solo conocemos una serie de puntos de la misma:_

_**(x0, y0), (x1, y1),…, (xn, yn)**_

_La interpolación pide hallar el valor y de un punto x (intermedio de x0 y xn) de esta función._

_Cuando el polinomio que conviene es de 2º grado la interpolación recibe el nombre de cuadrática._

_Lagrange (1736-1813) dio una manera simplificada de calcular los polinomios interpoladores de grado n. Para el caso de un polinomio de 2º grado que pasa por los puntos (x0, y0 ), (x1, y1), (x2, y2) la solución viene dada por la siguiente ecuación:_

![alt text](/00.-Sources/Images/IC.jpg)

_Esta ecuación nos permite realizar la interpolación de un nuevo punto (x,y), simplemente sustituyendo el valor de x, el resultado p(x) será la y buscada._

