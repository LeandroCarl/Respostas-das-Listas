# include <stdio.h>
	int main () {
	int i ;
	for ( i =1 ; i <= 100 ; i *=100) {
	if ( i == 30 ) {
	break;
}
	else {
	printf ("%2d\n" ,2* i ) ;
}
}
	printf ("Fim do laco !\n") ;
	return 0;
	
	//O programa tem a função imprimir o dobro do valor de i
	//A saída do programa será 2 e 200
}