#include "recorridos.h"

bool recorrido_iterativo_preorden(struct nodo_abb *actual,
				  bool (*funcion)(void *, void *), void *aux,
				  size_t *recorridos, size_t maximo)
{
	if (*recorridos == maximo)
		return false;

	if (actual == NULL)
		return true;

	(*recorridos)++;

	if (funcion(actual->elemento, aux) == false)
		return false;

	if (recorrido_iterativo_preorden(actual->izquierda, funcion, aux,
					 recorridos, maximo) == false)
		return false;

	return recorrido_iterativo_preorden(actual->derecha, funcion, aux,
					    recorridos, maximo);
}

bool recorrido_iterativo_inorden(struct nodo_abb *actual,
				 bool (*funcion)(void *, void *), void *aux,
				 size_t *recorridos, size_t maximo)
{
	if (*recorridos == maximo)
		return false;

	if (actual == NULL)
		return true;

	if (recorrido_iterativo_inorden(actual->izquierda, funcion, aux,
					recorridos, maximo) == false)
		return false;

	(*recorridos)++;

	if (funcion(actual->elemento, aux) == false)
		return false;

	return recorrido_iterativo_inorden(actual->derecha, funcion, aux,
					   recorridos, maximo);
}

bool recorrido_iterativo_postorden(struct nodo_abb *actual,
				   bool (*funcion)(void *, void *), void *aux,
				   size_t *recorridos, size_t maximo)
{
	if (*recorridos == maximo)
		return false;

	if (actual == NULL)
		return true;

	if (recorrido_iterativo_postorden(actual->izquierda, funcion, aux,
					  recorridos, maximo) == false)
		return false;

	if (recorrido_iterativo_postorden(actual->derecha, funcion, aux,
					  recorridos, maximo) == false)
		return false;

	(*recorridos)++;

	return funcion(actual->elemento, aux);
}
