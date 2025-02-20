#include <criterion/criterion.h>

char *str_reverse(char *str);

Test(str_reverse, null_test)
{
    char *str = str_reverse(NULL);
    bool res = false;

    if (str == NULL) {
        res = true;
    }
    cr_assert(res == true, "Expected \"NULL\", but got \"%s\"", str);
}

Test(str_reverse, reverse_short_string)
{
    char *str = str_reverse("a");
    char *expected = "a";

    cr_assert_str_eq(str, expected, "Expected \"%s\", but got \"%s\"", expected, str);
}

Test(str_reverse, reverse_medium_string)
{
    char *str = str_reverse("azerty");
    char *expected = "ytreza";

    cr_assert_str_eq(str, expected, "Expected \"%s\", but got \"%s\"", expected, str);
}

Test(str_reverse, reverse_large_string)
{
    char *str = str_reverse("azertyuiopazertyuiop");
    char *expected = "poiuytrezapoiuytreza";

    cr_assert_str_eq(str, expected, "Expected \"%s\", but got \"%s\"", expected, str);
}