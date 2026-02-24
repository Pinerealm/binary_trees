#include "binary_trees.h"

static avl_t *avl_remove_recursive(avl_t *root, int value);
static avl_t *avl_rebalance_remove(avl_t *root);
static avl_t *avl_min_node(avl_t *node);

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the AVL tree
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	root = avl_remove_recursive(root, value);
	if (root != NULL)
		root->parent = NULL;

	return (root);
}

/**
 * avl_remove_recursive - Removes a value from an AVL subtree
 * @root: Pointer to the current subtree root
 * @value: Value to remove in the subtree
 *
 * Return: Pointer to the (possibly new) subtree root
 */
static avl_t *avl_remove_recursive(avl_t *root, int value)
{
	avl_t *child, *successor;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
	{
		root->left = avl_remove_recursive(root->left, value);
		if (root->left != NULL)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = avl_remove_recursive(root->right, value);
		if (root->right != NULL)
			root->right->parent = root;
	}
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			child = (root->left != NULL) ? root->left : root->right;
			if (child != NULL)
				child->parent = root->parent;
			free(root);
			return (child);
		}

		successor = avl_min_node(root->right);
		root->n = successor->n;
		root->right = avl_remove_recursive(root->right, successor->n);
		if (root->right != NULL)
			root->right->parent = root;
	}

	return (avl_rebalance_remove(root));
}

/**
 * avl_rebalance_remove - Rebalances an AVL subtree after removal
 * @root: Pointer to the current subtree root
 *
 * Return: Pointer to the (possibly new) subtree root
 */
static avl_t *avl_rebalance_remove(avl_t *root)
{
	int balance;

	if (root == NULL)
		return (NULL);

	balance = binary_tree_balance(root);
	if (balance > 1 && root->left != NULL)
	{
		if (binary_tree_balance(root->left) >= 0)
			return (binary_tree_rotate_right(root));

		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && root->right != NULL)
	{
		if (binary_tree_balance(root->right) <= 0)
			return (binary_tree_rotate_left(root));

		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}

/**
 * avl_min_node - Finds the minimum node in a subtree
 * @node: Pointer to the subtree root
 *
 * Return: Pointer to the minimum node
 */
static avl_t *avl_min_node(avl_t *node)
{
	while (node != NULL && node->left != NULL)
		node = node->left;

	return (node);
}
