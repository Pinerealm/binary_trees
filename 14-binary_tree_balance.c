#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int r_factor, l_factor;

	if (tree == NULL)
		return (0);

	l_factor = tree->left ? 1 + binary_tree_balance(tree->left) : 0;
	r_factor = tree->right ? 1 + binary_tree_balance(tree->right) : 0;
	return (l_factor - r_factor);
}
