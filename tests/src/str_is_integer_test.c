#include <criterion/criterion.h>

bool str_is_integer(char *str);

Test(str_is_integer, null_test)
{
    char *str = NULL;
    bool res = str_is_integer(str);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_integer, is_not_integer)
{
    char *str = "56ezè879";
    bool res = str_is_integer(str);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_integer, is_positive_integer)
{
    char *str = "2323";
    bool res = str_is_integer(str);
    bool expected = true;

    cr_assert(res == expected, "Expected true but got false");
}

Test(str_is_integer, bad_negative_input)
{
    char *str = "19-823";
    bool res = str_is_integer(str);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(str_is_integer, is_negative_integer)
{
    char *str = "-19823";
    bool res = str_is_integer(str);
    bool expected = true;

    cr_assert(res == expected, "Expected true but got false");
}