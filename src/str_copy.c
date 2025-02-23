#include <stdlib.h>
#include <stddef.h>
#include "macros.h"

int str_get_len(char *str);

void str_copy(char **dest, char *str)
{
    if (str == NULL_STR) return;
    *dest = malloc(sizeof(char) * (str_get_len(str) + 1));
    if (dest == NULL_STR || dest == NULL) return;
    int i = 0;

    for (i = 0; str[i] != STR_END; i++) {
        (*dest)[i] = str[i];
    }
    (*dest)[i] = STR_END;
}