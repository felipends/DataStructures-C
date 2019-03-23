#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
 * int Stack Sctruct
*/
typedef struct{
    int *stack;
    int size, top;
} intStack;

void int_push(intStack *s, int val){
    int *temp_stack;
    int temp_size;

    if (s->top < (s->size - 1)){
        s->top++;
        s->stack[s->top] = val;
    } else {
        temp_size = s->size * 2;
        temp_stack = (int *)malloc(temp_size * sizeof(int));
        s->size = temp_size;

        temp_stack = s->stack;
        free(s->stack);

        s->stack = (int *)malloc(s->size * sizeof(int));
        s->stack = temp_stack;

        free(temp_stack);

        s->top++;
        s->stack[s->top] = val;
    }
}

int int_pop(intStack *s){
    int temp;

    if (s->top >= 0){
        temp = s->stack[s->top];
        s->top--;
        return temp;
    } else {
        return 0;
    }
}

/*
 * char Stack Sctruct
*/
typedef struct{
	char* stack;
	int size, top;
} charStack;

void char_push(charStack *s, const char c){
    char* temp_stack;
    int temp_size;

    if (s->top < (s->size - 1)){
        s->top++;
        strncat(s->stack, &c, 1);
    } else {
        temp_size = s->size * 2;
        temp_stack = (char *)malloc(temp_size * sizeof(char));
        strcpy(temp_stack, s->stack);
        
        s->size = temp_size;
        
        free(s->stack);

        s->stack = (char *)malloc(s->size * sizeof(char));    
        strcpy(s->stack, temp_stack);
        
        free(temp_stack);
        
        s->top++;
        strncat(s->stack, &c, 1);
    }
}

char char_pop(charStack* s){
    char temp;
    if(s->top >= 0){
        temp = s->stack[s->top]; 
        s->top--;
 	    return temp; 
    } else {
        return '\0';
    }
}
