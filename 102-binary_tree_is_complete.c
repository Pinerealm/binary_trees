#include "binary_trees.h"
binary_tree_t *_binary_tree_sibling(const binary_tree_t *node);
int _binary_tree_is_leaf(const binary_tree_t *node);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int left_complete, right_complete;

	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_complete = binary_tree_is_complete(tree->left);
	right_complete = binary_tree_is_complete(tree->right);
	if (left_complete == 1 && right_complete == 1)
		return (1);

	if (left_complete == 1 && right_complete == 0)
	{
		binary_tree_t *sibling = _binary_tree_sibling(tree);
		if (_binary_tree_is_leaf(sibling))
			return (1);
		else
			return (0);
	}

	return (0);
}

/**
 * _binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if node has no sibling
 */
binary_tree_t *_binary_tree_sibling(const binary_tree_t *node)
{
	binary_tree_t *sibling;

	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left == node)
		sibling = node->parent->right;
	else
		sibling = node->parent->left;
	return (sibling);
}

/**
 * _binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */
int _binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->left && !node->right)
		return (1);
	return (0);
}
