#ifndef _AUX_H_
#define _AUX_H_

#include "abb.h"
#include "abb_estructura_privada.h"

typedef struct almacenador{
    void** elementos;
    size_t cantidad;
    size_t total;
}almacenador_t;

struct nodo_abb *insertar_recursivo(abb_t *arbol, struct nodo_abb* actual, void * elemento, bool *insertado);

struct nodo_abb *buscar(abb_t *arbol, struct nodo_abb* actual, void * elemento);

void destruir_todo_iterativa(struct nodo_abb* actual, void (*destructor)(void *));

bool aniadir_al_array(void *actual, void* array);

struct nodo_abb *quitar_recursivo(abb_t *arbol, void *elemento, struct nodo_abb* actual, almacenador_t * encontrado);

#endif // _AUX_H_
