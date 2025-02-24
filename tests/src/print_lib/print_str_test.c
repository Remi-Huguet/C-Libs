#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "macros.h"

void print_str(char *str);

Test(print_str, print_a_str)
{
    cr_redirect_stdout();
    print_str("Hello, World!");
    cr_assert_stdout_eq_str("Hello, World!");
}

Test(print_str, print_a_empty_str)
{
    cr_redirect_stdout();
    print_str("");
    cr_assert_stdout_eq_str("");
}

Test(print_str, null_test)
{
    cr_redirect_stdout();
    print_str(NULL_STR);
    cr_assert_stdout_eq_str("");
}