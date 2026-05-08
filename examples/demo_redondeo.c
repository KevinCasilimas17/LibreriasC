#include <stdio.h>
#include "redondeo.h"

int main() {
    double real, aprox;

    printf("Ingrese valor real: ");
    scanf("%lf", &real);
    printf("Ingrese valor aproximado: ");
    scanf("%lf", &aprox);

    printf("Error absoluto: %.10lf\n", error_absoluto(real, aprox));
    printf("Error relativo: %.10lf\n", error_relativo(real, aprox));

    return 0;
}