#include <criterion/criterion.h>

char *int_to_str(int number);

Test(int_to_str, convert_zero)
{
    char *str = int_to_str(0);
    char *expected = "0";

    cr_assert_str_eq(str, expected, "Expected \"0\", but got \"%s\"", str);
}

Test(int_to_str, convert_negative_number)
{
    char *str = int_to_str(-1932);
    char *expected = "-1932";

    cr_assert_str_eq(str, expected, "Expected \"-1932\", but got \"%s\"", str);
}

Test(int_to_str, convert_little_negative_number)
{
    char *str = int_to_str(-2);
    char *expected = "-2";

    cr_assert_str_eq(str, expected, "Expected \"-2\", but got \"%s\"", str);
}

Test(int_to_str, convert_positive_number)
{
    char *str = int_to_str(1932);
    char *expected = "1932";

    cr_assert_str_eq(str, expected, "Expected \"1932\", but got \"%s\"", str);
}

Test(int_to_str, convert_little_positive_number)
{
    char *str = int_to_str(2);
    char *expected = "2";

    cr_assert_str_eq(str, expected, "Expected \"2\", but got \"%s\"", str);
}