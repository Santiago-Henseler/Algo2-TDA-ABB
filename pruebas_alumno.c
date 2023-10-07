#include "pa2m.h"
#include "src/abb.h"
#include "src/abb_estructura_privada.h"

int comparador(void *primero, void *segundo)
{
	int *uno = primero;
	int *dos = segundo;

	return (int)(uno - dos);
}

//crear
void creoUnArbolConComparadorNoNuloYSeCrea()
{
	abb_t *arbol = abb_crear(comparador);
	pa2m_afirmar(arbol != NULL, "Se crea un arbol correctamente");
	abb_destruir(arbol);
}

void creoUnArbolConComparadorNuloYNoSeCrea()
{
	abb_t *arbol = abb_crear(NULL);
	pa2m_afirmar(
		arbol == NULL,
		"No se crea un arbol correctamente sin funcion comparadora");
}

void creoUnArbolYEstaVacio()
{
	abb_t *arbol = abb_crear(comparador);
	pa2m_afirmar(abb_vacio(arbol), "Se crea un arbol vacio");
	abb_destruir(arbol);
}

//buscar
void BuscoUnElementoValido()
{
	abb_t *arbol = abb_crear(comparador);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[1]);

	pa2m_afirmar(abb_buscar(arbol, &num[1]) == &num[1],
		     "Se encuentra un elemento valido");
	abb_destruir(arbol);
}

void BuscoUnElementoInexistente()
{
	abb_t *arbol = abb_crear(comparador);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[1]);

	pa2m_afirmar(abb_buscar(arbol, &num[9]) == NULL,
		     "No se encuentra un elemento inexistente");
	abb_destruir(arbol);
}

void BuscoUnElementoEnArbolInexistente()
{
	abb_t *arbol = abb_crear(NULL);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[1]);

	pa2m_afirmar(abb_buscar(arbol, &num[1]) == NULL,
		     "No busco en un arbol inexistente");
}

//insertar
void InsertoEnUnArbolValido()
{
	abb_t *arbol = abb_crear(comparador);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[1]);

	pa2m_afirmar(abb_buscar(arbol, &num[1]) == &num[1],
		     "Se inserta 1 elemento correctamente");

	abb_insertar(arbol, &num[3]);
	abb_insertar(arbol, &num[4]);
	abb_insertar(arbol, &num[5]);
	abb_insertar(arbol, &num[6]);

	pa2m_afirmar(abb_buscar(arbol, &num[3]) == &num[3] &&
			     abb_buscar(arbol, &num[4]) == &num[4] &&
			     abb_buscar(arbol, &num[5]) == &num[5] &&
			     abb_buscar(arbol, &num[6]) == &num[6],
		     "Se inserta varios elementos correctamente");
	abb_destruir(arbol);
}

void InsertoEnUnArbolNoValido()
{
	abb_t *arbol = abb_crear(NULL);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[1]);

	pa2m_afirmar(abb_buscar(arbol, &num[1]) == NULL,
		     "No se inserta 1 elemento en un arbol invalido");

	abb_insertar(arbol, &num[3]);
	abb_insertar(arbol, &num[4]);
	abb_insertar(arbol, &num[5]);
	abb_insertar(arbol, &num[6]);

	pa2m_afirmar(
		abb_buscar(arbol, &num[3]) == NULL &&
			abb_buscar(arbol, &num[4]) == NULL &&
			abb_buscar(arbol, &num[5]) == NULL &&
			abb_buscar(arbol, &num[6]) == NULL,
		"No se insertan varios elementos elemento en un arbol invalido");
}

/*
void a(){
	abb_t *arbol = abb_crear(comparador);

	int num[] = {0,1,2,3,4,5,6,7,8,9};

	abb_insertar(arbol, &num[5]);
	abb_insertar(arbol, &num[1]);
	abb_insertar(arbol, &num[0]);
	abb_insertar(arbol, &num[2]);
	abb_insertar(arbol, &num[4]);
	abb_insertar(arbol, &num[6]);
	abb_insertar(arbol, &num[8]);
	abb_insertar(arbol, &num[9]);
	abb_insertar(arbol, &num[7]);
	
	void *array[20];

	int a = (int)abb_recorrer(arbol, INORDEN, array, 20);

	for(int i = 0; i < a; i++){
		printf("|");
		printf("%i", *(int*)array[i]);
	}

	printf("\n");

	int quit = *(int*)abb_quitar(arbol, &num[8]);

	printf("%i", quit);
	printf("\n");

	void *array2[20];

	int b = (int)abb_recorrer(arbol, INORDEN, array2, 20);

	for(int i = 0; i < b; i++){
		printf("|");
		printf("%i", *(int*)array2[i]);
	}
}
*/
//funciones
void EstaVacioArbolValido()
{
	abb_t *arbol = abb_crear(comparador);

	pa2m_afirmar(abb_vacio(arbol), "El arbol esta vacio");

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[1]);
	abb_insertar(arbol, &num[6]);

	pa2m_afirmar(!abb_vacio(arbol),
		     "Se agregan elementos y el arbol no esta vacio");
	abb_destruir(arbol);
}

void EstaVacioArbolInvalido()
{
	abb_t *arbol = abb_crear(NULL);

	pa2m_afirmar(abb_vacio(arbol), "El arbol no valido es vacio");

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[1]);
	abb_insertar(arbol, &num[6]);

	pa2m_afirmar(abb_vacio(arbol),
		     "Se agregan elementos y el arbol no valido sigue vacio");
}

void TamanioCorrecto()
{
	abb_t *arbol = abb_crear(comparador);

	pa2m_afirmar(abb_tamanio(arbol) == 0, "El arbol vacio tiene tamañio 0");

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[1]);
	abb_insertar(arbol, &num[6]);

	pa2m_afirmar(abb_tamanio(arbol) == 2,
		     "Se agregan elementos y el arbol tiene tamaño correcto");
	abb_destruir(arbol);
}

void TamanioorrectoArbolInvalido()
{
	abb_t *arbol = abb_crear(NULL);

	pa2m_afirmar(abb_tamanio(arbol) == 0,
		     "Un arbol invalido tiene tamañio 0");

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[1]);
	abb_insertar(arbol, &num[6]);

	pa2m_afirmar(
		abb_tamanio(arbol) == 0,
		"Se agregan elementos y el arbol invalido tiene tamañio 0");
}

int main()
{
	
	pa2m_nuevo_grupo(
		"\n======================== CREAR ARBOL ========================");
	creoUnArbolConComparadorNoNuloYSeCrea();
	creoUnArbolConComparadorNuloYNoSeCrea();
	creoUnArbolYEstaVacio();

	pa2m_nuevo_grupo(
		"\n======================== PRUEBAS BUSCAR ========================");
	BuscoUnElementoValido();
	BuscoUnElementoInexistente();
	BuscoUnElementoEnArbolInexistente();

	pa2m_nuevo_grupo(
		"\n======================== PRUEBAS INSERTAR ========================");
	InsertoEnUnArbolValido();
	InsertoEnUnArbolNoValido();

	pa2m_nuevo_grupo(
		"\n======================== PRUEBAS FUNCIONES ========================");
	EstaVacioArbolValido();
	EstaVacioArbolInvalido();
	TamanioCorrecto();
	TamanioorrectoArbolInvalido();

	return pa2m_mostrar_reporte();
}
