#include <stddef.h>

int array_get_len(char **array)
{
    if (array == NULL) {
        return 0;
    }
    int i = 0;

    while (array[i] != NULL) {
        i++;
    }
    return i;
}