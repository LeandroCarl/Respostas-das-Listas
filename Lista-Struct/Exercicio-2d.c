#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    char nome[20];
    int numero_documento;
    int idade;
} Pessoa;

void preenche(Pessoa * p) {
    int i;
    for (i = 0; i < 2; i++) {
        printf("Informe o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", p[i].nome);
        printf("Informe o numero de documento: ");
        scanf("%d", &p[i].numero_documento);
        printf("Informe a idade: ");
        scanf("%d", &p[i].idade);
        printf("\n");
    }
}

void imprime(Pessoa * p) {
    int i;
    for (i = 0; i < 2; i++) {
        printf("\nNome: %s \nSalario: %d \nNumero de documento: %d", p[i].nome, p[i].numero_documento, p[i].idade);
    }
}

int altera_idade(Pessoa *p, int i) {
    int nidade;
    printf("Informe quantos anos tem agora a pessoa %d: ", i + 1);
    scanf("%d", &nidade);
    printf("\n");
    return nidade;
}

void compara_idade(Pessoa * p) {
    int max = 0, min = 0;
    int i;
    for (i = 0; i < 2; i++) {
        if (p[i].idade > p[max].idade) {
            max = i;
        }
        if (p[i].idade < p[min].idade) {
            min = i;
        }
    }
    printf("\nPessoa mais velha: %s", p[max].nome);
    printf("\nPessoa mais nova: %s", p[min].nome);
}

int main() {
    Pessoa * p = (Pessoa *)malloc(2 * sizeof(Pessoa));

    if (p == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        return 1;
    }

    int i;
    preenche(p);
    imprime(p);
    int r;
    printf("\nDeseja alterar a idade dos sujeitos? 1- SIM ou 0- NAO\n");
    scanf("%d", &r);

    if (r) {
        for (i = 0; i < 2; i++) {
            p[i].idade = altera_idade(p, i);
            printf("Nova idade atualizada da pessoa %d: %d\n", i + 1, p[i].idade);
        }
    }

    compara_idade(p);

    free(p);

    return 0;
}
