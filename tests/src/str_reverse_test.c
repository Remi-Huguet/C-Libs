#include <criterion/criterion.h>
#include "macros.h"

char *str_reverse(char *str);

Test(str_reverse, null_test)
{
    char *str = NULL_STR;
    char *res = str_reverse(str);

    cr_assert(res == NULL_STR, "Expected \"NULL\", but got \"%s\"", str);
}

Test(str_reverse, reverse_short_string)
{
    char *str = "a";
    char *res = str_reverse(str);
    char *expected = "a";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_reverse, reverse_medium_string)
{
    char *str = "azerty";
    char *res = str_reverse(str);
    char *expected = "ytreza";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(str_reverse, reverse_large_string)
{
    char *str = "azertyuiopazertyuiop";
    char *res = str_reverse(str);
    char *expected = "poiuytrezapoiuytreza";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}