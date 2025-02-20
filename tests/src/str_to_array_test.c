#include <criterion/criterion.h>

bool array_is_same(char **array, char **array_to_compare);
char **str_to_array(char *str, char separator);

Test(str_to_array, null_test)
{
    char *str = NULL;
    char separator = ' ';
    char **array = str_to_array(str, separator);
    bool res = false;

    if (array == NULL) {
        res = true;
    }
    cr_assert(res == true, "Expected \"NULL\" but got : bad array");
}

Test(str_to_array, split_without_separator)
{
    char *str = "AZERTYUIOP";
    char separator = ' ';
    char **array = str_to_array(str, separator);
    char *expected[2] = {"AZERTYUIOP", NULL};
    bool res = false;

    if (array_is_same(array, expected)) {
        res = true;
    }
    cr_assert(res == true, "Expected array is not the same.");
}

Test(str_to_array, split_little_str_with_separator)
{
    char *str = "AZER TYU";
    char separator = ' ';
    char **array = str_to_array(str, separator);
    char *expected[3] = {"AZER", "TYU", NULL};
    bool res = false;

    if (array_is_same(array, expected)) {
        res = true;
    }
    cr_assert(res == true, "Expected array is not the same.");
}

Test(str_to_array, split_medium_str_with_separator)
{
    char *str = "AZER TYU IOP YAHOO HEHE";
    char separator = ' ';
    char **array = str_to_array(str, separator);
    char *expected[6] = {"AZER", "TYU", "IOP", "YAHOO", "HEHE", NULL};
    bool res = false;

    if (array_is_same(array, expected)) {
        res = true;
    }
    cr_assert(res == true, "Expected array is not the same.");
}

Test(str_to_array, split_large_str_with_separator)
{
    char *str = "AZER TYU IOP YAHOO HEHE, OUI NON TESTTEST";
    char separator = ' ';
    char **array = str_to_array(str, separator);
    char *expected[9] = {"AZER", "TYU", "IOP", "YAHOO", "HEHE,", "OUI", "NON", "TESTTEST", NULL};
    bool res = false;

    if (array_is_same(array, expected)) {
        res = true;
    }
    cr_assert(res == true, "Expected array is not the same.");
}