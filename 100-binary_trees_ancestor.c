#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 * otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);
	ancestor = (binary_tree_t *)second;
	while (first != NULL)
	{
		while (second != NULL)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = ancestor;
		first = first->parent;
	}
	return (NULL);
}
