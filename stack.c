#include <stdio.h>
#include <stdlib.h>


typedef struct STACK{
  int data;
  char description[100];
  struct STACK *point_nxt;
} STACK;

/*global declaration for ensuring access from anywhere*/

STACK *S_head = NULL;

/*double pointers cause head nodes are locally initialized in main()*/

void push(int value);
int  pop();
void print_stack();
void free_stack();



int main() {
  /*do your operation here*/
  return 0;
}



void push(int value) {

  	/*first commit / allocate a new head*/
  	STACK *cache;
  	cache = (STACK *) malloc(sizeof(STACK));
  	cache->data = value;

  	if (S_head == NULL) {
  		cache->point_nxt = NULL;
  		S_head = cache; /*assign the cache to head head*/
  		}

  	else {
  		/*point to the previous head*/
  		cache->point_nxt = S_head;
  		S_head = cache;
  	}

}


int pop(){

	if(S_head == NULL){
		printf("Stack is empty ! ! !\n");
		return -1;
	}

	else {
		/*put next head into a cache, free present head, take next head to present head*/
		STACK *cache ;
		cache = S_head->point_nxt;
		int popped_value = S_head->data;
		free(S_head);
		S_head = cache;
		return popped_value;
	}
}


void free_stack(){
	STACK *cache_head;

	while (S_head) {

		/*assign next head to the cache*/
		cache_head = S_head->point_nxt;
		free(S_head);
		S_head = cache_head;
	}

	printf("memory release complete !!! \n");
  /*for further assurance*/
  printf("stack head address: %x !!! \n", S_head);
}

void print_stack(){

  STACK *cache = S_head;

	while (cache) {
		printf(" %d \n", cache->data);
		printf(" |\n");
		cache = cache->point_nxt;
	}

	/*for further assurance*/
	if ( cache == NULL){
			printf("NULL\n");
	}
	printf("\n");
}
