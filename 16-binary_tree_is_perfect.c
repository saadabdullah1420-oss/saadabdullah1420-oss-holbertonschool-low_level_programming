#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of the tree
 */
static int tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * check_perfect - Checks if a tree is perfect
 * @tree: Pointer to the tree
 * @level: Current level
 * @height: Tree height
 *
 * Return: 1 if perfect, otherwise 0
 */
static int check_perfect(const binary_tree_t *tree, int level, int height)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (height == level);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (check_perfect(tree->left, level + 1, height) &&
		check_perfect(tree->right, level + 1, height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 *
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	height = tree_height(tree);

	return (check_perfect(tree, 0, height));
}
