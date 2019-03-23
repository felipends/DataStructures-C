#include "../stack_ds.h"
#include <string.h>
#include <stdio.h>

int main(void){
	charStack s = {.top = -1, .size = 10};
	s.stack = (char *)malloc(s.size * sizeof(char));
	
	char str[] = "I am very good at datastructures";
	size_t str_size = strlen(str);
	
	puts(str);

	for(size_t i = 0; i < str_size; i++){
		char_push(&s, str[i]);
	}

	for(size_t i = 0; i < str_size; i++){
		str[i] = char_pop(&s);
	}

	puts(str);

	return 0;
}
