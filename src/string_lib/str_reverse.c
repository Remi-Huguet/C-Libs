#include <stdlib.h>
#include "macros.h"

int str_get_len(char *str);

char *str_reverse(char *str)
{
    if (str == POINTER_ERROR) return NULL_STR;
    char *str_reversed = malloc(sizeof(str));
    if (str_reversed == MALLOC_ERROR) return NULL_STR;
    int reversed_index = 0;

    for (int i = str_get_len(str) - 1; i >= 0; i--) {
        str_reversed[reversed_index] = str[i];
        reversed_index++;
    }
    str_reversed[reversed_index] = STR_END;
    return str_reversed;
}