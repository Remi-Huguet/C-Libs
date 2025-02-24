#include <criterion/criterion.h>
#include <criterion/redirect.h>

void print_char(char c);

Test(print_char, print_a_char)
{
    cr_redirect_stdout();
    print_char('a');
    cr_assert_stdout_eq_str("a");
}