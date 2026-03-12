#include "binary_trees.h"

static size_t tree_size(const binary_tree_t *tree);
static heap_t *find_last_node(heap_t *root, size_t size);
static void heapify_down(heap_t *node);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node;
	int root_value;
	size_t size;

	if (root == NULL || *root == NULL)
		return (0);

	root_value = (*root)->n;
	size = tree_size(*root);

	if (size == 1)
	{
		free(*root);
		*root = NULL;
		return (root_value);
	}

	last_node = find_last_node(*root, size);

	(*root)->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);

	heapify_down(*root);

	return (root_value);
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

/**
 * find_last_node - Finds the last node in level-order traversal
 * @root: Pointer to the root of the heap
 * @size: Current size of the heap
 *
 * Return: Pointer to the last node
 */
static heap_t *find_last_node(heap_t *root, size_t size)
{
	size_t mask;
	int bit;

	/* Find the most significant bit position */
	for (mask = 1; mask <= size; mask <<= 1)
		;
	mask >>= 2; /* Move to second most significant bit */

	/* Traverse down the tree following the binary representation */
	while (mask > 0)
	{
		bit = (size & mask) != 0;
		if (bit)
			root = root->right;
		else
			root = root->left;
		mask >>= 1;
	}

	return (root);
}

/**
 * heapify_down - Restores max heap property by bubbling down
 * @node: Pointer to the node to bubble down
 */
static void heapify_down(heap_t *node)
{
	heap_t *largest;
	int temp;

	while (node != NULL)
	{
		largest = node;

		if (node->left != NULL && node->left->n > largest->n)
			largest = node->left;

		if (node->right != NULL && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			break;

		/* Swap values */
		temp = node->n;
		node->n = largest->n;
		largest->n = temp;

		node = largest;
	}
}
