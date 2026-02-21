#include "binary_trees.h"

static avl_t *avl_insert_recursive(avl_t *root, avl_t *parent, int value,
				   avl_t **inserted, int *status);
static avl_t *avl_insert_left(avl_t *root, int value, avl_t **inserted,
			      int *status);
static avl_t *avl_insert_right(avl_t *root, int value, avl_t **inserted,
			       int *status);
static avl_t *avl_rebalance(avl_t *root, int value);

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *inserted = NULL;
	int status = 0;

	if (tree == NULL)
		return (NULL);

	*tree = avl_insert_recursive(*tree, NULL, value, &inserted, &status);
	if (status != 1)
		return (NULL);

	return (inserted);
}

/**
 * avl_insert_recursive - Inserts a value in an AVL subtree and rebalances it
 * @root: Pointer to the current subtree root
 * @parent: Pointer to the parent of the current subtree root
 * @value: Value to store in the node to be inserted
 * @inserted: Address to store the created node on success
 * @status: Pointer to insertion status: 1 inserted, 0 duplicate, -1 failure
 *
 * Return: Pointer to the (possibly new) subtree root
 */
static avl_t *avl_insert_recursive(avl_t *root, avl_t *parent, int value,
				   avl_t **inserted, int *status)
{
	if (root == NULL)
	{
		*inserted = binary_tree_node(parent, value);
		if (*inserted == NULL)
		{
			*status = -1;
			return (NULL);
		}
		*status = 1;
		return (*inserted);
	}

	if (value == root->n)
	{
		*status = 0;
		return (root);
	}

	if (value < root->n)
		root = avl_insert_left(root, value, inserted, status);
	else
		root = avl_insert_right(root, value, inserted, status);

	if (*status != 1)
		return (root);

	return (avl_rebalance(root, value));
}

/**
 * avl_insert_left - Inserts a value in the left subtree and updates links
 * @root: Pointer to the current subtree root
 * @value: Value to store in the node to be inserted
 * @inserted: Address to store the created node on success
 * @status: Pointer to insertion status: 1 inserted, 0 duplicate, -1 failure
 *
 * Return: Pointer to the current subtree root
 */
static avl_t *avl_insert_left(avl_t *root, int value, avl_t **inserted,
			      int *status)
{
	avl_t *new_left = avl_insert_recursive(root->left, root, value,
					       inserted, status);

	if (*status == -1)
		return (root);

	root->left = new_left;
	return (root);
}

/**
 * avl_insert_right - Inserts a value in the right subtree and updates links
 * @root: Pointer to the current subtree root
 * @value: Value to store in the node to be inserted
 * @inserted: Address to store the created node on success
 * @status: Pointer to insertion status: 1 inserted, 0 duplicate, -1 failure
 *
 * Return: Pointer to the current subtree root
 */
static avl_t *avl_insert_right(avl_t *root, int value, avl_t **inserted,
			       int *status)
{
	avl_t *new_right = avl_insert_recursive(root->right, root, value,
						inserted, status);

	if (*status == -1)
		return (root);

	root->right = new_right;
	return (root);
}

/**
 * avl_rebalance - Rebalances an AVL subtree after insertion
 * @root: Pointer to the current subtree root
 * @value: Value inserted in the subtree
 *
 * Return: Pointer to the (possibly new) subtree root
 */
static avl_t *avl_rebalance(avl_t *root, int value)
{
	int balance;

	balance = binary_tree_balance(root);
	if (balance > 1 && root->left != NULL)
	{
		if (value < root->left->n)
			return (binary_tree_rotate_right(root));

		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && root->right != NULL)
	{
		if (value > root->right->n)
			return (binary_tree_rotate_left(root));

		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
