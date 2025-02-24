#include <criterion/criterion.h>
#include <criterion/redirect.h>

void print_int(int number);

Test(print_int, print_positive_int)
{
    cr_redirect_stdout();
    print_int(123);
    cr_assert_stdout_eq_str("123");
}

Test(print_int, print_negative_int)
{
    cr_redirect_stdout();
    print_int(-123);
    cr_assert_stdout_eq_str("-123");
}

Test(print_int, print_zero)
{
    cr_redirect_stdout();
    print_int(0);
    cr_assert_stdout_eq_str("0");
}