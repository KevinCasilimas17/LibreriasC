#include <stdio.h>
#include "binarios.h"

void decimal_a_binario(int n) {
    int binario[32];
    int i = 0;

    while(n > 0) {
        binario[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Binario: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

int binario_a_decimal(int binario) {
    int decimal = 0, i = 0;

    while(binario > 0) {
        int digito = binario % 10;
        decimal += digito * (i == 0 ? 1 : (i == 1 ? 2 : (i == 2 ? 4 : (i == 3 ? 8 : (i == 4 ? 16 : (i == 5 ? 32 : 64))))));
        binario /= 10;
        i++;
    }

    return decimal;
}