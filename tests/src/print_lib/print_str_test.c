#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "macros.h"

void print_str(char *str);

Test(print_str, print_a_str)
{
    char *str = "Hello, World!";
    char *expected = "Hello, World!";

    cr_redirect_stdout();
    print_str(str);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_str, print_a_empty_str)
{
    char *str = "";
    char *expected = "";

    cr_redirect_stdout();
    print_str(str);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_str, null_test)
{
    char *str = NULL_STR;
    char *expected = "";

    cr_redirect_stdout();
    print_str(str);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}