#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#include "queue.h"
#include <errno.h>
int main(int argc, char *argv[]) {
	FILE *fp;
	graph g;
	int n, x, i, j;
	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		perror("fopen failed:");
		return errno;
	}
	fscanf(fp, "%d", &n);
	init(&g, n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			fscanf(fp, "%d", &x);	
			if(x)
				insertedge(&g, i, j, x);
		}
	printgraph(&g);
	for(i = 0; i < n; i++)  {
		printf("DFS: ");
		depthwise(&g, i);
	}
	for(i = 0; i < n; i++)  {
		printf("BFS: ");
		levelwise(&g, i);
	}
	return 0;
}

typedef struct edge {
	int s, d;
}edge;

void dfs(graph *g, int v, int *visited) {
	int i;
	printf("%d ", v);
	visited[v] = 1;
	for(i = 0; i < g->n; i++)
		if(g->a[v][i] && !visited[i])
			dfs(g, i, visited);
}
void depthwise(graph *g, int v) {
	int i;
	int *visited = (int *)malloc(g->n * sizeof(int));
	for(i = 0; i < g->n; i++)
		visited[i] = 0;
	printf("[ ");
	dfs(g, v, visited);	
	printf("]\n");
}
void init(graph *g, int n) {
	int i, j;
	g->a = (int **) malloc(n * sizeof(int *));	
	g->n = n;
	for(i = 0; i < n; i++) {
		g->a[i] = (int *)malloc(sizeof(int) * n);
		for(j = 0; j < n; j++)
			g->a[i][j] = 0;	
	}
} // create 2-d array, initialise to zero
void printgraph(graph *g) {
	int i, j;
	printf("Graph: %d\n", g->n);
	for(i = 0; i < g->n; i++)  {
		printf("%d: ", i);
		for(j = 0; j < g->n; j++)
			printf("%d ", g->a[i][j]);
		printf("\n");
	}
}

