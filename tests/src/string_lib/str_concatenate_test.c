#include <criterion/criterion.h>
#include "macros.h"

void str_concatenate(char **dest, char *str);

Test(str_concatenate, null_test)
{
    char *res = "LE DEBUT ";
    char *str = NULL_STR;
    str_concatenate(&res, str);
    char *expected = "LE DEBUT ";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_concatenate, concatenate_short_string)
{
    char *res = "LE DEBUT ";
    char *str = "Oui";
    str_concatenate(&res, str);
    char *expected = "LE DEBUT Oui";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_concatenate, concatenate_empty_string)
{
    char *res = "LE DEBUT ";
    char *str = "";
    str_concatenate(&res, str);
    char *expected = "LE DEBUT ";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_concatenate, concatenate_long_string)
{
    char *res = "LE DEBUT ";
    char *str = "Oui, c'est une longue phrase";
    str_concatenate(&res, str);
    char *expected = "LE DEBUT Oui, c'est une longue phrase";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_concatenate, concatenate_null_dest)
{
    char *res = NULL_STR;
    char *str = "Oui";
    str_concatenate(&res, str);
    char *expected = NULL_STR;

    cr_assert(res == expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_concatenate, multiple_concatenation)
{
    char *res = "LE DEBUT ";
    char *str = "Oui";
    str_concatenate(&res, str);
    str_concatenate(&res, str);
    str_concatenate(&res, str);
    char *expected = "LE DEBUT OuiOuiOui";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}