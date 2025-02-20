#include <criterion/criterion.h>

bool str_is_same(char *str, char *dist);

Test(str_is_same, null_test_one_string)
{
    bool res = str_is_same("heheha", NULL);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_same, null_test_both_strings)
{
    bool res = str_is_same(NULL, NULL);
    bool expected = true;

    cr_assert(res == expected, "Expected true but got false");
}

Test(str_is_same, compare_different_size)
{
    int res = str_is_same("azera", "azerae");
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_same, compare_same_size_different_content)
{
    int res = str_is_same("azert", "yuiop");
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_same, compare_same_size_same_content)
{
    bool res = str_is_same("azert", "azert");
    bool expected = true;

    cr_assert(res == expected, "Expected true but got false");
}