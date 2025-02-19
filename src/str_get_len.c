#include <stddef.h>

int str_get_len(char *str)
{
    if (str == NULL) {
        return 0;
    }
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}