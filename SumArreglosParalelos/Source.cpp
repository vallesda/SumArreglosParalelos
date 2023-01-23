// Se crea y configura el proyecto; visual studio 2022 por default habilita openMP
// Se importan las librerias
#include <iostream>
#include <omp.h>
using namespace std;


// define el tamano del arreglo
#define N 1000

#define chunk 100
// variable para mostrar los primeros N numeros
#define mostrar 10


// funcion para imprimir arreglo
void imprimeArreglo(float* d) {
	for (int x = 0; x < mostrar; x++) {
		cout << d[x] << " -";
	}
	cout << endl;
}

int main()
{
	cout << "Sumando Arrgelos variables de 1 - 100 \n";

	float a[N], b[N], c[N];
	int i;

	for (i = 0; i < N; i++) {
		a[i] = rand() % 100 + 1;
		b[i] = rand() % 100 + 1;
	}

	// region paralela
	int pedazos = chunk;
	#pragma omp parallel for \
	shared(a, b, c, pedazos) private(i) \
	schedule(static, pedazos)

	for (i = 0; i < N; i++) {
		c[i] = a[i] + b[i];
	}

	cout << " Imprime los primeros" << mostrar << " valores del arreglo A: " << endl;
	imprimeArreglo(a);
	cout << " Imprime los primeros" << mostrar << " valores del arreglo B: " << endl;
	imprimeArreglo(b);
	cout << " Imprime los primeros" << mostrar << " valores del arreglo C: " << endl;
	imprimeArreglo(c);
}