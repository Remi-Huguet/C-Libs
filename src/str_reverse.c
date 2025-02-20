#include <stdlib.h>

int str_get_len(char *str);

char *str_reverse(char *str)
{
    if (str == NULL) {
        return NULL;
    }
    char *str_reversed = malloc(sizeof(char) * str_get_len(str));
    int reversed_index = 0;

    for (int i = str_get_len(str) - 1; i >= 0; i--) {
        str_reversed[reversed_index] = str[i];
        reversed_index++;
    }
    str_reversed[reversed_index] = '\0';
    return str_reversed;
}