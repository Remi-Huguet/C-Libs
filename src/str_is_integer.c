#include <stdbool.h>
#include <stddef.h>

int str_get_len(char *str);

bool str_is_integer(char *str)
{
    if (str == NULL) {
        return 0;
    }
    int i = 0;

    if (str_get_len(str) > 1 && str[0] == '-') {
        i++;
    }
    for (i = i; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}