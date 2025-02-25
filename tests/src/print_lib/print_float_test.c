#include <criterion/criterion.h>
#include <criterion/redirect.h>

void print_float(float number, int precision);

Test(print_float, print_negative_lower_same_prec)
{
    float number = -123.456;
    int precision = 1;
    char *expected = "-123.4";

    cr_redirect_stdout();
    print_float(number, precision);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_float, print_negative_float_same_prec)
{
    float number = -123.456;
    int precision = 3;
    char *expected = "-123.456";

    cr_redirect_stdout();
    print_float(number, precision);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_float, print_negative_float_higher_prec)
{
    float number = -123.456;
    int precision = 5;
    char *expected = "-123.45600";

    cr_redirect_stdout();
    print_float(number, precision);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_float, print_positive_float_lower_prec)
{
    float number = 123.456;
    int precision = 1;
    char *expected = "123.4";

    cr_redirect_stdout();
    print_float(number, precision);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_float, print_positive_float_same_prec)
{
    float number = 123.456;
    int precision = 3;
    char *expected = "123.456";

    cr_redirect_stdout();
    print_float(number, precision);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_float, print_positive_float_higher_prec)
{
    float number = 123.456;
    int precision = 5;
    char *expected = "123.45600";

    cr_redirect_stdout();
    print_float(number, precision);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_float, print_negative_zero)
{
    float number = -0;
    int precision = 1;
    char *expected = "0.0";

    cr_redirect_stdout();
    print_float(number, precision);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_float, print_positive_zero_with_prec)
{
    float number = 0;
    int precision = 5;
    char *expected = "0.00000";

    cr_redirect_stdout();
    print_float(number, precision);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}