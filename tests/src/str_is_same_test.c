#include <criterion/criterion.h>

bool str_is_same(char *str, char *dist);

Test(str_is_same, null_test_one_string)
{
    char *str = "heheha";
    char *dist = NULL;
    bool res = str_is_same(str, dist);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_same, null_test_both_strings)
{
    char *str = NULL;
    char *dist = NULL;
    bool res = str_is_same(str, dist);
    bool expected = true;

    cr_assert(res == expected, "Expected true but got false");
}

Test(str_is_same, compare_different_size)
{
    char *str = "azera";
    char *dist = "azerae";
    bool res = str_is_same(str, dist);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_same, compare_same_size_different_content)
{
    char *str = "azert";
    char *dist = "yuiop";
    bool res = str_is_same(str, dist);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_same, compare_same_size_same_content)
{
    char *str = "azert";
    char *dist = "azert";
    bool res = str_is_same(str, dist);
    bool expected = true;

    cr_assert(res == expected, "Expected true but got false");
}