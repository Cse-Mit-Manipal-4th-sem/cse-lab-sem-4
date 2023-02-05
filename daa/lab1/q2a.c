#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct Graph {
  int numVertices;
  struct node** adjLists;
};

struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createAGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  int i;

  for (i = 0; i < vertices; i++)
  {
    struct node* newNode = createNode(i+1);
  newNode->next = NULL;
    graph->adjLists[i] = newNode;
  }

  return graph;
}

void addEdge(struct Graph* graph, int s, int d) {
  struct node* newNode = createNode(d+1);
  newNode->next = NULL;

  struct node* temp ;

  temp = graph->adjLists[s];
  while(temp->next!=NULL){
    temp=temp->next;
  }

  temp->next = newNode;
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {


int n;
char edge='n';
printf("Enter number of vertices\n");
scanf("%d",&n);
struct Graph* graph = createAGraph(n);

for (int i = 0; i < n; i++)
{
for (int j = i; j < n; j++)
{
printf("Is there any edge between %d and %d \n",i+1,j+1);
printf("y/n\n");

scanf(" %c",&edge);
if(edge=='y'){
  addEdge(graph, i,j);
  addEdge(graph, j,i);
}

edge='n';

}
}
 
 printf("Adjacency List: \n");
  printGraph(graph);

  return 0;
}

