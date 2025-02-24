#include <criterion/criterion.h>
#include "macros.h"

int str_get_len(const char *str);

Test(str_get_len, get_the_len_of_a_empty_string)
{
    char str[] = "";
    int res = str_get_len(str);
    int expected = 0;

    cr_assert(res == expected, "Expected length 5, but got %d", res);
}

Test(str_get_len, get_the_len_of_a_short_string)
{
    char str[] = "He";
    int res = str_get_len(str);
    int expected = 2;

    cr_assert(res == expected, "Expected length 5, but got %d", res);
}

Test(str_get_len, get_the_len_of_a_normal_string)
{
    char str[] = "Hello";
    int res = str_get_len(str);
    int expected = 5;

    cr_assert(res == expected, "Expected length 5, but got %d", res);
}

Test(str_get_len, get_the_len_of_a_large_string)
{
    char str[] = "HelloHelloHelloHelloHelloHelloHelloHelloHelloHello";
    int res = str_get_len(str);
    int expected = 50;

    cr_assert(res == expected, "Expected length 5, but got %d", res);
}

Test(str_get_len, null_test)
{
    char *str = NULL_STR;
    int res = str_get_len(str);
    int expected = 0;

    cr_assert(res == expected, "Expected length 5, but got %d", res);
}