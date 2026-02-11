#include "binary_trees.h"

/**
 * depth_leftmost - Measures the depth of the leftmost path in a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The depth of the leftmost path
 */
static int depth_leftmost(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect_helper - Helper function to check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 * @depth: The depth of the leftmost path
 * @level: The current level in the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
static int is_perfect_helper(const binary_tree_t *tree, int depth, int level)
{
	if (!tree)
		return (level == depth);

	if (!tree->left && !tree->right)
		return (level + 1 == depth);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect_helper(tree->left, depth, level + 1) &&
		is_perfect_helper(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (!tree)
		return (0);

	depth = depth_leftmost(tree);
	return (is_perfect_helper(tree, depth, 0));
}
