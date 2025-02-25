#include <criterion/criterion.h>
#include <criterion/redirect.h>

void print_octal(int number);

Test(print_octal, print_positive_int)
{
    int number = 64;
    char *expected = "100";

    cr_redirect_stdout();
    print_octal(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_octal, print_positive_grand_int)
{
    int number = 162892;
    char *expected = "476114";

    cr_redirect_stdout();
    print_octal(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_octal, print_negative_int)
{
    int number = -64;
    char *expected = "-100";

    cr_redirect_stdout();
    print_octal(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_octal, print_zero)
{
    int number = 0;
    char *expected = "0";

    cr_redirect_stdout();
    print_octal(number);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}