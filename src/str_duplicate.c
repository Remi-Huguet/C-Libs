#include <stddef.h>
#include <stdlib.h>
#include "macros.h"

int str_get_len(char *str);
void str_copy(char **dest, char *str);

char *str_duplicate(char *str)
{
    if (str == NULL_STR) return NULL_STR;
    char *new_str = NULL;

    str_copy(&new_str, str);
    return new_str;
}