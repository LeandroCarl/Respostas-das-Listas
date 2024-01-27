#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entrevistado {
	char sexo[20];
	char op[10];
}Entrevistado;

float porcentagemM(Entrevistado * pessoa) {
	int i;
	float m = 0;
	
	for (i = 0; i < 5; i++){
	if (strcmp(pessoa[i].sexo, "masculino") == 0 && strcmp(pessoa[i].op, "nao gostei") == 0) {
		m += 1;
	}
	}
	
	return m*20;
}

float calcula_porcentagemF(Entrevistado * pessoa) {
	int i;
	float f = 0;
	
	for (i = 0; i < 5; i++){
	if (strcmp(pessoa[i].sexo, "feminino") == 0 && strcmp(pessoa[i].op, "gostei") == 0) {
		f += 1;
	} 
	}
	
	return f*20;
}

int main() {
	Entrevistado * pessoa = (Entrevistado *) malloc(5 * sizeof(Entrevistado));
	float pf, pm;
	int i;
	
	for (int i = 0; i < 5; i++) {
        printf("Qual seu genero? \n");
        scanf(" %[^\n]", pessoa[i].sexo);
        printf("\nInforme se gostou ou não do novo produto: \n");
        scanf(" %[^\n]", pessoa[i].op);
    }
	
	pm = porcentagemM(pessoa);
	pf = calcula_porcentagemF(pessoa);
	
	
	
	printf("\nPorcentagem de mulheres que gostaram: %2.f\n", pf);
	printf("Porcentagem de homens que nao gostaram: %2.f\n", pm);
	free(pessoa);
	return 0;
	
}