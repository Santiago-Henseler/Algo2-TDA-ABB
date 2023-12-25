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

//Pre: Recibe un arbol valido y un elemento a insertar
//Post: Devuelve el elemento si lo pudo insertar, sino devuelve NULL
struct nodo_abb *insertar_recursivo(abb_t *arbol, struct nodo_abb *actual,
				    void *elemento, bool *insertado);

//Pre: Recibe un arbol valido y un elemento a buscar
//Post: Devuelve el elemento si se encontro o NULL si no lo encontro
struct nodo_abb *buscar(abb_t *arbol, struct nodo_abb *actual, void *elemento);

//Pre: Recibe una estructura almacenador y un elemento a guardar
//Post: llena la estructura almacenador con el elemento pasado hasta llenar el almacenador
bool aniadir_al_array(void *actual, void *array);

#endif // _FUNCIONALIDADES_H_
