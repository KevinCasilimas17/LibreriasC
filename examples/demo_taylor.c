#include <stdio.h>
#include <math.h>
#include "taylor.h"

int main() {
    double x, tol;
    int max_iter;

    printf("Aproximacion de e^x usando Taylor\n");
    printf("Ingrese valor de x: ");
    scanf("%lf", &x);
    printf("Ingrese tolerancia: ");
    scanf("%lf", &tol);
    printf("Ingrese maximo de iteraciones: ");
    scanf("%d", &max_iter);

    double resultado = taylor_exp(x, tol, max_iter);
    printf("\nResultado aproximado: %.10lf\n", resultado);
    printf("Valor real (exp): %.10lf\n", exp(x));

    return 0;
}