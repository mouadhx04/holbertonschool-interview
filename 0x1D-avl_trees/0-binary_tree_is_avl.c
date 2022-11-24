# incluir  " árboles_binarios.h "

/* *
* tree_height - mide la altura de un árbol binario
* @tree: puntero al nodo raíz del árbol para medir la altura
*
* Devuelve: Altura o 0 si el árbol es NULL
 */
size_t  tree_height ( const  binary_tree_t *árbol)
{
	tamaño_t altura_l = 0 ;
	tamaño_t altura_r = 0 ;

	si (!árbol)
		retorno ( 0 );

	si (árbol-> izquierda )
		altura_l = 1 + altura_árbol (árbol-> izquierda );

	si (árbol-> derecho )
		altura_r = 1 + altura_árbol (árbol-> derecha );

	si (altura_l > altura_r)
		retorno (altura_l);
	retorno (altura_r);
}

/* *
* isBST - comprueba si cada nodo tiene a la izquierda un valor menor que él mismo
* @root: nodo a comprobar
* @min: valor mínimo para comprobar con el nodo de la izquierda
* @max: valor máximo para comprobar con el nodo de la derecha
* Devuelve: 1 si es un BST o 0 en caso contrario
 */
int  isBST ( const  binary_tree_t *raíz,
		  const  binary_tree_t *mín, const  binary_tree_t *máx)
{
	si (raíz == NULL )
		retorno ( 1 );

	if (min != NULL && root-> n <= min-> n )
		retorno ( 0 );

	if (max != NULL && root-> n >= max-> n )
		retorno ( 0 );

	return ( isBST (raíz-> izquierda , min, raíz) &&
			isBST (raíz-> derecha , raíz, máx.));
}
/* *
* tree_is_bst - comprueba si un árbol binario es un árbol de búsqueda binaria nid
* @tree: un puntero al nodo nodo del árbol para verificar
* Devuelve: 1 si el árbol es un BST nid y 0 en caso contrario
* Si el árbol es NULL, devuelve 0
 */
int  tree_is_bst ( const  binary_tree_t *árbol)
{
	si (!árbol)
		retorno ( 0 );

	volver ( isBST (árbol, NULL , NULL ));
}

/* *
* avl_check - comprueba si un árbol binario es un árbol AVL válido
* @tree: puntero al nodo raíz del árbol a comprobar
*
* Devuelve: 1 si el árbol es un árbol AVL válido y 0 en caso contrario
 */
int  avl_check ( const  binary_tree_t *árbol)
{
	int diff, alturaL = 0 , alturaR = 0 ;

	si (!árbol)
		retorno ( 1 );

	si (! tree_is_bst (árbol))
		retorno ( 0 );

	alturaL = altura_arbol (arbol-> izquierda );
	alturaR = altura_arbol (arbol-> derecha );

	diff = abs (alturaL - alturaR);

	if (diff == 0 && avl_check (árbol-> izquierda ) && avl_check (árbol-> derecha ))
		retorno ( 1 );
	retorno ( 0 );
}

/* *
* binary_tree_is_avl - comprueba si un árbol binario es un árbol AVL válido
* @tree: puntero al nodo raíz del árbol a comprobar
*
* Devuelve: 1 si el árbol es un árbol AVL válido y 0 en caso contrario
 */
int  binary_tree_is_avl ( const  binary_tree_t *árbol)
{
	si (!árbol)
		retorno ( 0 );

	retorno ( avl_check (árbol));
}
