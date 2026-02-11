#include "binary_trees.h"
static size_t tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue, *current;
	size_t size, front = 0, rear = 0;
	int seen_null = 0;

	if (tree == NULL)
		return (0);

	size = tree_size(tree);
	queue = malloc(sizeof(*queue) * (size * 2 + 1));
	if (queue == NULL)
		return (0);

	queue[rear++] = tree;
	while (front < rear)
	{
		current = queue[front++];
		if (current == NULL)
		{
			seen_null = 1;
			continue;
		}

		if (seen_null)
		{
			free(queue);
			return (0);
		}

		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}

	free(queue);
	return (1);
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
