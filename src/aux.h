#ifndef _AUX_H_
#define _AUX_H_

#include "abb.h"

abb_t *insertar(abb_t *arbol, struct nodo_abb* actual, void * elemento);

struct nodo_abb *buscar(abb_t *arbol, struct nodo_abb* actual, void * elemento);

#endif // _AUX_H_
