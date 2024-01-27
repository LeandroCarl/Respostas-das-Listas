#include <stdio.h>
#include <stdlib.h>
typedef enum tipos{
	ALIMENTO, 
	BEBIDA,
	ELETRONICO
}Tipos;

typedef union tipoDet{
	char alimento[20];
	char bebida[20];
	char eletronico[20];
}TiposDet;

typedef struct produto{
	char nome[80];
	float preco;
	Tipos tipo;
	TiposDet t;
}Produto;

int main() {
	Produto *produto = (Produto*) malloc(sizeof(Produto));
	
	printf("Informe o nome do produto: ");
	scanf(" %[^\n]", produto->nome);
	printf("\nInforme o preco: ");
	scanf("%f", &produto->preco);
	printf("\nQual o tipo do produto? (0 - ALIMENTO, 1 - BEDIDA E 2 - ELETRONICO: ");
	scanf("%d", &produto->tipo);
	
	switch(produto->tipo){
		case ALIMENTO:
			printf("\nInforme o tipo de alimento: ");
			scanf("%s", produto->t.alimento);
			break;
	case BEBIDA:
			printf("\nInforme o tipo de bebida: ");
			scanf("%s", produto->t.bebida);
			break;
	case ELETRONICO:
			printf("\nInforme o tipo de eletronico: ");
			scanf("%s", produto->t.eletronico);
			break;
		default:
			printf("Opcao invalida\n");
			return 1;
	}
	
	printf("\nDADOS DO PRODUTO: \n");
	printf("Nome: %s \nPreco: R$ %.2f \n", produto->nome, produto->preco);
	
	switch(produto->tipo){
		case ALIMENTO:
			printf("Tipo: Alimento - %s", produto->t.alimento);
			break;
	case BEBIDA:
			printf("Tipo: Bebida - %s", produto->t.bebida);
			break;
	case ELETRONICO:
			printf("Tipo: Eletronico - %s", produto->t.eletronico);
			break;
		default:
	printf("Opcao invalida\n");
	return 1;
	}
	
	return 0;
}