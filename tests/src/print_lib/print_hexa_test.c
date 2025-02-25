#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdbool.h>

void print_hexa(int number, bool upper);

Test(print_hexa, print_positive_int_lower)
{
    int number = 123;
    bool upper = false;
    char *expected = "7b";

    cr_redirect_stdout();
    print_hexa(number, upper);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_hexa, print_positive_int_upper)
{
    int number = 123;
    bool upper = true;
    char *expected = "7B";

    cr_redirect_stdout();
    print_hexa(number, upper);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_hexa, print_negative_int_lower)
{
    int number = -123;
    bool upper = false;
    char *expected = "-7b";

    cr_redirect_stdout();
    print_hexa(number, upper);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_hexa, print_negative_int_upper)
{
    int number = -123;
    bool upper = true;
    char *expected = "-7B";

    cr_redirect_stdout();
    print_hexa(number, upper);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_hexa, print_little_int)
{
    int number = 7;
    bool upper = true;
    char *expected = "7";

    cr_redirect_stdout();
    print_hexa(number, upper);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_hexa, print_zero)
{
    int number = 0;
    bool upper = true;
    char *expected = "0";

    cr_redirect_stdout();
    print_hexa(number, upper);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}

Test(print_hexa, print_negative_zero)
{
    int number = -0;
    bool upper = true;
    char *expected = "0";

    cr_redirect_stdout();
    print_hexa(number, upper);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got : %s", expected, cr_get_redirected_stdout());
}