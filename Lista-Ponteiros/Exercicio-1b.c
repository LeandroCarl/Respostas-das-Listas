#include <stdio.h>

int main() {
	int x, y, *p;
y = 0;
p = &y;
x = *p;
x = 4;
(*p)++;
--x;
(*p) += x;

printf("%d %d %p", x , y, p);
}

//Os valores finais de x e y serão respectivamente, 3 e 4, enquanto p contém o endereço de y