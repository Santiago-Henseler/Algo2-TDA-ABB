#include "borrador.h"

struct nodo_abb * padre_predecesor_inorder(struct nodo_abb* actual){
	if(actual->derecha->derecha == NULL)
		return actual;
	return padre_predecesor_inorder(actual->derecha);
}

struct nodo_abb *reacomodar_al_quitar(abb_t *arbol, struct nodo_abb* actual){
	if(actual->izquierda == NULL && actual->derecha == NULL){	
		free(actual);
		return NULL;
	}
	if(actual->izquierda == NULL){
		struct nodo_abb * aux = actual->derecha;
		free(actual);
		return aux;
	}
	if(actual->derecha == NULL){
		struct nodo_abb * aux = actual->izquierda;
		free(actual);
		return aux;
	}
	else{
		if(actual->izquierda->derecha == NULL){
			actual->elemento = actual->izquierda->elemento;
			struct nodo_abb* aux = actual->izquierda;
			actual->izquierda = actual->izquierda->izquierda;
			free(aux);
			return actual;
		}
		struct nodo_abb* padre_predecesor = padre_predecesor_inorder(actual->izquierda);
		struct nodo_abb* predecesor = padre_predecesor->derecha;
		padre_predecesor->derecha = predecesor->izquierda;

		actual->elemento = predecesor->elemento;
		free(predecesor);
		return actual;
	}
	return actual;
}

struct nodo_abb *quitar_recursivo(abb_t *arbol, void *elemento, struct nodo_abb* actual, almacenador_t * almacenador){

	if(actual == NULL){
		almacenador->elementos = NULL;
		return NULL;
	}

	int comparador = arbol->comparador(actual->elemento, elemento);

	if(comparador == 0){
		if(arbol->tamanio == 1){
			almacenador->elementos = actual->elemento;
			almacenador->total = 1;
			free(actual);
			
			return NULL;
		}
		almacenador->elementos = actual->elemento;
		almacenador->total = 1;
		return reacomodar_al_quitar(arbol, actual);
	}
	if(comparador > 0){
		actual->izquierda = quitar_recursivo(arbol, elemento, actual->izquierda, almacenador);
	}else{
		actual->derecha = quitar_recursivo(arbol, elemento, actual->derecha, almacenador);
	}

	return actual;
}

void destruir_todo_iterativa(struct nodo_abb* actual, void (*destructor)(void *)){
	if(actual == NULL)
		return;
    if(destructor != NULL)
	    destructor(actual->elemento);
	destruir_todo_iterativa(actual->izquierda, destructor);
	destruir_todo_iterativa(actual->derecha, destructor);
	free(actual);
}