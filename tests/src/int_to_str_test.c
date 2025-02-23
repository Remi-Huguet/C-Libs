#include <criterion/criterion.h>

char *int_to_str(int number);

Test(int_to_str, convert_zero)
{
    int number = 0;
    char *res = int_to_str(number);
    char *expected = "0";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(int_to_str, convert_negative_number)
{
    int number = -1932;
    char *res = int_to_str(number);
    char *expected = "-1932";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(int_to_str, convert_little_negative_number)
{
    int number = -2;
    char *res = int_to_str(number);
    char *expected = "-2";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(int_to_str, convert_positive_number)
{
    int number = 1932;
    char *res = int_to_str(number);
    char *expected = "1932";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}

Test(int_to_str, convert_little_positive_number)
{
    int number = 2;
    char *res = int_to_str(number);
    char *expected = "2";

    cr_assert_str_eq(res, expected, "Expected \"%s\", but got \"%s\"", expected, res);
}