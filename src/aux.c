#include "aux.h"

struct nodo_abb *insertar_recursivo(abb_t *arbol, struct nodo_abb* actual, void * elemento, bool *insertado)
{
	if(actual == NULL){
		actual = calloc(1, sizeof(struct nodo_abb ));
		if(actual == NULL)
			return NULL;
		*insertado = true;
		actual->elemento = elemento;
		arbol->tamanio++;
		return actual;
	}

	int comparador = arbol->comparador(actual->elemento, elemento);

	if(comparador >= 0){
		actual->izquierda = insertar_recursivo(arbol, actual->izquierda, elemento, insertado);
	}else{
		actual->derecha = insertar_recursivo(arbol, actual->derecha, elemento, insertado);
	}

	return actual;
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

void destruir_iterativa(struct nodo_abb* actual){
	if(actual == NULL)
		return;
	destruir_iterativa(actual->izquierda);
	destruir_iterativa(actual->derecha);
	free(actual);
}

void destruir_todo_iterativa(struct nodo_abb* actual, void (*destructor)(void *)){
	if(actual == NULL)
		return;
	destructor(actual->elemento);
	destruir_todo_iterativa(actual->izquierda, destructor);
	destruir_todo_iterativa(actual->derecha, destructor);
	free(actual);
}

bool aniadir_al_array(void *actual, void* array){

	almacenador_t *almacenador = array;

	if(almacenador->cantidad == almacenador->total)
		return false;

	almacenador->elementos[almacenador->cantidad] = actual;

	almacenador->cantidad++;

	return true;
}

struct nodo_abb * padre_predecesor_inorder(struct nodo_abb* actual){
	if(actual->derecha->derecha == NULL)
		return actual;
	return padre_predecesor_inorder(actual->derecha);
}

struct nodo_abb *reacomodar_al_quitar(abb_t *arbol, struct nodo_abb* actual){
	if(actual->izquierda == NULL && actual->derecha == NULL){	
		return NULL;
	}
	if(actual->izquierda == NULL){
		return actual->derecha;
	}
	if(actual->derecha == NULL){
		return actual->izquierda;
	}
	else{
		/*
		struct nodo_abb* padre_predecesor = padre_predecesor_inorder(actual->izquierda);
		struct nodo_abb* predecesor = padre_predecesor->derecha;
		padre_predecesor->derecha = NULL;
		padre_predecesor->izquierda = predecesor->izquierda;

		actual->elemento = predecesor->elemento;*/
		return actual;
	}
	return actual;
}

struct nodo_abb *quitar_recursivo(abb_t *arbol, void *elemento, struct nodo_abb* actual, almacenador_t * encontrado){

	if(actual == NULL){
		encontrado->elementos = NULL;
		return NULL;
	}

	if(arbol->tamanio == 1){
		encontrado->elementos = actual->elemento;
		return NULL;
	}

	int comparador = arbol->comparador(actual->elemento, elemento);

	if(comparador == 0){
		encontrado->elementos = actual->elemento;
		return reacomodar_al_quitar(arbol, actual);
	}
	if(comparador > 0){
		actual->izquierda = quitar_recursivo(arbol, elemento, actual->izquierda, encontrado);
	}else{
		actual->derecha = quitar_recursivo(arbol, elemento, actual->derecha, encontrado);
	}

	return actual;
}