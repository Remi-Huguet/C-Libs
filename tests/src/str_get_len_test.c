#include <criterion/criterion.h>

int str_get_len(const char *str);

Test(str_get_len, get_the_len_of_a_empty_string)
{
    char str[] = "";
    int len = str_get_len(str);
    int expected = 0;

    cr_assert_eq(len, expected, "Expected length 5, but got %d", len);
}

Test(str_get_len, get_the_len_of_a_short_string)
{
    char str[] = "He";
    int len = str_get_len(str);
    int expected = 2;

    cr_assert_eq(len, expected, "Expected length 5, but got %d", len);
}

Test(str_get_len, get_the_len_of_a_normal_string)
{
    char str[] = "Hello";
    int len = str_get_len(str);
    int expected = 5;

    cr_assert_eq(len, expected, "Expected length 5, but got %d", len);
}

Test(str_get_len, get_the_len_of_a_large_string)
{
    char str[] = "HelloHelloHelloHelloHelloHelloHelloHelloHelloHello";
    int len = str_get_len(str);
    int expected = 50;

    cr_assert_eq(len, expected, "Expected length 5, but got %d", len);
}

Test(str_get_len, null_test)
{
    char *str = NULL;
    int len = str_get_len(str);
    int expected = 0;

    cr_assert_eq(len, expected, "Expected length 5, but got %d", len);
}