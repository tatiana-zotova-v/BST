#include <stdio.h>
#include "tree.h"

void interface (struct bst *tree)
{
	int key, to_do, error, cnt;
	char value[256] = {0};
	struct bst *temp = NULL;

	printf ("Let's go create binary search tree!\n\n"
			"Enter the key of the first node: ");
	scanf ("%d", &key);
	printf ("And the value what you want assign to it: ");
	scanf ("%s", value);
	tree = new_bstree (key, value);
	if (tree == NULL)
	{
		printf("Memmory allocation error\n");
		return;
	}

	printf ("\nWhat do you want to do with your bst?\n"
			"1 - add the new element\n"
			"2 - find an element by key\n"
			"3 - find an element with the smallest key\n"
			"4 - find an element with the biggest key\n"
			"5 - delete an elemet by key\n"
			"6 - printf all the elements\n"
			"0 - stop the programm\n\n");
	while (1)
	{
		scanf ("%d", &to_do);

		if (to_do == 0)
		{
			break;
		}

		else if (to_do == 1)
		{
			char val[256] = {0};
			printf("\nEnter the key of the new node: ");
			scanf ("%d", &key);
			printf ("Enter the value what you want assign to it: ");
			scanf ("%s", val);
			error = add_bstree (tree, key, val);
			if (error == 1 || error == 3)
				printf ("There is no such binary search tree. Error code: %d\n", error);

			else if (error == 2)
				printf ("You can not add this element, "
						"because its key matches the key of one "
						"of the elements in this binary search tree.\n");

			printf ("\nYour node was added\n");
		}

		else if (to_do == 2) 
		{
			printf("Enter the key of the node, what you want to find: ");
			scanf ("%d", &key);
			temp = find_node_bst (tree, key);
			if (temp == NULL)
				printf ("There is no such binary search tree");
		}

		else if (to_do == 3)
		{
			temp = min_elem (tree);
			if (temp == NULL)
				printf ("There is no such binary search tree\n"
						"The node with the min key was not found\n");
			else
				printf ("Value of the element with min key: %s\n", temp->value); 
		}

		else if (to_do == 4)
		{
			temp = max_elem (tree);
			if (temp == NULL)
				printf ("There is no such binary search tree\n"
						"The node with the max key was not found\n");
			else 
				printf ("Value of the element with max key: %s\n", temp->value); 
		}

		else if (to_do == 5)
		{
			printf ("Enter the key of the node, what you want to delete: ");
			scanf ("%d", &key);
			error = del_elem (&tree, key);
			if (error)
				printf ("There is no such binary search tree. Code: %d\n", error);
		}

		else if (to_do == 6)
		{
			error = printf_bst(tree);
			if (error)
			{
				printf ("The bst is empty\nDo you want to create a new bst?\n1 - yes\nelse numb - no\n");
				scanf ("%d", &cnt);
				if (cnt == 1)
				{
					printf ("Let's go create binary search tree!\n\n"
							"Enter the key of the first node: ");
					scanf ("%d", &key);
					printf ("And the value what you want assign to it: ");
					scanf ("%s", value);
					tree = new_bstree (key, value);
					if (tree == NULL)
					{
						printf("Memmory allocation error\n");
						return;
					}
				}

				else
					break;
			}
		}

		else if (to_do == 7)
			printf ("1 - add the new element\n"
					"2 - find an element by key\n"
					"3 - find an element with the smallest key\n"
					"4 - find an element with the biggest key\n"
					"5 - delete an elemet by key\n"
					"6 - printf all the elements\n"
					"0 - stop the programm\n");

		else 
		{
			printf ("\nYou entered incorrect numb, try again\n");
		}

		printf ("\nPress numb from 0 to 6 again dependening on you want\n"
				"If you don't remember the commands, press 7\n\n");
	}
	
	printf("Bye!\n");
}