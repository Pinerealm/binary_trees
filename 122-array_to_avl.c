#include "binary_trees.h"

static int avl_contains(const avl_t *tree, int value);

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	avl_t *node;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (avl_contains(root, array[i]))
			continue;

		node = avl_insert(&root, array[i]);
		if (node == NULL)
			return (NULL);
	}

	return (root);
}

/**
 * avl_contains - Checks if a value exists in an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 * @value: Value to search for
 *
 * Return: 1 if value exists, otherwise 0
 */
static int avl_contains(const avl_t *tree, int value)
{
	while (tree != NULL)
	{
		if (value == tree->n)
			return (1);
		if (value < tree->n)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return (0);
}
