#include <criterion/criterion.h>
#include "macros.h"

char *str_duplicate(char *str);

Test(str_duplicate, null_test)
{
    char *res = NULL_STR;
    char *str = NULL_STR;
    res = str_duplicate(str);
    char *expected = NULL_STR;

    cr_assert(res == expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_duplicate, short_string)
{
    char *res = NULL_STR;
    char *str = "Oui";
    res = str_duplicate(str);
    char *expected = "Oui";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_duplicate, medium_string)
{
    char *res = NULL_STR;
    char *str = "Azertyuiop";
    res = str_duplicate(str);
    char *expected = "Azertyuiop";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_duplicate, large_string)
{
    char *res = NULL_STR;
    char *str = "AzertyuiopQsdfghjklm";
    res = str_duplicate(str);
    char *expected = "AzertyuiopQsdfghjklm";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_duplicate, multiple_duplicate)
{
    char *res = NULL_STR;
    char *str = "Azertyuiop";
    char *str2 = "Qsdfghjklm";
    res = str_duplicate(str);
    res = str_duplicate(str2);
    char *expected = "Qsdfghjklm";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}