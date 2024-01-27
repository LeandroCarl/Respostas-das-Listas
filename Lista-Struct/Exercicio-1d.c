#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[20];
    float salario;
    int identificador;
    char cargo[20];
} Funcionario;

void preenche(Funcionario *f) {
    int i;
    for (i = 0; i < 2; i++) {
        printf("Informe o nome do funcionario %d: ", i + 1);
        scanf(" %[^\n]", f[i].nome);
        printf("Informe o salario: ");
        scanf("%f", &f[i].salario);
        printf("Informe o identificador: ");
        scanf("%d", &f[i].identificador);
        printf("Informe o cargo: ");
        scanf(" %[^\n]", f[i].cargo);
        printf("\n");
    }
}

void imprime(Funcionario *f) {
    int i;
    for (i = 0; i < 2; i++) {
        printf("\nNome: %s \nSalario: %.2f \nIdentificador: %d \nCargo: %s", f[i].nome, f[i].salario, f[i].identificador, f[i].cargo);
        printf("\n");
    }
}

float altera_salario(Funcionario *f, int i) {
    float nsalario;
    printf("Informe o novo salario do funcionario %d: ", i + 1);
    scanf("%f", &nsalario);
    printf("\n");
    return nsalario;
}

void compara_salario(Funcionario *f) {
    int max = 0, min = 0;
    int i;
    for (i = 0; i < 2; i++) {
        if (f[i].salario > f[max].salario) {
            max = i;
        }
        if (f[i].salario < f[min].salario) {
            min = i;
        }
    }
    printf("\nFuncionario com maior salario:\nNome: %s\nSalario: %.2f\nCargo: %s\n", f[max].nome, f[max].salario, f[max].cargo);
    printf("\nFuncionario com menor salario:\nNome: %s\nSalario: %.2f\nCargo: %s\n", f[min].nome, f[min].salario, f[min].cargo);
}

int main() {
    Funcionario *f = (Funcionario *)malloc(2 * sizeof(Funcionario));

    if (f == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        return 1;
    }

    int i;
    preenche(f);
    imprime(f);
    int r;
    printf("\nDeseja alterar o salario dos funcionarios? 1- SIM ou 0- NAO\n");
    scanf("%d", &r);

    if (r) {
        for (i = 0; i < 2; i++) {
            f[i].salario = altera_salario(f, i);
            printf("Novo salario atualizado do funcionario %d: %.2f\n", i + 1, f[i].salario);
        }
    }

    compara_salario(f);

    free(f);

    return 0;
}
