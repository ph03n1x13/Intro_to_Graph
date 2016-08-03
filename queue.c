#include<stdio.h>
#include<stdlib.h>



typedef struct NODE {
	int data;
	struct NODE *next_node;
	} NODE;


NODE *Q_head = NULL;
NODE *Q_tail = NULL;


void enqueue(int value);
int  dequeue();
void print_queue();
void free_queue();



int main(){
		/*operations here*/
		return 0;
}



void enqueue(int value){
	/*create an individual node*/
	NODE *cache;
	cache = (NODE *) malloc(sizeof(NODE));
	cache->data = value;
	cache->next_node = NULL;

	if (Q_head == NULL) {
		//interchanging head and tail. Now tail will act as head and updated
		Q_head = cache;
		Q_tail = Q_head;
		}

	else {
		//updtating the tail. cache will be the new tail
		Q_tail->next_node = cache;
		Q_tail = cache;
	}
}



int dequeue() {
	if (Q_head == NULL) {
		printf("queue is empty\n");
		return -1;
	}
	int dequeued_value = Q_head->data;
	NODE *cache = Q_head->next_node;
	free(Q_head);
	Q_head = cache;
	return dequeued_value;
}




void print_queue(){
	NODE *cache_head = Q_head;
	while(cache_head){
			//printf("{data %d add: %x} -> ", cache_head->data, cache_head);
			printf("%d -> ", cache_head->data);

			//printf(" |\n");
			cache_head = cache_head->next_node;
	}
	if (cache_head == NULL) {
			printf("NULL\n");
	}
}


void free_queue(){

	if (Q_head == NULL) {
		printf("head is null releasing tail\n" );
	}

	else{
		NODE *cache_head;

		while (cache_head) {

			/*assign next head to the cache*/
			cache_head = Q_head->next_node;
			free(Q_head);
			Q_head = cache_head;
		}

	}

		Q_tail = NULL;
	printf("memory release complete !!! \n");
}
