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

void BuscoUnElementoQuitado()
{
	abb_t *arbol = abb_crear(comparador);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[5]);
	abb_insertar(arbol, &num[1]);
	abb_insertar(arbol, &num[0]);
	abb_insertar(arbol, &num[2]);
	abb_insertar(arbol, &num[4]);
	abb_insertar(arbol, &num[6]);
	abb_insertar(arbol, &num[8]);
	abb_insertar(arbol, &num[9]);
	abb_insertar(arbol, &num[7]);

	abb_quitar(arbol, &num[2]);

	pa2m_afirmar(
		abb_buscar(arbol, &num[2]) == NULL,
		"No se puede buscar un elemento que ya no esta en el arbol");

	abb_destruir(arbol);
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

//quitar
void TratoDeQuitarEnUnArbolNoValido()
{
	abb_t *arbol = abb_crear(NULL);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	void *quitado = abb_quitar(arbol, &num[5]);

	pa2m_afirmar(quitado == NULL, "No se puede quitar de un arbol nulo");

	abb_destruir(arbol);
}

void QuitoLaRaizDeUnArbolValidoYSeAcomodaBien()
{
	abb_t *arbol = abb_crear(comparador);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[5]);
	abb_insertar(arbol, &num[1]);
	abb_insertar(arbol, &num[0]);
	abb_insertar(arbol, &num[2]);
	abb_insertar(arbol, &num[4]);
	abb_insertar(arbol, &num[6]);
	abb_insertar(arbol, &num[8]);
	abb_insertar(arbol, &num[9]);
	abb_insertar(arbol, &num[7]);

	abb_quitar(arbol, &num[5]);

	pa2m_afirmar(*(int *)arbol->nodo_raiz->elemento == num[4],
		     "Quito la raiz y se acomoda bien el arbol");

	abb_quitar(arbol, &num[4]);

	pa2m_afirmar(*(int *)arbol->nodo_raiz->elemento == num[2],
		     "Quito otra vez la raiz y se acomoda bien el arbol");

	abb_quitar(arbol, &num[2]);
	abb_quitar(arbol, &num[1]);
	abb_quitar(arbol, &num[0]);
	abb_quitar(arbol, &num[6]);
	abb_quitar(arbol, &num[8]);

	pa2m_afirmar(*(int *)arbol->nodo_raiz->elemento == num[7],
		     "Quito muchas veces la raiz y se acomoda bien el arbol");

	pa2m_afirmar(
		abb_tamanio(arbol) == 2,
		"Quito muchas veces un elemento y se achica el arbol bien");

	abb_quitar(arbol, &num[7]);
	abb_quitar(arbol, &num[9]);

	pa2m_afirmar(abb_tamanio(arbol) == 0,
		     "Quito todo el arbol y queda vacio");

	abb_destruir(arbol);
}

void QuitoUnValorInexistenteDevuelveNULL()
{
	abb_t *arbol = abb_crear(comparador);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[5]);
	abb_insertar(arbol, &num[1]);
	abb_insertar(arbol, &num[0]);
	abb_insertar(arbol, &num[2]);
	abb_insertar(arbol, &num[4]);
	abb_insertar(arbol, &num[6]);
	abb_insertar(arbol, &num[8]);
	abb_insertar(arbol, &num[9]);
	abb_insertar(arbol, &num[7]);

	void *quitado = abb_quitar(arbol, &num[3]);

	pa2m_afirmar(quitado == NULL,
		     "No se puede quitar un elemento inexistente del arbol");

	abb_destruir(arbol);
}

void QuitoUnElementoConUnHijo()
{
	abb_t *arbol = abb_crear(comparador);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[5]);
	abb_insertar(arbol, &num[1]);

	abb_quitar(arbol, &num[5]);

	pa2m_afirmar(
		arbol->nodo_raiz->elemento == &num[1],
		"Se quita un elemento con un hijo y el arbol se acomoda bien");

	abb_destruir(arbol);
}

