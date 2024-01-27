#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct aluno{
	char nome[80];
	int matricula;
	float notas[3];
	float media;
	char turma[20];
}Aluno;


void matricula(Aluno *aluno, int Q){
	int i;
	for(i = 0; i < Q; i++){
	printf("\nInforme o nome do aluno %d: ", i + 1);
	scanf(" %[^\n]", aluno[i].nome);
	printf("\nInforme a matricula do aluno %d: ", i + 1);
	scanf("%d", &aluno[i].matricula);
	printf("\na turma a qual pertence: ");
	scanf(" %[^\n]", aluno[i].turma);
		
}
}

void lanca_notas(Aluno *aluno, int Q){
	int i, j;
	for(i = 0; i < Q; i++){
		for(j = 0; j < 3; j++){
			printf("\nNota %d do aluno %d: ", j + 1, i + 1);
			scanf("%f", &aluno[i].notas[j]);
		}
		aluno[i].media = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2])/3;
	}
	
	for(i = 0; i < Q; i++){
			printf("\nMedia do aluno %d: %.2f", i + 1, aluno[i].media);
		}
	}

	void imprime_tudo(Aluno *aluno, int Q) {
    int i, j;
    for (i = 0; i < Q; i++) {
    	printf("\nNome: %s \nMatricula: %d \nTurma: %s \nMedia: %.2f", aluno[i].nome, aluno[i].matricula, aluno[i].turma, aluno[i].media);
		for (j = 0; j < 3; j++){
   			printf("\nNota %d do aluno %d: %.2f\n", j + 1, i + 1, aluno[i].notas[j]);
        printf("\n");
    }
}
}

void imprime_turma(Aluno *aluno, int Q){
	char turma[20];
	int i, j;
	printf("Escolha a turma: ");
	scanf(" %[^\n]", turma);

	int TurmaEncontrada = 0;
	for (i = 0; i < Q; i++){
	if (strcmp(turma, aluno[i].turma) == 0) {
		TurmaEncontrada = 1;
		printf("\nNome: %s \nMatricula: %d \nMedia: %.2f", aluno[i].nome, aluno[i].matricula, aluno[i].media);
		for (j = 0; j < 3; j ++) {
			printf("\nNota %d do aluno %d: %.2f", j + 1, i + 1, aluno[i].notas[j]);
		}
	}		
}
	if (!TurmaEncontrada) {
	printf("Turma nao encontrada\n");
}
}
	

void imprime_turma_aprovados(Aluno *aluno, int Q){
	char turma[20];
	int i;
	printf("Escolha uma turma: ");
	scanf(" %[^\n]", turma);
	
	int TurmaEncontrada = 0;
	for (i = 0; i < Q; i++){
		if (strcmp(turma, aluno[i].turma) == 0 && aluno[i].media >= 7){
			TurmaEncontrada = 1;
			printf("\nNome: %s \nMedia: %.2f\n", aluno[i].nome, aluno[i].media);
		}
	}
	
	if (!TurmaEncontrada) {
	printf("Turma nao encontrada\n");
}
}


int main(){
	int M = 6;
	int Q;
	
	Aluno * aluno = (Aluno*) malloc(Q * sizeof(Aluno));
	
	if (aluno == NULL) {
		printf("Erro na alocacao. Encerrando programa");
		return 1;
	}
	printf("Numero de Vagas disponiveis: %d\n", M);
	printf("\nInforme a quantidade de alunos: \n");
	scanf("%d", &Q);
	
	if (aluno == NULL) {
		printf("Erro na alocacao. Encerrando programa");
		return 1;
	}
	
	if (Q > M) {
		printf("%d ficaram na lista de espera\n", Q - M);
		Q = M;
	}
	matricula(aluno, Q);
	lanca_notas(aluno, Q);
	imprime_tudo(aluno, Q);
	int op;
	
	printf("\nIMPRIMIR UMA TURMA ESPECIFICA \n");
	do {
	imprime_turma(aluno, Q);
	printf("\nDeseja escolher outra turma? 1 - SIM ou 0 - NAO\n");
	scanf("%d", &op);
} while(op);
	
	printf("SECAO DOS APROVADOS \n");
	do {
	imprime_turma_aprovados(aluno, Q);
	printf("\nDeseja escolher outra turma? 1 - SIM ou 0 - NAO\n");
	scanf("%d", &op);
} while(op);
free(aluno);
}