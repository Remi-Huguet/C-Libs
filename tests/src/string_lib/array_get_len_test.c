#include <criterion/criterion.h>
#include "macros.h"

int array_get_len(char **array);

Test(array_get_len, get_the_len_of_big_array)
{
    char *array[11] = {"azer", "azeraz", "azer", "azerazr", "azerazer", "azer", "azeraz", "azer", "azerazr", "azerazer", ARRAY_END};
    int res = array_get_len(array);
    int expected = 10;

    cr_assert(res == expected, "Expected length %d, but got %d", expected, res);
}

Test(array_get_len, get_the_len_of_medium_array)
{
    char *array[6] = {"azer", "azeraz", "azer", "azerazr", "azerazer", ARRAY_END};
    int res = array_get_len(array);
    int expected = 5;

    cr_assert(res == expected, "Expected length %d, but got %d", expected, res);
}

Test(array_get_len, get_the_len_of_little_array)
{
    char *array[2] = {"azer", NULL};
    int res = array_get_len(array);
    int expected = 1;

    cr_assert(res == expected, "Expected length %d, but got %d", expected, res);
}

Test(array_get_len, get_the_len_of_empty_array)
{
    char *array[] = {ARRAY_END};
    int res = array_get_len(array);
    int expected = 0;

    cr_assert(res == expected, "Expected length %d, but got %d", expected, res);
}

Test(array_get_len, null_test)
{
    char **array = NULL_ARRAY;
    int res = array_get_len(array);
    int expected = 0;

    cr_assert(res == expected, "Expected length %d, but got %d", expected, res);
}