//recorridos
void RecorroLosElementos()
{
	abb_t *arbol = abb_crear(comparador);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[5]);
	abb_insertar(arbol, &num[1]);
	abb_insertar(arbol, &num[0]);
	abb_insertar(arbol, &num[2]);
	abb_insertar(arbol, &num[4]);
	abb_insertar(arbol, &num[6]);
	abb_insertar(arbol, &num[8]);
	abb_insertar(arbol, &num[9]);
	abb_insertar(arbol, &num[7]);

	void *array[abb_tamanio(arbol)];

	pa2m_afirmar((int)abb_recorrer(arbol, INORDEN, array,
				       abb_tamanio(arbol)) ==
			     abb_tamanio(arbol),
		     "Se recorre todo el arbol");

	void *array2[2];

	pa2m_afirmar((int)abb_recorrer(arbol, INORDEN, array2, 2) == 2,
		     "Se recorre una parte del arbol");

	abb_destruir(arbol);
}

void NoRecorroUnArbolVacio()
{
	abb_t *arbol = abb_crear(NULL);

	void *array[10];

	pa2m_afirmar((int)abb_recorrer(arbol, INORDEN, array, 10) == 0,
		     "No se recorre un  arbol vacio");

	abb_destruir(arbol);
}

void RecorroLosElementosConOrden()
{
	abb_t *arbol = abb_crear(comparador);

	int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	abb_insertar(arbol, &num[5]);
	abb_insertar(arbol, &num[1]);
	abb_insertar(arbol, &num[0]);
	abb_insertar(arbol, &num[2]);
	abb_insertar(arbol, &num[4]);
	abb_insertar(arbol, &num[6]);
	abb_insertar(arbol, &num[8]);
	abb_insertar(arbol, &num[9]);
	abb_insertar(arbol, &num[7]);
	abb_insertar(arbol, &num[3]);

	void *array[abb_tamanio(arbol)];

	abb_recorrer(arbol, INORDEN, array, abb_tamanio(arbol));

	bool bien_recorrido_inorder = true;

	for (int i = 0; i < abb_tamanio(arbol); i++) {
		if (*(int *)array[i] != num[i])
			bien_recorrido_inorder = false;
	}

	pa2m_afirmar(bien_recorrido_inorder,
		     "Se recorre bien de manera inorder el arbol");

	int num_pre[] = { 5, 1, 0, 2, 4, 3, 6, 8, 7, 9 };

	void *array2[abb_tamanio(arbol)];

	bool bien_recorrido_preorden = true;

	abb_recorrer(arbol, PREORDEN, array2, abb_tamanio(arbol));

	for (int i = 0; i < abb_tamanio(arbol); i++) {
		if (*(int *)array2[i] != num_pre[i])
			bien_recorrido_preorden = false;
	}

	pa2m_afirmar(bien_recorrido_preorden,
		     "Se recorre bien de manera preorden el arbol");

	int num_post[] = { 0, 3, 4, 2, 1, 7, 9, 8, 6, 5 };

	void *array3[abb_tamanio(arbol)];

	bool bien_recorrido_postorden = true;

	abb_recorrer(arbol, POSTORDEN, array3, abb_tamanio(arbol));

	for (int i = 0; i < abb_tamanio(arbol); i++) {
		if (*(int *)array3[i] != num_post[i])
			bien_recorrido_postorden = false;
	}

	pa2m_afirmar(bien_recorrido_postorden,
		     "Se recorre bien de manera postorden el arbol");

	abb_destruir(arbol);
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
	BuscoUnElementoQuitado();

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

	pa2m_nuevo_grupo(
		"\n======================== PRUEBAS QUITAR ========================");
	QuitoLaRaizDeUnArbolValidoYSeAcomodaBien();
	TratoDeQuitarEnUnArbolNoValido();
	QuitoUnValorInexistenteDevuelveNULL();
	QuitoUnElementoConUnHijo();

	pa2m_nuevo_grupo(
		"\n======================== PRUEBAS RECORRER ========================");
	RecorroLosElementos();
	NoRecorroUnArbolVacio();
	RecorroLosElementosConOrden();

	return pa2m_mostrar_reporte();
}