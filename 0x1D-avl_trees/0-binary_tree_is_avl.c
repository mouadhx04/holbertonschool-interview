#include "binary_trees.h"

/**
 * is_valid_avl - valid tree
 * @tree: pointer head
 * @min: min val
 * @max: max val
 * @height: height
 * Return: 1 or 0
 */
int is_valid_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int height1 = 0, height2 = 0;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (is_valid_avl(tree->left, min, tree->n, &height1) == 0 ||
		is_valid_avl(tree->right, tree->n, max, &height2) == 0)
	return (0);

	*height = ((height1 > height2) ? height1 : height2) + 1;

	if (abs(height1 - height2) > 1)
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - valid tree
 * @tree: pointer head
 * Return: 1 or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (is_valid_avl(tree, INT_MIN, INT_MAX, &height));
}
