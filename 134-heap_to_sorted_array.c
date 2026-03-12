#include "binary_trees.h"

static size_t tree_size(const binary_tree_t *tree);

/**
 * heap_to_sorted_array - Converts a Max Binary Heap to a sorted array
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to a sorted array in descending order, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t heap_size, i;
	int *array;

	if (heap == NULL)
	{
		*size = 0;
		return (NULL);
	}

	heap_size = tree_size(heap);
	array = malloc(sizeof(int) * heap_size);
	if (array == NULL)
	{
		*size = 0;
		return (NULL);
	}

	*size = heap_size;
	for (i = 0; i < heap_size; i++)
		array[i] = heap_extract(&heap);

	return (array);
}

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}
