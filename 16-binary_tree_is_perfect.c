#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = tree->left ? 1 + binary_tree_is_perfect(tree->left) : 0;
	right = tree->right ? 1 + binary_tree_is_perfect(tree->right) : 0;

	if (left == right)
		return (1);
	return (0);
}
