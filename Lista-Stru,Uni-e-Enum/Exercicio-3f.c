#include <stdio.h>
#include <stdlib.h>

typedef enum mes {
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Mes;

typedef struct data {
    char dia[3], ano[5];  
    Mes m;
} Data;

int main() {
    Data* d = (Data*)malloc(sizeof(Data));

    if (d == NULL) {
        printf("Erro na alocacao\n");
        return 1;
    }

    printf("Informe o dia: ");
    scanf("%s", d->dia);
    printf("\nInforme o mes: ");
    scanf("%d", &d->m);
    printf("\nInforme o ano: ");
    scanf("%s", d->ano);

    if (d->m < JANEIRO || d->m > DEZEMBRO) {
        printf("Mes invalido\n");
        free(d);
        return 1;
    }

    printf("DATA: %s/%02d/%s\n", d->dia, d->m, d->ano);  

    
    free(d);

    return 0;
}
