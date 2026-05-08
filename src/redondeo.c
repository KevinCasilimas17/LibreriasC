#include <math.h>
#include "redondeo.h"

double error_absoluto(double real, double aprox) {
    return fabs(real - aprox);
}

double error_relativo(double real, double aprox) {
    return fabs(real - aprox) / fabs(real);
}