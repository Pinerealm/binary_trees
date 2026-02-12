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
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
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
	bst_t *successor;

	if (node->left == NULL)
		return (node->right);

	if (node->right == NULL)
		return (node->left);

	successor = find_min(node->right);
	node->n = successor->n;
	node->right = bst_remove(node->right, successor->n);

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
