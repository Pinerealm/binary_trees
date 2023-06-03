#include "binary_trees.h"
void print_level(const binary_tree_t *tree, int level, void (*func)(int));
int _binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *node;
	int height, i;

	if (tree == NULL || func == NULL)
		return;
	height = _binary_tree_height(tree);
	for (i = 0; i <= height; i++)
	{
		node = (binary_tree_t *)tree;
		print_level(node, i, func);
	}
}

/**
 * print_level - Prints the nodes at a given level
 * @tree: Pointer to the root node of the tree
 * @level: Level of the tree to print
 * @func: Pointer to a function to call for each node
 */
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * _binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int _binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}
