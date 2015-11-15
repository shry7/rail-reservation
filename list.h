typedef struct node {
	int fare;
	time_t arrive;
	time_t dept;
	char tname;
	struct node *next, *prev;
}node;

typedef struct list {
	struct node *head, *tail;
	int length;
}list;

void init(list *l);
void traverse(list *l);
void insert(list *l, char *str, int pos);


