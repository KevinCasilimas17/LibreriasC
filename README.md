# LibreriasC

Repositorio de bibliotecas en lenguaje C para métodos numéricos, conversiones y aproximaciones matemáticas.

## Bibliotecas incluidas

| Biblioteca | Archivo de cabecera | Descripcion |
|------------|---------------------|--------------|
| iteracion  | iteracion.h         | Metodo de punto fijo para encontrar raices de ecuaciones |
| newton     | newton.h            | Metodo Newton-Raphson para encontrar raices de ecuaciones |
| binarios   | binarios.h          | Conversion entre numeros decimales y binarios |
| biseccion  | biseccion.h         | Metodo de biseccion para encontrar raices en un intervalo |
| redondeo   | redondeo.h          | Calculo de errores absoluto y relativo |
| taylor     | taylor.h            | Aproximacion de la funcion exponencial mediante serie de Taylor |

## Compilacion de bibliotecas
### Requisitos

- Compilador GCC 


### Compilacion de la biblioteca estatica (.a)
# Compilar los archivos objeto
gcc -c -Iinclude src/iteracion.c -o src/iteracion.o
gcc -c -Iinclude src/newton.c -o src/newton.o
gcc -c -Iinclude src/binarios.c -o src/binarios.o
gcc -c -Iinclude src/biseccion.c -o src/biseccion.o
gcc -c -Iinclude src/redondeo.c -o src/redondeo.o
gcc -c -Iinclude src/taylor.c -o src/taylor.o


# Crear la biblioteca estatica
ar rcs lib/libmatematicas.a src/*.o