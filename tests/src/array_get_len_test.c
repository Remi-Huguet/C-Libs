#include <criterion/criterion.h>

int array_get_len(char **array);

Test(array_get_len, get_the_len_of_big_array)
{
    char *array[11] = {"azer", "azeraz", "azer", "azerazr", "azerazer", "azer", "azeraz", "azer", "azerazr", "azerazer", NULL};
    int len = array_get_len(array);
    int expected = 10;

    cr_assert_eq(len, expected, "Expected length 10, but got %d", len);
}

Test(array_get_len, get_the_len_of_medium_array)
{
    char *array[6] = {"azer", "azeraz", "azer", "azerazr", "azerazer", NULL};
    int len = array_get_len(array);
    int expected = 5;

    cr_assert_eq(len, expected, "Expected length 5, but got %d", len);
}

Test(array_get_len, get_the_len_of_little_array)
{
    char *array[2] = {"azer", NULL};
    int len = array_get_len(array);
    int expected = 1;

    cr_assert_eq(len, expected, "Expected length 1, but got %d", len);
}

Test(array_get_len, get_the_len_of_empty_array)
{
    char *array[] = {NULL};
    int len = array_get_len(array);
    int expected = 0;

    cr_assert_eq(len, expected, "Expected length 0, but got %d", len);
}

Test(array_get_len, null_test)
{
    int len = array_get_len(NULL);
    int expected = 0;

    cr_assert_eq(len, expected, "Expected length 0, but got %d", len);
}