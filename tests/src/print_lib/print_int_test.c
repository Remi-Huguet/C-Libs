#include <criterion/criterion.h>
#include <criterion/redirect.h>

void print_int(int number);

Test(print_int, print_positive_int)
{
    int number = 123;
    char *expected = "123";

    cr_redirect_stdout();
    print_int(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_int, print_negative_int)
{
    int number = -123;
    char *expected = "-123";

    cr_redirect_stdout();
    print_int(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_int, print_zero)
{
    int number = 0;
    char *expected = "0";

    cr_redirect_stdout();
    print_int(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_int, print_negative_zero)
{
    int number = -0;
    char *expected = "0";

    cr_redirect_stdout();
    print_int(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}