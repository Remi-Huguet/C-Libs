#include <criterion/criterion.h>
#include <stdbool.h>
#include "macros.h"

bool str_contain(char *str, char c);

Test(str_contain, null_test)
{
    char *str = NULL_STR;
    char c = 'a';
    bool res = str_contain(str, c);
    bool expected = false;

    cr_assert(res == expected, "Can't find %c in %s", c, str);
}

Test(str_contain, check_if_contain)
{
    char *str = "Oh Que oui";
    char c = 'Q';
    bool res = str_contain(str, c);
    bool expected = true;

    cr_assert(res == expected, "Can't find %c in %s", c, str);
}

Test(str_contain, check_if_not_contain)
{
    char *str = "Oh Que oui";
    char c = 'Z';
    bool res = str_contain(str, c);
    bool expected = false;

    cr_assert(res == expected, "Can't find %c in %s", c, str);
}