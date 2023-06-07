#include "binary_trees.h"
int _binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? _binary_tree_height(tree->left) + 1 : 0;
	right_height = tree->right ? _binary_tree_height(tree->right) + 1 : 0;

	return (left_height - right_height);
}

/**
 * _binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
int _binary_tree_height(const binary_tree_t *tree)
{
	int height_l, height_r;

	if (tree == NULL)
		return (0);
	height_l = tree->left ? 1 + _binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + _binary_tree_height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}
