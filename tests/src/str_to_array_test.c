#include <criterion/criterion.h>

bool array_is_same(char **array, char **array_to_compare);
char **str_to_array(char *str, char separator);

Test(str_to_array, null_test)
{
    char *str = NULL;
    char separator = ' ';
    char **res = str_to_array(str, separator);

    cr_assert(res == NULL, "Expected \"NULL\" but got : bad array");
}

Test(str_to_array, split_without_separator)
{
    char *str = "AZERTYUIOP";
    char separator = ' ';
    char **res = str_to_array(str, separator);
    char *expected[2] = {"AZERTYUIOP", NULL};

    cr_assert(array_is_same(res, expected), "Expected array is not the same.");
}

Test(str_to_array, split_little_str_with_separator)
{
    char *str = "AZER TYU";
    char separator = ' ';
    char **res = str_to_array(str, separator);
    char *expected[3] = {"AZER", "TYU", NULL};

    cr_assert(array_is_same(res, expected), "Expected array is not the same.");
}

Test(str_to_array, split_medium_str_with_separator)
{
    char *str = "AZER TYU IOP YAHOO HEHE";
    char separator = ' ';
    char **res = str_to_array(str, separator);
    char *expected[6] = {"AZER", "TYU", "IOP", "YAHOO", "HEHE", NULL};
 
    cr_assert(array_is_same(res, expected), "Expected array is not the same.");
}

Test(str_to_array, split_large_str_with_separator)
{
    char *str = "AZER TYU IOP YAHOO HEHE, OUI NON TESTTEST";
    char separator = ' ';
    char **res = str_to_array(str, separator);
    char *expected[9] = {"AZER", "TYU", "IOP", "YAHOO", "HEHE,", "OUI", "NON", "TESTTEST", NULL};

    cr_assert(array_is_same(res, expected), "Expected array is not the same.");
}