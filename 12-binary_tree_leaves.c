#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);
	leaves = binary_tree_leaves(tree->left);
	leaves += binary_tree_leaves(tree->right);
	if (tree->left == NULL && tree->right == NULL)
		return (leaves + 1);

	return (leaves);
}
