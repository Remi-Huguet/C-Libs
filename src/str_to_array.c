#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

int str_get_len(char *str);

char **str_to_array(char *str, char separator)
{
    if (str == POINTER_ERROR) return NULL_STR;
    int len = str_get_len(str);
    char **array = malloc(sizeof(char *) * len);
    if (array == MALLOC_ERROR) return NULL_STR;
    int arrayIndex = 0;
    int i = 0;

    while (i < len) {
        while (i < len && str[i] == separator) {
            i++;
        }
        char *line = malloc(sizeof(char) * len);
        if (line == MALLOC_ERROR) return NULL_STR;
        int lineIndex = 0;
 
        while (i < len && str[i] != separator) {
            line[lineIndex] = str[i];
            i++;
            lineIndex++;
            if (i == len || str[i] == separator) {
                line[lineIndex] = STR_END;
                array[arrayIndex]= strdup(line);
                arrayIndex++; 
                free(line);
            }
        }
        i++;
    }
    array[arrayIndex] = ARRAY_END;
    return array;
}