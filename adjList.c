#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*

review:
http://codereview.stackexchange.com/questions/147816/adjacency-list-from-scratch-c

*/

/*this is hardcoded but easy and ready to tweak and use flexibly use*/

 /*a single node of an adjacency list*/
typedef struct adjList{
    int dest;
    int weight;
    struct adjList *next;
} adjList;


/*Image of a graph...*/

typedef struct Image{
    int source;
    adjList *head;
} Image;

// when passing through functions type *var and type var[] will mean same
// because we pass an array's first identical address through the c functions

void initialize_graph(Image *graph, int vertices);

void print_graph(Image graph[], int vertices);

void add_adj_node(Image *graph, int source, int destiny, bool directed);

void free_graph(Image graph[], int vertices);



int main() {

    int vertices;
    scanf("%d", &vertices);
//    declare the graph array of 1 * 'vertices'+1
    /*as we start from 1 of 0 1 2 3 4 5 ......n*/
    Image graph[vertices+1];

    printf("size of graph: %d bytes\n", sizeof graph);

    initialize_graph(graph, vertices);

    printf("initialized image of graph\n");

    print_graph(graph, vertices);

    printf("                          \n");
    //is the graph directed ? ans: false

    add_adj_node(graph, 1, 7, false);
    add_adj_node(graph, 1, 3, false);
    add_adj_node(graph, 4, 6, false);
    add_adj_node(graph, 4, 1, false);
    add_adj_node(graph, 5, 2, false);
    add_adj_node(graph, 1, 5, false);
    add_adj_node(graph, 1, 2, false);

    print_graph(graph, vertices);

    free_graph(graph, vertices);

    /*if this print produces segmentation fault then the memory is fully freed ! ! holla ! !*/
    //printf("graph[1].head->dest%d\n", graph[1].head->dest);
    return 0;
}



void initialize_graph(Image graph[], int vertices) {

        for(int i = 1; i<= vertices; i++){
                graph[i].source = i;
                graph[i].head = NULL;
        }
       return;
}


void add_adj_node(Image *graph, int src, int dest, bool directed){

    /*create a single node*/
    adjList *cache = malloc(sizeof(adjList));
    
    // as sequence doesn't matter just make an adjacency stack/ update the head
    cache->dest = dest;
    cache->next = graph[src].head;
    graph[src].head = cache;

    if (directed == false) {
          directed = true; // prevent third recursion
          /*notice we've changed the sequence. dest and src*/
          add_adj_node( graph, dest, src, directed);
    }

    return;
}



void print_graph(Image *graph, int vertices){

    for(int i = 1; i<= vertices; i++){
                adjList *crawl = graph[i].head;
                printf("node: %d    ", graph[i].source);
                while(crawl){
                      printf("%d ", crawl->dest);
                      crawl = crawl->next;
                }
                printf("\n");
        }
    return;
}


/*just a reverse version of crawling a graph*/

void free_graph(Image *graph, int vertices){

    for(int i = 1; i<= vertices; i++){
                adjList *cache;
                printf("releasing elements of node: %d    ", graph[i].source);
                while(graph[i].head){
                      /*put the next adjacency node in the cache*/
                      cache = graph[i].head->next;
                      /*free the present adjacencey node*/
                      free(graph[i].head);
                      graph[i].head = cache;
                }
               printf("\n");
        }
    return;
}
