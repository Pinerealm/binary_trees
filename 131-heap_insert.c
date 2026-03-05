#include "binary_trees.h"

static size_t tree_size(const binary_tree_t *tree);
static heap_t *find_insertion_parent(heap_t *root, size_t size);
static heap_t *heapify_up(heap_t *node);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new_node, *inserted;
	size_t size;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = tree_size(*root);
	parent = find_insertion_parent(*root, size);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	inserted = heapify_up(new_node);

	while ((*root)->parent != NULL)
		*root = (*root)->parent;

	return (inserted);
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
 * find_insertion_parent - Finds the parent node for insertion
 * @root: Pointer to the root of the heap
 * @size: Current size of the heap
 *
 * Return: Pointer to the parent node where insertion should occur
 */
static heap_t *find_insertion_parent(heap_t *root, size_t size)
{
	size_t position, mask;
	int bit;

	position = size + 1;

	/* Find the most significant bit position */
	for (mask = 1; mask <= position; mask <<= 1)
		;
	mask >>= 2; /* Move to second most significant bit */

	/* Traverse down the tree following the binary representation */
	while (mask > 1)
	{
		bit = (position & mask) != 0;
		if (bit)
			root = root->right;
		else
			root = root->left;
		mask >>= 1;
	}

	return (root);
}

/**
 * heapify_up - Bubbles up a node to maintain max heap property
 * @node: Pointer to the node to bubble up
 *
 * Return: Pointer to the node containing the inserted value after bubbling
 */
static heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		/* Swap values with parent */
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		/* Move up */
		node = node->parent;
	}

	return (node);
}
