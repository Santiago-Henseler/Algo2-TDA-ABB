#ifndef _BORRADOR_H_
#define _BORRADOR_H_

#include "funcionalidades.h"

//Pre: Recibe un nodo valido
//Post:	Si el destructor es valido borra todos los nodos aplicandole el iterador, sino simplemente borra los nodos
void destruir_todo_iterativa(struct nodo_abb *actual,
			     void (*destructor)(void *));

//Pre: Recibe un arbol y un nodo valido, un elemento a buscar y un alamcenador
//Post: Si se encuentra el elemento lo borra, reacomoda el arbol y devuelve el elemento. Si no devuelve NULL.
struct nodo_abb *quitar_recursivo(abb_t *arbol, void *elemento,
				  struct nodo_abb *actual,
				  almacenador_t *encontrado);

#endif // _BORRADOR_H_
