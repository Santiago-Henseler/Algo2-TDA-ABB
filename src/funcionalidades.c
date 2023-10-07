#include "funcionalidades.h"

struct nodo_abb *insertar_recursivo(abb_t *arbol, struct nodo_abb *actual,
				    void *elemento, bool *insertado)
{
	if (actual == NULL) {
		struct nodo_abb *nuevo_nodo =
			calloc(1, sizeof(struct nodo_abb));
		if (nuevo_nodo == NULL)
			return NULL;
		*insertado = true;
		nuevo_nodo->elemento = elemento;
		arbol->tamanio++;
		return nuevo_nodo;
	}

	int comparador = arbol->comparador(actual->elemento, elemento);

	if (comparador >= 0) {
		actual->izquierda = insertar_recursivo(arbol, actual->izquierda,
						       elemento, insertado);
	} else {
		actual->derecha = insertar_recursivo(arbol, actual->derecha,
						     elemento, insertado);
	}

	return actual;
}

struct nodo_abb *buscar(abb_t *arbol, struct nodo_abb *actual, void *elemento)
{
	if (arbol->comparador(actual->elemento, elemento) == 0) {
		return actual;
	} else if (arbol->comparador(actual->elemento, elemento) > 0) {
		if (actual->izquierda == NULL)
			return NULL;
		return buscar(arbol, actual->izquierda, elemento);
	}

	if (actual->derecha == NULL)
		return NULL;
	return buscar(arbol, actual->derecha, elemento);
}

bool aniadir_al_array(void *actual, void *array)
{
	almacenador_t *almacenador = array;

	if (almacenador->cantidad == almacenador->total)
		return false;

	almacenador->elementos[almacenador->cantidad] = actual;

	almacenador->cantidad++;

	return true;
}