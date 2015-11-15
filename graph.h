typedef struct graph { 
	int **a;
	int n;  // distance betn stations //
}graph;

void depthwise(graph *g, int v);
void init(graph *g, int n); // create 2-d array, initialise to zero
void printgraph(graph *g); 

