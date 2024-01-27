#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float base;
    float altura;
} Ret;

typedef struct {
    float raio;
} Circ;


Ret* ret_circunscrito(Circ* c, float h) {
    
    float lado = c->raio * 2;

    
    if (h >= lado) {
        printf("Altura fornecida é maior ou igual ao diâmetro do círculo. Nenhum retângulo circunscrito criado.\n");
        return NULL;
    }

    
    Ret* retanguloCircunscrito = (Ret*)malloc(sizeof(Ret));
    retanguloCircunscrito->base = lado;
    retanguloCircunscrito->altura = h;

    return retanguloCircunscrito;
}


Circ* circ_interno(Ret* r) {
    
    float raio = (r->base < r->altura) ? r->base / 2 : r->altura / 2;

    
    Circ* circuloInterno = (Circ*)malloc(sizeof(Circ));
    circuloInterno->raio = raio;

    return circuloInterno;
}

int main() {
    
    Circ c;
    c.raio = 10;

    Ret* retanguloC = ret_circunscrito(&c, 6.0);

    if (retanguloC != NULL) {
        printf("Retangulo circunscrito: Base = %.2f, Altura = %.2f\n", retanguloC->base, retanguloC->altura);
        free(retanguloC);
    }

    Ret retangulo;
    retangulo.base = 8.0;
    retangulo.altura = 6.0;

    Circ* circuloInterno = circ_interno(&retangulo);

    printf("Circulo interno: Raio = %.2f\n", circuloInterno->raio);

    free(circuloInterno);

    return 0;
}
