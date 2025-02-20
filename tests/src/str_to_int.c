#include <criterion/criterion.h>

int str_to_int(const char *str);

Test(str_to_int, null_test)
{
    char *str = NULL;
    int res = str_to_int(str);
    int expected = 0;

    cr_assert_eq(res, expected, "Expected get %d, but got %d", expected, res);
}

Test(str_to_int, not_number)
{
    char *str = "-23fez";
    int res = str_to_int(str);
    int expected = 0;

    cr_assert_eq(res, expected, "Expected get %d, but got %d", expected, res);
}

Test(str_to_int, bad_negative_number_input)
{
    char *str = "1-3232";
    int res = str_to_int(str);
    int expected = 0;

    cr_assert_eq(res, expected, "Expected get %d, but got %d", expected, res);
}

Test(str_to_int, negative_number)
{
    char *str = "-3232";
    int res = str_to_int(str);
    int expected = -3232;

    cr_assert_eq(res, expected, "Expected get %d, but got %d", expected, res);
}

Test(str_to_int, positive_number)
{
    char *str = "13232";
    int res = str_to_int(str);
    int expected = 13232;

    cr_assert_eq(res, expected, "Expected get %d, but got %d", expected, res);
}