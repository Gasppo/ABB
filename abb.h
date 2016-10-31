#ifndef ABB_H
#define ABB_H

#include <stdbool.h>
#include <stddef.h>

//Arbol----------------------------------------------------------------------------------
typedef struct abb abb_t;

typedef int (*abb_comparar_clave_t) (const char *, const char *);
typedef void (*abb_destruir_dato_t) (void *);


//Crea el Arbol ABB
abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato);

//Guarda un dato en un arbol a partir de la clave
bool abb_guardar(abb_t *arbol, const char *clave, void *dato);

//Borra un elemento del arbol a partir de la clave
void *abb_borrar(abb_t *arbol, const char *clave);

//Obtiene un elemento del arbol a partir de la clave
void *abb_obtener(const abb_t *arbol, const char *clave);

//Determina si un elemento pertenece al arbol a partir de la clave
bool abb_pertenece(const abb_t *arbol, const char *clave);

//Devuelve la cantidad de elementos del arbol
size_t abb_cantidad(abb_t *arbol);

//Destruye el arbol
void abb_destruir(abb_t *arbol);

//Iterador interno-----------------------------------------------------------------------

//Itera el arbol a partir de una funcion visitar de la manera inorder
void abb_in_order(abb_t *arbol, bool visitar(const char *, void *, void *), void *extra);

//Iterador externo-----------------------------------------------------------------------

typedef struct abb_iter abb_iter_t;

//Crea el iterador
abb_iter_t *abb_iter_in_crear(const abb_t *arbol);

//Avanza el iterador
bool abb_iter_in_avanzar(abb_iter_t *iter);

//Ve la clave del elemento donde se encuentra el iter
const char *abb_iter_in_ver_actual(const abb_iter_t *iter);

//Determina si el iterador se encuentra al final
bool abb_iter_in_al_final(const abb_iter_t *iter);

//Destruye el iterador
void abb_iter_in_destruir(abb_iter_t* iter);

#endif // ABB_H
