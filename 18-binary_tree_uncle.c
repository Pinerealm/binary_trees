#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	grandparent = parent->parent;
	if (!grandparent)
		return (NULL);

	if (grandparent->left == parent)
		return (grandparent->right);
	return (grandparent->left);
}
