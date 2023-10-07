#ifndef _FUNCIONALIDADES_H_
#define _FUNCIONALIDADES_H_

#include <stddef.h>
#include <stdlib.h>

#include "abb.h"
#include "abb_estructura_privada.h"

typedef struct almacenador {
	void **elementos;
	size_t cantidad;
	size_t total;
} almacenador_t;

struct nodo_abb *insertar_recursivo(abb_t *arbol, struct nodo_abb *actual,
				    void *elemento, bool *insertado);

struct nodo_abb *buscar(abb_t *arbol, struct nodo_abb *actual, void *elemento);

bool aniadir_al_array(void *actual, void *array);

#endif // _FUNCIONALIDADES_H_
