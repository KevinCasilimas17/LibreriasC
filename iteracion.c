#include <math.h>
#include "iteracion.h"

double g(double x) {
    return cos(x);
}

double punto_fijo(double x0, double tol, int max_iter) {
    double x1;
    
    for(int i = 0; i < max_iter; i++) {
        x1 = g(x0);
        
        if(fabs(x1 - x0) < tol) {
            return x1;
        }
        
        x0 = x1;
    }
    
    return x1;
}