#ifndef _RECORRIDOS_H_
#define _RECORRIDOS_H_

#include "abb.h"
#include "abb_estructura_privada.h"

bool recorrido_iterativo_preorden(struct nodo_abb *actual,
				  bool (*funcion)(void *, void *), void *aux,
				  size_t *recorridos, size_t maximo);

bool recorrido_iterativo_inorden(struct nodo_abb *actual,
				 bool (*funcion)(void *, void *), void *aux,
				 size_t *recorridos, size_t maximo);

bool recorrido_iterativo_postorden(struct nodo_abb *actual,
				   bool (*funcion)(void *, void *), void *aux,
				   size_t *recorridos, size_t maximo);

#endif // _RECORRIDOS_H_
