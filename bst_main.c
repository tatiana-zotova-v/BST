#include <stdlib.h>
#include "tree.h"

int main ()
{
	struct bst *tree = NULL;
	interface(tree);
	free_tree(&tree);
	return 0;
}