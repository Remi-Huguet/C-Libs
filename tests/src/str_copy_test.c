#include <criterion/criterion.h>
#include <stddef.h>
#include "macros.h"

void str_copy(char **dest, char *str);

Test(str_copy, null_test)
{
    char *res = NULL_STR;
    char *str = NULL_STR;
    char *expected = NULL_STR;
    str_copy(&res, str);

    cr_assert(res == expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_copy, short_string)
{
    char *res = NULL_STR;
    char *str = "Oui";
    char *expected = "Oui";
    str_copy(&res, str);

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_copy, medium_string)
{
    char *res = NULL_STR;
    char *str = "Azertyuiop";
    char *expected = "Azertyuiop";
    str_copy(&res, str);

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_copy, large_string)
{
    char *res = NULL_STR;
    char *str = "Azertyuiop Qsdfghjklm";
    char *expected = "Azertyuiop Qsdfghjklm";
    str_copy(&res, str);

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}