#include "binary_trees.h"
int binary_tree_balance_helper(const binary_tree_t *tree);

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

	l_factor = tree->left ? 1 + binary_tree_balance_helper(tree->left) : 0;
	r_factor = tree->right ? 1 + binary_tree_balance_helper(tree->right) : 0;
	return (l_factor - r_factor);
}

/**
 * binary_tree_balance_helper - Helper function for binary_tree_balance
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor of the tree
 */
int binary_tree_balance_helper(const binary_tree_t *tree)
{
	int l_height, r_height;

	l_height = tree->left ? 1 + binary_tree_balance_helper(tree->left) : 0;
	r_height = tree->right ? 1 + binary_tree_balance_helper(tree->right) : 0;
	return (l_height > r_height ? l_height : r_height);
}
