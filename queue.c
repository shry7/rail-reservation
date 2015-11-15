#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
void qinit(queue *q) {
	q->head = NULL;
	q->tail = NULL;
}
void enqueue(queue *q, int ch) {
	struct node *tmp;
	tmp = (node *)malloc(sizeof(node));
	if(tmp == NULL) {
		exit(1);
	}
	tmp->ch = ch;
	tmp->next = NULL;	
	if(q->tail)
		q->tail->next = tmp;
	else
		q->head = tmp;
	q->tail = tmp;
}

int dequeue(queue *q) {
	int x = q->head->ch;
	node *tmp = q->head;
	q->head = q->head->next; // head pointer goes to next node
	free(tmp);// free the first nodej
	if(q->head == NULL)
		q->tail = NULL;
	return x; // return the int in first node
}
int qempty(queue *q) {
	return q->head == NULL;
}
int qfull(queue *q) { 
	return 0;
}
void qprint(queue *q) {

}
