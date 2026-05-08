#include <stdio.h>
#include "binarios.h"

int main() {
    int opcion;

    printf("1. Decimal a Binario\n");
    printf("2. Binario a Decimal\n");
    printf("Seleccione: ");
    scanf("%d", &opcion);

    if(opcion == 1) {
        int num;
        printf("Ingrese numero decimal: ");
        scanf("%d", &num);
        decimal_a_binario(num);
    } else if(opcion == 2) {
        int bin;
        printf("Ingrese numero binario: ");
        scanf("%d", &bin);
        printf("Decimal: %d\n", binario_a_decimal(bin));
    }

    return 0;
}