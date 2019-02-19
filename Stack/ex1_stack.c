#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *stack;
    int size, top;
} Stack;

void push(Stack *s, int val)
{
    int *temp_stack;
    int temp_size;

    if (s->top < (s->size - 1))
    {
        s->top++;
        s->stack[s->top] = val;
    }
    else
    {
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

int pop(Stack *s)
{
    int temp;

    if (s->top >= 0)
    {
        temp = s->stack[s->top];
        s->top--;
        return temp;
    }
    else
    {
        return 0;
    }
}

typedef struct
{
    char *str;
    int index, size;
} String;

void str_insert(String *s, char c)
{
    char *aux_str;
    int aux_size;

    if (s->index < (s->size - 1))
    {
        s->index++;
        s->str[s->index] = c;
    }
    else
    {
        aux_size = s->size * 2;
        aux_str = (char *)malloc(aux_size * sizeof(char));
        aux_str = s->str;
        free(s->str);

        s->size = aux_size;
        s->str = (char *)malloc(s->size * sizeof(char));
        s->str = aux_str;

        free(aux_str);

        s->index++;
        s->str[s->index] = c;
    }
}

int main(void)
{
    Stack s = {.top = -1, .size = 10};
    s.stack = (int *)malloc(s.size * sizeof(int));

    String text = {.index = -1, .size = 10};
    text.str = (char *)malloc(text.size * sizeof(char));

    int flag = 1;

    int pop_result;

    int i = 0;
    while (1)
    {
        scanf("%c", &text.str[i]);
        if (text.str[i] == '\n')
            break;
        if (text.str[i] == '(')
        {
            push(&s, 1);
        }
        else if (text.str[i] == ')')
        {
            pop_result = pop(&s);
            if (pop_result == 0)
            {
                flag = 0;
                break;
            }
        }
        i++;
    }

    if (s.top >= 0)
        flag = 0;

    if (flag == 1)
        puts("correct");
    else
        puts("incorrect");

    return 0;
}