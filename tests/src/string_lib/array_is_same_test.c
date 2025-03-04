#include <criterion/criterion.h>
#include "macros.h"

bool array_is_same(char **array, char **array_to_compare);

Test(array_is_same, null_test_one_array)
{
    char **array = NULL_ARRAY;
    char *array_to_compare[3] = {"azerzaer", "azerazer", ARRAY_END};
    bool res = array_is_same(array, array_to_compare);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(array_is_same, null_test_both_arrays)
{
    char **array = NULL_ARRAY;
    char **array_to_compare = NULL_ARRAY;
    bool res = array_is_same(array, array_to_compare);
    bool expected = true;

    cr_assert(res == expected, "Expected true but got false");
}

Test(array_is_same, compare_different_size)
{
    char *array[4] = {"azerzaer", "azerazer", "BEAZOEZE", ARRAY_END};
    char *array_to_compare[3] = {"azerzaer", "azerazer", ARRAY_END};
    bool res = array_is_same(array, array_to_compare);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(array_is_same, compare_same_size_different_content)
{
    char *array[3] = {"azerzaer", "zeacrzerazer", ARRAY_END};
    char *array_to_compare[3] = {"azerzaer", "azerazer", ARRAY_END};
    bool res = array_is_same(array, array_to_compare);
    bool expected = false;

    cr_assert(res == expected, "Expected false but got true");
}

Test(array_is_same, compare_same_size_same_content)
{
    char *array[3] = {"azerzaer", "zeacrzerazer", ARRAY_END};
    char *array_to_compare[3] = {"azerzaer", "zeacrzerazer", ARRAY_END};
    bool res = array_is_same(array, array_to_compare);
    bool expected = true;

    cr_assert(res == expected, "Expected true but got false");
}