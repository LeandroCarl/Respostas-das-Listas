#include <stdio.h>

int Soma(int a, int b){
	int s, n;
	s = 0;
	for (n = a + 1; n < b; n++) {
		s += n;
	}
	return s;
}

int main() {
	int a, b;
	a = 5;
	b = 10;
	int resultado;
	resultado = Soma(a, b);
	
	printf("Soma dos numeros entre %d e %d: %d", a, b, resultado);
}