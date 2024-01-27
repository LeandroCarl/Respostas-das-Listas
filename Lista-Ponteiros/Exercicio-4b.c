#include <stdio.h>
#include <math.h>

void calcula_hexagono(double l, double *area, double *perimetro){
    *perimetro = 6 * l;
    *area = (3 * pow(l, 2) * sqrt(3)) / 2;
}

int main(){
    double l = 3;
    double area, perimetro;
    
    calcula_hexagono(l, &area, &perimetro);
    
    printf("Lado: %.0lf\nArea: %.2lf\nPerimetro: %.2lf", l, area, perimetro);
    
    return 0;
}
