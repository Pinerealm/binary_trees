#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = tree->left ? binary_tree_is_full(tree->left) : 0;
	right = tree->right ? binary_tree_is_full(tree->right) : 0;

	if (left == right)
		return (1);
	return (0);
}
