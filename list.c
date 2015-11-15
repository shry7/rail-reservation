#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void init(list *l) {
	l->head = l->tail = NULL;
	l->length = 0;
}
void traverse(list *l) {
	printf("Forwards: [ ");
	node *p = l->head;
	while(p != l->tail) {
		printf("%s %d %u %u\n", p->str, p->fare, p->arrive, p->dept );
		p = p->next;
	}
	if(p)
		printf("%s %d %u %u\n", p->str, p->fare, p->arrive, p->dept ); 
	printf(" ]\n");

}
/* can insert at positions [0..length] */
void insert(list *l, char *str, int pos) {
	node *p, *tmp;
	int i;
	if(pos < 0 || pos > l->length)		
		return;

	tmp = (node *)malloc(sizeof(node));
	tmp->str = (char *)malloc(strlen(str) + 1);
	strcpy(tmp->str, str);
	if(l->head == NULL) {
		tmp->next = tmp->prev = 
		l->head = l->tail = tmp;
		l->length = 1;
		return;
	}
	/* assert: posoitin is =>0 && <= length */
	p = l->head;
	for(i = 0; i < pos - 1; i++)
		p = p->next;
	if(pos == 0)
		p = p->prev;
	/* assert: p points to the node after which we link tmp*/

	tmp->prev = p;	
	tmp->next = p->next;
	p->next->prev = tmp;
	p->next = tmp;
	if(pos == l->length)
		l->tail = tmp;
	if(pos == 0)
		l->head = tmp;
	(l->length)++;
}


int length(list *l) {
	return l->length ;	
}



