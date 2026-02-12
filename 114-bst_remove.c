#include "binary_trees.h"

static bst_t *find_min(bst_t *node);
static bst_t *remove_node(bst_t *node);

/**
 * bst_remove - Removes a node from a BST
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		if (root->left != NULL)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
		if (root->right != NULL)
			root->right->parent = root;
	}
	else
		root = remove_node(root);

	return (root);
}

/**
 * remove_node - Removes the given node from the BST
 * @node: Node to remove
 *
 * Return: Pointer to the node replacing the removed node
 */
static bst_t *remove_node(bst_t *node)
{
	bst_t *successor, *child;

	if (node->left == NULL)
	{
		child = node->right;
		if (child != NULL)
			child->parent = node->parent;
		free(node);
		return (child);
	}

	if (node->right == NULL)
	{
		child = node->left;
		if (child != NULL)
			child->parent = node->parent;
		free(node);
		return (child);
	}

	successor = find_min(node->right);
	node->n = successor->n;
	node->right = bst_remove(node->right, successor->n);
	if (node->right != NULL)
		node->right->parent = node;

	return (node);
}

/**
 * find_min - Finds the node with minimum value in a subtree
 * @node: Root of the subtree
 *
 * Return: Pointer to the node with minimum value
 */
static bst_t *find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;

	return (node);
}
