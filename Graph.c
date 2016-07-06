#include <stdio.h>
#include <stdlib.h>

struct list_node{
	
	int node_value;
	struct list_node * next;
	
};

struct Graph{
	int no_of_vertices;
	int no_of_edges;
	struct list_node * adjacent; 
};

struct Graph * G, * G1;
struct list_node * vertex_list;

struct Graph * insert_graph();

int main(int argc, char *argv[]){
	
	G = malloc( sizeof(struct Graph));
	printf ("Enter the no of vertices\n");
	scanf("%d",&G->no_of_vertices);
	printf("Enter the no of Edges\n");
	scanf("%d",&G->no_of_edges);
	vertex_list = malloc ( (G->no_of_edges) * sizeof( struct list_node));
	G->adjacent = vertex_list;
    G1 = insert_graph();
	
}
struct Graph * insert_graph(){
	
	int i,x,y;
	struct list_node *  temp, *t;
	
	
	for (i = 0;i<= G->no_of_vertices-1;i++){
		
		G->adjacent[i].node_value = i;
	    G->adjacent[i].next = G->adjacent+i;
		
	}
	
	printf ("The vertices are as follows\n");
	
	for (i = 0;i<= G->no_of_vertices-1;i++){
		
		printf ("%d\t",G->adjacent[i].node_value);
		
	}
	
	printf("\n");
	for ( i= 0; i<=G->no_of_edges-1;i++){
	
		printf ("Enter the source vertex(u)\n");
		scanf("%d",&x);
		printf("Enter the destination vertex(v)\n");
		scanf("%d",&y);
		temp = malloc (sizeof (struct list_node ));
		temp->node_value = y;
		temp->next = G->adjacent+x;
		t = G->adjacent+x;
		while ( t->next != (G->adjacent+x))
		  t = t->next;
		t->next = temp;
		
	}

  return G;
	
}
