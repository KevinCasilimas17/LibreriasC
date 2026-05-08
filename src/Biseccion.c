#include <stdio.h>
#include <math.h>
#include "biseccion.h"

double f_biseccion(double x, int opcion) {
    switch(opcion) {
        case 1: return x*x - 4;
        case 2: return x*x*x - x - 2;
        case 3: return cos(x) - x;
        default: return 0;
    }
}

double biseccion(double a, double b, double tol, int max_iter, int opcion) {
    double xr, xr_ant = 0;
    double error = 1;
    int i = 0;

    if (f_biseccion(a, opcion) * f_biseccion(b, opcion) >= 0) {
        printf("Error: el intervalo no encierra una raiz.\n");
        return 0;
    }

    while (i < max_iter && error > tol) {
        xr = (a + b) / 2.0;

        if (i > 0) {
            error = fabs((xr - xr_ant) / xr);
        }

        printf("Iteracion %d: xr = %.10lf, error = %.10lf\n", i+1, xr, error);

        if (f_biseccion(a, opcion) * f_biseccion(xr, opcion) < 0) {
            b = xr;
        } else {
            a = xr;
        }

        xr_ant = xr;
        i++;
    }

    return xr;
}