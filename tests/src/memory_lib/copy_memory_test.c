#include <criterion/criterion.h>
#include "macros.h"

void *copy_memory(void *dest, const void *src, size_t n);

Test(copy_memory, null_test)
{
    void *ptr = copy_memory(NULL_POINTER, NULL_POINTER, 10);

    cr_assert_null(ptr, "Expected ptr to be NULL, got %p", ptr);
}

Test(copy_memory, null_dest)
{
    char *src = "Hello, World!";
    void *ptr = copy_memory(NULL_POINTER, src, 10);

    cr_assert_null(ptr, "Expected ptr to be NULL, got %p", ptr);
}

Test(copy_memory, null_src)
{
    char dest[20];
    void *ptr = copy_memory(dest, NULL_POINTER, 10);

    cr_assert_null(ptr, "Expected ptr to be NULL, got %p", ptr);
}

Test(copy_memory, copy_memory)
{
    char src[] = "Hello, World!";
    char dest[20];
    void *ptr = copy_memory(dest, src, 15);

    cr_assert_not_null(ptr, "Expected ptr to be not NULL, got %p", ptr);
    cr_assert_str_eq(dest, "Hello, World!", "Expected dest to be 'Hello, World!', got '%s'", dest);
}