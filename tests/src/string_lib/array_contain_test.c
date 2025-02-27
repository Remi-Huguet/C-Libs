#include <criterion/criterion.h>
#include "macros.h"

bool array_contain(char **array, char *str);

Test(array_contain, null_test_array)
{
    char **array = NULL_ARRAY;
    char *str = "YAHOO";
    bool res = array_contain(array, str);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(array_contain, null_test_str)
{
    char **array = NULL_ARRAY;
    char *str = NULL_STR;
    bool res = array_contain(array, str);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(array_contain, array_contain_str)
{
    char *array[6] = {"azer", "ououi", "grngaeuig", "  fzf  ", "YAHOOO", ARRAY_END};
    char *str = "YAHOOO";
    bool res = array_contain(array, str);
    bool expected = true;

    cr_assert(res == expected, "Expected false but got true");
}

Test(array_contain, array_not_contain_str)
{
    char *array[6] = {"azer", "ououi", "grngaeuig", "  fzf  ", "heheha", ARRAY_END};
    char *str = "YAHOOO";
    bool res = array_contain(array, str);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}