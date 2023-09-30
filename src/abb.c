#include "abb.h"
#include "abb_estructura_privada.h"
#include <stddef.h>
#include <stdlib.h>

#include "aux.h"

abb_t *abb_crear(abb_comparador comparador)
{
	if(comparador == NULL)
		return NULL;
	
	struct abb *arbol = calloc(1, sizeof(struct abb ));

	if(arbol == NULL)
		return NULL;

	arbol->comparador = comparador;

	return arbol;
}

abb_t *abb_insertar(abb_t *arbol, void *elemento)
{
	if(arbol == NULL)
		return NULL;

	if(abb_tamanio(arbol) == 0){
		struct nodo_abb *raiz = calloc(1, sizeof(struct nodo_abb ));

		if(raiz == NULL)
			return NULL;

		arbol->nodo_raiz = raiz; 
		arbol->nodo_raiz->elemento = elemento;
		arbol->tamanio++;
		return arbol;
	}

	return insertar(arbol, arbol->nodo_raiz, elemento);
}

void *abb_quitar(abb_t *arbol, void *elemento)
{
	return elemento;
}

void *abb_buscar(abb_t *arbol, void *elemento)
{
	if(abb_vacio(arbol))
		return NULL;

	return buscar(arbol, arbol->nodo_raiz, elemento);
}

bool abb_vacio(abb_t *arbol)
{
	if(arbol == NULL)
		return true;
	
	if(arbol->tamanio == 0)
		return true;

	return false;
}

size_t abb_tamanio(abb_t *arbol)
{
	if(arbol == NULL)
		return 0;

	return arbol->tamanio;
}

void abb_destruir(abb_t *arbol)
{
}

void abb_destruir_todo(abb_t *arbol, void (*destructor)(void *))
{
}

size_t abb_con_cada_elemento(abb_t *arbol, abb_recorrido recorrido,
			     bool (*funcion)(void *, void *), void *aux)
{
	return 0;
}

size_t abb_recorrer(abb_t *arbol, abb_recorrido recorrido, void **array, size_t tamanio_array)
{
	return 0;
}
