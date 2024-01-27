#include <stdio.h>
#include <stdlib.h>

typedef struct ingresso {
    char local[20];
    float preco;
    char atracao[20];
} Ingresso;

void preenche(Ingresso *n, int Q) {
    int i;
    for (i = 0; i < Q; i++) {
        printf("Informe o local do show : ");
        scanf(" %[^\n]", n[i].local);
        printf("Informe o preco: ");
        scanf("%f", &n[i].preco);
        printf("Informe qual será o evento: ");
        scanf(" %[^\n]", n[i].atracao);
        printf("\n");
    }
}

void imprime(Ingresso *n, int Q) {
    int i;
    for (i = 0; i < Q; i++) {
        printf("\nIngresso %d \nLocal: %s \nPreco: R$ %.2f \nAtracao: %s", i + 1, n[i].local, n[i].preco, n[i].atracao);
        printf("\n");
    }
}

float altera_preco(Ingresso *n, int i) {
    float npreco;
    printf("Preco atual do Ingresso %d: R$ %.2f\n", i + 1, n[i].preco);
	printf("Informe o novo preco: ");
    scanf("%f", &npreco);
    printf("\n");
    return npreco;
}

void compara_preco(Ingresso *n, int Q) {
    int max = 0, min = 0;
    int i;
    for (i = 0; i < Q; i++) {
        if (n[i].preco > n[max].preco) {
            max = i;
        }
        if (n[i].preco < n[min].preco) {
            min = i;
        }
    }
    printf("\nIngresso mais caro: \nAtracao: %s\nPreco: R$ %.2f", n[max].atracao, n[max].preco);
    printf("\nIngresso mais barato:\nAtracao: %s\nPreco: R$ %.2f", n[min].atracao, n[min].preco);
}

int main() {
    int Q;
	Ingresso *n = (Ingresso *)malloc(Q * sizeof(Ingresso));
	
    if (n == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        return 1;
    }
	printf("Digite a quantidade de ingressos: ");
	scanf("%d", &Q);
    int i;
    preenche(n, Q);
    imprime(n, Q);
    int r;
    printf("\nDeseja alterar o preco dos ingressos? 1- SIM ou 0- NAO\n");
    scanf("%d", &r);

    if (r) {
        for (i = 0; i < Q; i++) {
            n[i].preco = altera_preco(n, i);
            printf("Novo preco atualizado: R$ %.2f\n", n[i].preco);
        }
    }

    compara_preco(n, Q);

    free(n);

    return 0;
}
