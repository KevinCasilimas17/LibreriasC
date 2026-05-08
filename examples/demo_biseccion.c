#include <stdio.h>
#include "biseccion.h"

int main() {
    int opcion, max_iter;
    double a, b, tol;

    printf("Metodo de Biseccion\n");
    printf("Seleccione la funcion:\n");
    printf("1. x^2 - 4\n");
    printf("2. x^3 - x - 2\n");
    printf("3. cos(x) - x\n");
    scanf("%d", &opcion);

    printf("Ingrese limite inferior (a): ");
    scanf("%lf", &a);
    printf("Ingrese limite superior (b): ");
    scanf("%lf", &b);
    printf("Ingrese tolerancia: ");
    scanf("%lf", &tol);
    printf("Ingrese maximo de iteraciones: ");
    scanf("%d", &max_iter);

    double raiz = biseccion(a, b, tol, max_iter, opcion);
    printf("\nRaiz aproximada: %.10lf\n", raiz);

    return 0;
}