#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node. The value in the
 * node must be passed as a parameter to this function
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *queue[1024], *current;
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue[rear++] = tree;
	while (front < rear)
	{
		current = queue[front++];

		func(current->n);
		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}
}
