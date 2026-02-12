#include "binary_trees.h"

static int bst_contains(const bst_t *tree, int value);

/**
 * array_to_bst - Builds a BST from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	bst_t *node;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (bst_contains(root, array[i]))
			continue;

		node = bst_insert(&root, array[i]);
		if (node == NULL)
			return (NULL);
	}

	return (root);
}

/**
 * bst_contains - Checks if a value exists in a BST
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for
 *
 * Return: 1 if value exists, otherwise 0
 */
static int bst_contains(const bst_t *tree, int value)
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
