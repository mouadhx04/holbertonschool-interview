#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is an AVL tree
 * @tree: tree to check
 *
 * Return: 1 if avl tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (bst(tree, INT_MIN, INT_MAX) && bal(tree))
		return (1);

	return (0);
}

/**
 * bal - checks if tree is balanced
 * @tree: tree to check
 *
 * Return: 1 if balanced, 0 otherwise
 */
int bal(const binary_tree_t *tree)
{
	if (tree && (!tree->left || bal(tree->left)) &&
	    (!tree->right || bal(tree->right)) &&
	    (abs(height(tree->right) - height(tree->left)) <= 1))
		return (1);

	return (0);
}

/**
 * bst - checks if binary tree is a BST tree
 * @tree: tree to check
 * @min: min value
 * @max: max value
 *
 * Return: 1 if BST tree, 0 otherwise
 */
int bst(const binary_tree_t *tree, int min, int max)
{
	if (tree && (!tree->right || (tree->right->n > tree->n &&
	    (tree->right->n < max || tree->right->n == INT_MAX) &&
	    bst(tree->right, tree->n, max))) && (!tree->left  ||
	    (tree->left->n < tree->n && (tree->left->n > min ||
	    tree->left->n == INT_MIN) && bst(tree->left, min, tree->n))))
		return (1);

	return (0);
}

/**
 * height - gets height of binary tree
 * @tree: tree to check
 *
 * Return: height of tree
 */
int height(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree)
	{
		lh = height(tree->left);
		rh = height(tree->right);

		if (rh > lh)
			return (1 + rh);

		return (1 + lh);
	}

	return (0);
}
