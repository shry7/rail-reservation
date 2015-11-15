
typedef struct node {
	int ch;
	struct node *next;
}node;

typedef struct queue {
	struct node *head, *tail;
}queue;

void qinit(queue *q);
void enqueue(queue *q, int ch);
int dequeue(queue *q);
int qempty(queue *q);
int qfull(queue *q); 
