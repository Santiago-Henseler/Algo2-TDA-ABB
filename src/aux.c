#include "abb_estructura_privada.h"
#include "aux.h"

abb_t *insertar(abb_t *arbol, struct nodo_abb* actual, void * elemento)
{

	if(arbol->comparador(actual->elemento, elemento) >= 0){
		if(actual->izquierda == NULL){
			actual->izquierda = calloc(1, sizeof(struct nodo_abb *));
			if(actual->izquierda == NULL)
				return NULL;
			actual->izquierda->elemento = elemento;
			arbol->tamanio++;
			return arbol;
		}else{
			return insertar(arbol, actual->izquierda, elemento);
		}
	}

	if(actual->derecha == NULL){
		actual->derecha = calloc(1, sizeof(struct nodo_abb *));
		if(actual->derecha == NULL)
			return NULL;
		actual->derecha->elemento = elemento;
		arbol->tamanio++;
		return arbol;
	}else{
		return insertar(arbol, actual->derecha, elemento);
	}
}

struct nodo_abb *buscar(abb_t *arbol, struct nodo_abb* actual, void * elemento)
{

	if(arbol->comparador(actual->elemento, elemento) == 0){
		return actual;
	}
	else if(arbol->comparador(actual->elemento, elemento) > 0){
		if(actual->izquierda == NULL)
			return NULL;
		return buscar(arbol, actual->izquierda, elemento);
	}

	if(actual->derecha == NULL)
		return NULL;
	return buscar(arbol, actual->derecha, elemento);
}

struct nodo_abb *buscar_anterior(abb_t *arbol, struct nodo_abb* actual, void * elemento)
{

	if(arbol->comparador(actual->elemento, elemento) == 0){
		return actual;
	}
	else if(arbol->comparador(actual->elemento, elemento) > 0){
		if(actual->izquierda == NULL)
			return NULL;
		return buscar(arbol, actual->izquierda, elemento);
	}

	if(actual->derecha == NULL)
		return NULL;
	return buscar(arbol, actual->derecha, elemento);
}

