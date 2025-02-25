#include <criterion/criterion.h>
#include <criterion/redirect.h>

void print_char(char c);

Test(print_char, print_a_char)
{
    char c = 'a';
    char *expected = "a";

    cr_redirect_stdout();
    print_char(c);
    cr_assert_stdout_eq_str(expected, "Expected : \"%s\" but got \"%s\"", expected, cr_get_redirected_stdout());
}