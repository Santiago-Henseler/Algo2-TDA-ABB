#ifndef _BORRADOR_H_
#define _BORRADOR_H_

#include "funcionalidades.h"

void destruir_todo_iterativa(struct nodo_abb *actual,
			     void (*destructor)(void *));

struct nodo_abb *quitar_recursivo(abb_t *arbol, void *elemento,
				  struct nodo_abb *actual,
				  almacenador_t *encontrado);

#endif // _BORRADOR_H_