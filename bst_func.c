#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct bst *new_bstree (int key, char *value)
{
	struct bst *node;
	node = malloc (sizeof(struct bst));
	if (node == NULL)
		return NULL;

	node->value = malloc(sizeof(char)*strlen(value));
	if (node->value == NULL)
		return NULL;

	node->key = key;
	strncpy (node->value, value, strlen(value));
	node->left = NULL;
	node->right = NULL;

	return node;
}

int add_bstree (struct bst *tree, int key, char *value)
{
	struct bst *parent, *node, *temp = tree;

	if (tree == NULL)
		return 1;

	while (temp != NULL)
	{
		parent = temp;
		
		if (key > temp->key)
			temp = temp->right;
		
		else if (key < temp->key)
			temp = temp->left;

		else 
			return 2;
	}

	node = new_bstree (key, value);
	if (node == NULL)
		return 3;

	if (key < parent->key)
		parent->left = node;
	else
		parent->right = node;

	return 0;
}

struct bst *find_node_bst (struct bst *tree, int key)
{
	struct bst* temp = tree;
	if (tree == NULL)
		return NULL;
	
	while (temp != NULL)
	{
		if (key == temp->key)
		{
			printf ("Value of the element with this key: %s\n", temp->value);
			return temp;
		}
		else if (key > temp->key)
			temp = temp->right;
		else 
			temp = temp->left;
	}

	printf ("There is no element with this key.\n");
	return tree;
}

struct bst *min_elem (struct bst *tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->left != NULL)
	{
		tree = tree->left;
	}
	return tree;
}

struct bst *max_elem (struct bst *tree) 
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
	{
		tree = tree->right;
	}
	return tree;
}

int del_elem (struct bst **tree, int key)
{
	if (tree == NULL)
		return 1;

	struct bst *to_del = find_node_bst (*tree, key);
	if (to_del == NULL)
		return 2;

	/*struct bst **parent = find_parent_p (tree, to_del);
	if (parent == NULL)
		return 3;*/

	if (to_del->right == NULL && to_del->left == NULL)
		*tree = NULL;

	else if (to_del->right == NULL || to_del->left == NULL)
	{	
		if (to_del->left == NULL)
			*tree = to_del->right;

		else if (to_del->right == NULL)
			*tree = to_del->left;
	}

	else
	{		
		struct bst *safe;
		
		*tree = min_elem (to_del->right);

		if (*tree != to_del->right)
		{
			safe = (*tree)->right;
			(*tree)->right = to_del->right;
			(*tree)->right->left = safe;
		}

		(*tree)->left = to_del->left;
	}

	free (to_del->value);
	free (to_del);

	return 0;
}

int printf_bst (struct bst* bstree)
{
	if (bstree == NULL)
		return 1;

	printf ("\nKey of node: %d\t value of node: %s\n", bstree->key, bstree->value);
	if (bstree->left == NULL)
		printf("Node %s has no no left node.\t", bstree->value);

	else
		printf ("Left node %s: %d %s\t", bstree->value, (bstree->left)->key, (bstree->left)->value);

	if (bstree->right == NULL)
		printf("Node %s has no right node.\n", bstree->value);

	else
		printf ("Right node %s: %d %s\n", bstree->value, (bstree->right)->key, (bstree->right)->value);

	printf_bst (bstree->left);
	printf_bst (bstree->right);

	return 0;
}

void free_tree(struct bst **tree)
{
	if(*tree == NULL)
		return;

	if ((*tree)->left != NULL)
		free_tree(&(*tree)->left);

	if ((*tree)->right != NULL)
		free_tree(&(*tree)->right);

	del_elem(tree, (*tree)->key);
}