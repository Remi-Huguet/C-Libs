#include <stdbool.h>
#include <stddef.h>
#include "macros.h"

int str_get_len(char *str);

bool str_is_same(char *str, char *dist)
{
    if (str == POINTER_ERROR && dist == POINTER_ERROR) {
        return true;
    }
    if (str == POINTER_ERROR || dist == POINTER_ERROR) return false;
    if (str_get_len(str) != str_get_len(dist)) {
        return false;
    }
    for (int i = 0; str[i] != STR_END; i++) {
        if (str[i] != dist[i]) {
            return false;
        }
    }
    return true;
}