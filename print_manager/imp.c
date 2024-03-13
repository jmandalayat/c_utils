/*
 * Pequeño programa para imprimir a doble cara y con varias páginas por cara
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args){

	// Número de parámetros incorrecto
	if(argc != 4) {
		printf("Modo de uso:");
		printf("\n\timp [primera página] [última página] [páginas por cara]");
		printf("\n");
		exit(1);
	}

	// Se toman los parámetros
	int first_p = atoi(args[1]);
	int last_p = atoi(args[2]);
	int ppp = atoi(args[3]);

	// Número de páginas
	int N = last_p - first_p + 1;

	// Número de caras
	//int n_caras = N / ppp;
	//if(N % ppp != 0) n_caras++;

	// Número de páginas para las caras impares
	int impar_len;

	// Número de páginas para las caras pares
	int par_len;

	// Calculamos la cantidad para cada conjunto
	impar_len = ppp*(N / (2*ppp));
	par_len = ppp*(N / (2*ppp));
	if(N % (2*ppp) <= ppp) impar_len += N % (2*ppp);
	else {
		impar_len += ppp;
		par_len += N % ppp;
	}

	// Vectores con los números de página
	int pares[par_len];
	int impares[impar_len];

	//printf("\n\nDEBUG:\n\timpar_len: %i\n\tpar_len: %i\n\n", impar_len, par_len);

	int i, j, c;

	// Números de página para las caras impares
	c = 0;
	for(i = first_p;i <= last_p;i+=2*ppp) {
		for(j = 0;j < ppp;j++) {
			impares[c] = i+j;
			c++;
		}
	}

	// Números de página para las caras pares
	c = 0;
	for(i = first_p+ppp;i <= last_p;i+=2*ppp) {
		for(j = 0;j < ppp;j++) {
			pares[c] = i+j;
			c++;
		}
	}

	// Mostramos para las caras impares
	printf("\nPáginas a imprimir en las caras impares:\n\t");
	for(i = 0;i < impar_len;i++) printf("%i, ", impares[i]);
	printf("\n");

	// Mostramos para las caras pares
	printf("\nPáginas a imprimir en las caras pares:\n\t");
	for(i = 0;i < par_len;i++) printf("%i, ", pares[i]);
	printf("\n");

	// Mostramos para la primera impresión
	printf("\nPáginas a imprimir en la primera impresión para doble cara (empezando por las caras impares):\n\t");
	for(i = 0;i < impar_len;i++) printf("%i, ", impares[i]);
	printf("\n");

	// Mostramos para la segunda impresión
	int start = par_len - ppp;
	if(impar_len > par_len) {

		int sobran = par_len % ppp;

		printf("\nHabrá un folio excepcional: ");

		if(sobran == 0) {
			printf("Retira el último folio antes de la segunda impresión, la cara par no tiene nada");
		}
		else {
			printf("Imprime las siguientes páginas en la cara par del último folio antes de la segunda impresión, no alcanzó a tener %i páginas en la cara par:\n\t", ppp);
			for(i = par_len-(sobran);i < par_len;i++) printf("%i, ", pares[i]);

			start -= sobran;
		}
	}
	printf("\n");
	printf("\nPáginas a imprimir en la segunda impresión para doble cara (empezando por las caras impares):\n\t");
	for(i = start;i >= 0;i-=ppp) {
		for(j = 0;j < ppp;j++) {
			printf("%i, ", pares[i+j]);
		}
	}
	printf("\n");

	printf("\n");
}
