#include <criterion/criterion.h>
#include "macros.h"

bool str_is_same(char *str, char *str_to_compare);

Test(str_is_same, null_test_one_string)
{
    char *str = "heheha";
    char *str_to_compare = NULL_STR;
    bool res = str_is_same(str, str_to_compare);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_same, null_test_both_strings)
{
    char *str = NULL_STR;
    char *str_to_compare = NULL_STR;
    bool res = str_is_same(str, str_to_compare);
    bool expected = true;

    cr_assert(res == expected, "Expected true but got false");
}

Test(str_is_same, compare_different_size)
{
    char *str = "azera";
    char *str_to_compare = "azerae";
    bool res = str_is_same(str, str_to_compare);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_same, compare_same_size_different_content)
{
    char *str = "azert";
    char *str_to_compare = "yuiop";
    bool res = str_is_same(str, str_to_compare);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_same, compare_same_size_same_content)
{
    char *str = "azert";
    char *str_to_compare = "azert";
    bool res = str_is_same(str, str_to_compare);
    bool expected = true;

    cr_assert(res == expected, "Expected true but got false");
}