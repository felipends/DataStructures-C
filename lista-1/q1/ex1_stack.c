/************ Check parentheses balance ***************/

#include <stdio.h>
#include <stdlib.h>
#include "../stack_ds.h"

int main(void)
{
    intStack s = {.top = -1, .size = 10};
    s.stack = (int *)malloc(s.size * sizeof(int));

    size_t text_size = 10;
    char *text = (char *) malloc(text_size * sizeof(char));

    int flag = 1;

    int pop_result;
    
    size_t size_count = 0;
    int i = 0;
    while (1)
    {
        scanf("%c", &text[i]);
	size_count++;
	if (size_count > text_size)
	    text = (char *) realloc(text, text_size * 2);
        if (text[i] == '\n')
            break;
        if (text[i] == '(')
        {
            int_push(&s, 1);
        }
        else if (text[i] == ')')
        {
            pop_result = int_pop(&s);
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

    free(s.stack);
    free(text);

    return 0;
}
