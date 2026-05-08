#include <stdio.h>
#include "newton.h"

int main() {
    int opcion, max_iter;
    double x0, tol;
    
    printf("Seleccione la funcion:\n");
    printf("1. x^2 - 4\n");
    printf("2. x^3 - x - 2\n");
    printf("3. cos(x) - x\n");
    scanf("%d", &opcion);
    
    printf("Ingrese valor inicial: ");
    scanf("%lf", &x0);
    
    printf("Ingrese tolerancia: ");
    scanf("%lf", &tol);
    
    printf("Ingrese maximo de iteraciones: ");
    scanf("%d", &max_iter);
    
    double raiz = newton(x0, tol, max_iter, opcion);
    
    printf("\nRaiz aproximada: %.6lf\n", raiz);
    
    return 0;
}