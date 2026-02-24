#include "binary_trees.h"

static avl_t *sorted_array_to_avl_helper(int *array, int start, int end,
					 avl_t *parent);

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, 0, (int)size - 1, NULL));
}

/**
 * sorted_array_to_avl_helper - Helper to build AVL tree from sorted array
 * @array: Pointer to the sorted array
 * @start: Start index in the array
 * @end: End index in the array
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the created AVL subtree
 */
static avl_t *sorted_array_to_avl_helper(int *array, int start, int end,
					 avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = start + (end - start) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = sorted_array_to_avl_helper(array, start, mid - 1, root);
	root->right = sorted_array_to_avl_helper(array, mid + 1, end, root);

	return (root);
}
