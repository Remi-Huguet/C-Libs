#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "macros.h"

void print_formatted(char *str, ...);

Test(print_formatted, str_agr_str)
{
    char *str = "Et oui ! %s";
    char *arg = "YAHOO";
    char *expected = "Et oui ! YAHOO";

    cr_redirect_stdout();
    print_formatted(str, arg);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, str_agr_int)
{
    char *str = "Et oui ! %d";
    int arg = 42;
    char *expected = "Et oui ! 42";

    cr_redirect_stdout();
    print_formatted(str, arg);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, str_agr_char)
{
    char *str = "Et oui ! %c";
    char arg = '!';
    char *expected = "Et oui ! !";

    cr_redirect_stdout();
    print_formatted(str, arg);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, str_arg_percent)
{
    char *str = "Et oui ! %%";
    char *expected = "Et oui ! %";

    cr_redirect_stdout();
    print_formatted(str);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, str_agr_hexa)
{
    char *str = "Et oui ! %x";
    int arg = 123;
    char *expected = "Et oui ! 7b";

    cr_redirect_stdout();
    print_formatted(str, arg);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, str_agr_octal)
{
    char *str = "Et oui ! %o";
    int arg = 64;
    char *expected = "Et oui ! 100";

    cr_redirect_stdout();
    print_formatted(str, arg);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, str_agr_binary)
{
    char *str = "Et oui ! %b";
    int arg = 72;
    char *expected = "Et oui ! 1001000";

    cr_redirect_stdout();
    print_formatted(str, arg);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, str_agr_float)
{
    char *str = "Et oui ! %f";
    float arg = 72.2387;
    char *expected = "Et oui ! 72.238700";

    cr_redirect_stdout();
    print_formatted(str, arg);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, str_agrs_multiple)
{
    char *str = "Et oui ! %fheheha%cquoi%%";
    float arg_1 = 72.2387;
    char arg_2 = '!';
    char *expected = "Et oui ! 72.238700heheha!quoi%";

    cr_redirect_stdout();
    print_formatted(str, arg_1, arg_2);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, empty_print)
{
    char *str = "";
    char *expected = "";

    cr_redirect_stdout();
    print_formatted(str);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, null_test)
{
    char *str = NULL_STR;
    char *expected = "";

    cr_redirect_stdout();
    print_formatted(str);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}

Test(print_formatted, without_agrs)
{
    char *str = "Et oui !";
    char *expected = "Et oui !";

    cr_redirect_stdout();
    print_formatted(str);
    cr_assert_stdout_eq_str(expected, "Expected \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}