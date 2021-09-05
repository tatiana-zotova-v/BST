#include <stdio.h>

struct bst 
{
	int key;
	char *value;
	struct bst *left;
	struct bst *right;
};
struct bst *new_bstree (int key, char *value);
int add_bstree (struct bst *tree, int key, char *value);
struct bst *find_node_bst (struct bst *tree, int key);
struct bst *min_elem (struct bst *tree);
struct bst *max_elem (struct bst *tree);
int del_elem (struct bst **tree, int key);
int printf_bst (struct bst* bstree);
void free_tree(struct bst **tree);
void interface (struct bst *tree);

struct avl 
{
	int key;
	char *value;

	int height;
	struct avl *left;
	struct avl *right;
};
struct avl *new_avl(int key, char *value);
int height(struct avl* tree);
int now_h(struct avl *tree);
int balance(struct avl *tree);
struct avl *r_rotation(struct avl *tree);
struct avl *l_rotation(struct avl *tree);
struct avl *rl_rotation(struct avl *tree);
struct avl *lr_rotation(struct avl *tree);
void balancing(struct avl **tree);
struct avl *add_tree(struct avl *tree, int key, char *value);
struct avl *find_node_avl(struct avl *tree, int key);
struct avl *min_elem_avl(struct avl *tree);
int del_elem_avl(struct avl **tree, int key);
int printf_avl_txt(struct avl *avl);
int printf_avl(struct avl* avl, int level);
void free_tree_avl(struct avl **tree);
void interface_avl (struct avl *tree);