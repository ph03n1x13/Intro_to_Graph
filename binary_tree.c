/*
*Implementation of a simple binary tree that is mimiced
*by the concept of singly linked list concept by fragmanting
*and array into a median and recursively using each median a root and
*smaller values in left and greaters in right.
*though c++ comes with a nice container ready with tree, graph, [not sure],
*vectors, linked lists, stacks n queues etc data sturctures
*but this is a good practice to write these structures
*from scractch for better understanding :)

assume a list : 1 2 3 4 5 6 7
here recursive medians are : 4  2  6  1  3  5  7
So the tree looks like this

      4
  2       6
1   3   5   7
Null---------Null

*/
#include <stdio.h>
#include <stdlib.h> // standard C library for memory_allocation malloc()

typedef struct tree {
	  int value;
		char character[2];
		char string[100];
	  struct tree *left_child;
    struct tree *right_child;
	} bin_tree; // user defined data type alias

/*
we'll pass pointer to the pointer that will
affect the root node kept in main function.
*/

void create_tree(int value, bin_tree **root);


void print_tree(bin_tree *root);

/*
single pointer is not enough to destroy the allocated memory 
cause root is not global here.
don't run without virtual box in your linux system lol*/

void sudo_rm_rf(bin_tree **root);


void ping_root(bin_tree **root);


int main() {


		bin_tree *root = NULL;
    int val;

		/* ctr+d for Linux and ctr+z for windows == End of File */

		while (scanf("%d", &val) != EOF) {
						/*for double pointer use address (a copy) of the root..... or pointer to the root*/
					 create_tree(val, &root);
		}

	   printf("--------------------------------\n");
		printf("root : %d\n", root->value);
		print_tree(root);
		sudo_rm_rf(&root);
		printf("					\n");
		ping_root(&root);
		print_tree(root);
		return 0;
}

/*a simple recursion*/

void create_tree(int val, bin_tree **root) {

		 if (*root == NULL) {
			 /*update the root and we need a cache to temporaritly store data*/
      bin_tree *cache = (bin_tree *) malloc(sizeof(bin_tree));
			cache->value = val;
			cache->left_child = NULL;
			cache->right_child = NULL;
			*root = cache;
		 }
		 /*this tree is built avoiding duplicates*/
		 else if(val < (*root)->value){ create_tree(val, &(*root)->left_child);}
		 else if(val > (*root)->value){ create_tree(val, &(*root)->right_child);}
}


/*in-order print like a sorted array*/
void print_tree(bin_tree *root) {
		 if (root != NULL) {
			 	 print_tree(root->left_child);
				 printf("%d ", root->value);
				 print_tree(root->right_child);
		 }

}


void sudo_rm_rf(bin_tree **root) {
	if (*root == NULL) { return; }

		sudo_rm_rf(&(*root)->left_child);
		sudo_rm_rf(&(*root)->right_child);
		free(*root);
		*root = NULL; // explicitly nullyfy the 'this' root(s) to avoid memory leak
}


/*check if there any memory leak*/

void ping_root(bin_tree **root) {
		 if (*root == NULL) {
		    printf("root was null, \n" );
		 }
		 else{printf("root %d\n", (*root)->value );}
}
