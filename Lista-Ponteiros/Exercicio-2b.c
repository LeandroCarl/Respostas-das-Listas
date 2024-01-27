#include <stdio.h>


int main(void) {
	int x, *p;
	x = 100;
	p = x;
	printf(“Valor de p = %p\tValor de *p = %d”, p, *p);
	
	//a) o programa, conforme escrito acima, irá exibir uma mensagem de erro
	//b) a mensagem é emitida uma vez que houve um erro na atribuição de valor à variável p, já que, por ser ponteiro, era esperado um endereço e não um valor inteiro
	//c) Não houve sucesso na compilação do programa
	//d) Para funcionar, basta colocar um "&" antes da variável x na linha 7
	//e) Ao fazer as alterações, o programa funcionou perfeitamente 
}
