#include "binary_trees.h"
static size_t tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t r_height, l_height;

	if (tree == NULL)
		return (0);

	l_height = tree_height(tree->left);
	r_height = tree_height(tree->right);
	return ((int)l_height - (int)r_height);
}

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (tree == NULL)
		return (0);
	height_l = tree_height(tree->left);
	height_r = tree_height(tree->right);
	return (1 + (height_l > height_r ? height_l : height_r));
}
