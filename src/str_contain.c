#include <stdbool.h>
#include <stddef.h>

bool str_contain(char *str, char c)
{
    if (str == NULL) {
        return false;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}