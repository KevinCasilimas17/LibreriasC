#include <stdio.h>
#include <math.h>
#include "taylor.h"

double taylor_exp(double x, double tol, int max_iter) {
    double suma = 1.0;
    double termino = 1.0;
    int n = 1;

    while (n <= max_iter) {
        termino = termino * x / n;
        suma += termino;

        printf("Iteracion %d: termino = %.10lf, suma = %.10lf\n", n, termino, suma);

        if (fabs(termino) < tol) {
            break;
        }

        n++;
    }

    return suma;
}