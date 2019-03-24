#include "../../linked-list_ds.h"
#include <stdio.h>

/*
 * stack singly linked list based
 */ 
typedef struct{
	struct slList* stack;
	struct sllNode* top;
	int size;
}sllStack;

void sll_push(sllStack* s, struct sllNode* n){
	sll_prepend(s->stack, n);
	s->top = s->stack->head;
	s->size++;
}

struct sllNode* sll_pop(sllStack* s){
	struct sllNode* temp = (struct sllNode*)malloc(sizeof(struct sllNode));
	temp = s->stack->head;
	s->stack->head = temp->next;
	s->top = s->stack->head;

	s->size--;
	s->stack->size--;
	return temp;
}

int main(void){
	sllStack* s = (sllStack *)malloc(sizeof(sllStack));
	s->stack = (struct slList *)malloc(sizeof(struct slList));
	s->stack->head = NULL;
	s->stack->size = 0;
	s->top = (struct sllNode *)malloc(sizeof(struct slList));
	s->size = 0;

	struct sllNode* n1 = (struct sllNode *)malloc(sizeof(struct sllNode));
	n1->val = 1;
	n1->next = NULL;

	sll_push(s, n1);

	struct sllNode* n2 = (struct sllNode *)malloc(sizeof(struct sllNode));
	n2->val = 2;
	n2->next = NULL;

	sll_push(s, n2);

	struct sllNode* n3 = (struct sllNode *)malloc(sizeof(struct sllNode));
	n3->val = 3;
	n3->next = NULL;

	sll_push(s, n3);	
	sll_pop(s);

	printf("%i\n", s->top->val);

	return 0;
}
