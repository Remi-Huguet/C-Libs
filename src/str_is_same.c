#include <stdbool.h>
#include <stddef.h>

int str_get_len(char *str);

bool str_is_same(char *str, char *dist)
{
    if (str == NULL || dist == NULL || str_get_len(str) != str_get_len(dist)) {
        return false;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != dist[i]) {
            return false;
        }
    }
    return true;
}