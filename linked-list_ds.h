#include <stdlib.h>

/*
 * int Singly linked list definition
 */
//node of an int singly linked list
struct sllNode{
	int val;
	struct sllNode* next;
};

//descriptor of singly linked list
struct slList{
	int size;
	struct sllNode* head;
};

void sll_append(struct slList* list, struct sllNode* n){
	struct sllNode* temp = (struct sllNode *)malloc(sizeof(struct sllNode)); 

	temp = list->head;
	
	if(temp == NULL){
		list->head = n;
		n->next = NULL;
	} else {
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = n;		
	}
	list->size++;
	
	free(temp);
}

void sll_prepend(struct slList* list, struct sllNode* n){
	if(list->head == NULL){
		list->head = n;
		n->next = NULL;
	} else {
		n->next = list->head;
		list->head = n;
	}

	list->size++;
}

void sll_insert_after(struct slList* list, struct sllNode* n1, struct sllNode* n){
	struct sllNode* temp = (struct sllNode*)malloc(sizeof(struct sllNode));
	temp->next = n1->next;

	n->next = temp->next;
	n1->next = n;

	list->size++;

	free(temp);	
}
