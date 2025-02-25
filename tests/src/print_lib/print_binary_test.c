#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdbool.h>

void print_binary(int number);

Test(print_binary, print_positive_binary)
{
    int number = 72;
    char *expected = "1001000";

    cr_redirect_stdout();
    print_binary(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_binary, print_negative_binary)
{
    int number = -72;
    char *expected = "-1001000";

    cr_redirect_stdout();
    print_binary(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_binary, print_null_binary)
{
    int number = 0;
    char *expected = "0";

    cr_redirect_stdout();
    print_binary(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}