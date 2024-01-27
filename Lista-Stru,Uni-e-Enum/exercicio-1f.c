#include <stdio.h>
#include <stdlib.h>

typedef enum genero {
    masculino,
    feminino
} Genero;

typedef struct pessoa {
    char nome[20];
    int idade;
    Genero genero_pessoa;
} Pessoa;

void get_Dados(Pessoa *pessoa) {
    printf("Informe o nome:\n");
    scanf("%[^\n]", pessoa->nome);
    printf("Informe a idade:\n");
    scanf("%d", &pessoa->idade);
    printf("Informe o genero:\n 0- Masculino\n 1 - Feminino\n");
    scanf("%d", &pessoa->genero_pessoa);
}

void imprime(Pessoa *pessoa) {
    printf("Nome: %s\nIdade: %d\nGenero: %s", pessoa->nome, pessoa->idade, pessoa->genero_pessoa == masculino ? "Masculino" : "Feminino");
}

int main(void) {
    Pessoa * pessoa = (Pessoa *)malloc(sizeof(Pessoa));
    get_Dados(pessoa);
    imprime(pessoa);
    free(pessoa);
    return 0;
}