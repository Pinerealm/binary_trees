#include "binary_trees.h"
#include <limits.h>

static int is_avl_helper(const binary_tree_t *tree, int min, int max, int *height);
static int max_int(int a, int b);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL Tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX, &height));
}

/**
 * is_avl_helper - Helper function to validate AVL tree properties
 * @tree: Pointer to the current node
 * @min: Minimum value the node can have
 * @max: Maximum value the node can have
 * @height: Pointer to store the height of the current subtree
 *
 * Return: 1 if valid AVL Tree, otherwise 0
 */
static int is_avl_helper(const binary_tree_t *tree, int min, int max, int *height)
{
	int left_height = 0, right_height = 0, balance;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (!is_avl_helper(tree->left, min, tree->n, &left_height))
		return (0);

	if (!is_avl_helper(tree->right, tree->n, max, &right_height))
		return (0);

	balance = left_height - right_height;
	if (balance > 1 || balance < -1)
		return (0);

	*height = 1 + max_int(left_height, right_height);
	return (1);
}

/**
 * max_int - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Maximum of a and b
 */
static int max_int(int a, int b)
{
	return (a > b ? a : b);
}
