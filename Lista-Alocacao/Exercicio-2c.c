#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char r[10];
    float nota;
} Aluno;

float calcula_nota(Aluno *a, char *gabarito, int Nq, int i) {
    int j;
    float n = 0;

    for (j = 0; j < Nq; j++) {
        if (gabarito[j] == a[i].r[j]) {
            n += 10.0 / Nq;
        }
    }

    return n;
}

float porcentagem(Aluno * a){
	int i;
	float p = 0;
	for (i = 0; i < 10; i++) {
		if(a[i].nota >= 6) {
			p += 1;
		}
	}
	
	return p*10;
}

int main() {
    int Nq, i, j;
	
    printf("Informe o numero de questoes: ");
    scanf("%d", &Nq);

    char *gabarito = (char *)malloc(Nq * sizeof(char));

    printf("\nDigite o gabarito: ");
    for (i = 0; i < Nq; i++) {
        scanf(" %c", &gabarito[i]);
    }

    Aluno *a = (Aluno *)malloc(10 * sizeof(Aluno));

    for (i = 0; i < 10; i++) {
        printf("Preencha o gabarito do aluno %d: ", i + 1);
        for (j = 0; j < Nq; j++) {
            scanf(" %c", &a[i].r[j]);
        }
        printf("\n");
    }

    printf("Notas dos alunos:\n");
    for (i = 0; i < 10; i++) {
        a[i].nota = calcula_nota(a, gabarito, Nq, i);
        printf("Nota do aluno %d: %.2f\n", i + 1, a[i].nota);
    }

	float P = porcentagem(a);
	printf("Porcentagem de aprovacao: %.2f%%\n", P);
    free(gabarito);
    free(a);

    return 0;
}
