#include <stdio.h>

void inverter(int *vetor, int n) {
    int i, t;
    for (i = 0; i < n / 2; i++) {
        t = vetor[i];
        vetor[i] = vetor[n - 1 - i];
        vetor[n - 1 - i] = t;
    }
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int i;
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor em ordem: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    inverter(vetor, n);

    printf("\nVetor invertido: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    return 0;
}