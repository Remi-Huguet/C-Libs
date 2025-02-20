#include <stdbool.h>
#include <stddef.h>

int array_get_len(char **array);
bool str_is_same(char *str, char *dist);

bool array_is_same(char **array, char **array_to_compare)
{
    if (array == NULL && array_to_compare == NULL) {
        return true;
    }
    if (array == NULL || array_to_compare == NULL || array_get_len(array) != array_get_len(array_to_compare)) {
        return false;
    }
    for (int i = 0; array[i] != NULL; i++) {
        if (!str_is_same(array[i], array_to_compare[i])) {
            return false;
        }
    }
    return true;
}