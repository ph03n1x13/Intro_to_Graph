/*
some important references---
1. pass by value or ref:
http://stackoverflow.com/questions/373419/whats-the-difference-between-passing-by-reference-vs-passing-by-value

2. passing vector to function:
http://stackoverflow.com/questions/26647152/passing-vectors-to-a-function-value-vs-reference-c
*/

#include <cstdio>
#include <vector>

using namespace std;

/*image of the graph. custom vector type data structure*/
typedef vector< vector<int> > Image;

void add_adj_node(Image &graph, int source, int destiny, bool directed);
void print_graph(Image &graph, int limit);


int  main() {

  int limit = 8;
  /*an Image type array named graph of limit+1 size as we will ignore 0th index*/
  Image graph(limit+1);
  printf("size of declared graph: %d\n", graph.size());
  add_adj_node(graph, 2, 7, false);
  add_adj_node(graph, 5, 2, false);
  add_adj_node(graph, 4, 8, false);
  add_adj_node(graph, 3, 2, false);
  add_adj_node(graph, 8, 6, false);
  print_graph(graph, limit);

  return 0;
}

void add_adj_node(Image &graph, int src, int dst, bool dir) {

    graph[src].push_back(dst);
    if (dir == false) {
        dir = true;
        add_adj_node(graph, dst, src, dir);
    }
  return;
}

void print_graph(Image &graph, int lmt) {
  for (int i = 0; i <= lmt; i++) {
    printf("array[%d]: ", i);
    int grSz = graph[i].size();

    for (int j = 0; j < grSz; j++) {
        printf("%d ",graph[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return;
}
