#include "binary_trees.h"

/**
 * node_depth - Measures the depth of a node in a binary tree
 * @node: Pointer to the node to be measured
 *
 * Return: The depth of the node
 */
static size_t node_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	while (node)
	{
		depth++;
		node = node->parent;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * in a binary tree
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common
 * ancestor is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = node_depth(first);
	depth_second = node_depth(second);

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
