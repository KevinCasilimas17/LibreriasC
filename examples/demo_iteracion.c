#include <stdio.h>
#include "iteracion.h"

int main() {
    double x0 = 0.5, tol = 0.0001;
    int iter = 100;
    
    double raiz = punto_fijo(x0, tol, iter);
    
    printf("Raiz aproximada (punto fijo): %.6lf\n", raiz);
    
    return 0;
}