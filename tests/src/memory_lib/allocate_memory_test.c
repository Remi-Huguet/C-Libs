#include <criterion/criterion.h>
#include "macros.h"

void *allocate_memory(size_t size);
void free_memory(void *ptr);

Test(allocate_memory, test_small_memory)
{
    void *ptr = allocate_memory(10);

    cr_assert_not_null(ptr, "Expected ptr to be not NULL, got %p", ptr);
    free_memory(ptr);
}

Test(allocate_memory, test_medium_memory)
{
    void *ptr = allocate_memory(100);

    cr_assert_not_null(ptr, "Expected ptr to be not NULL, got %p", ptr);
    free_memory(ptr);
}

Test(allocate_memory, test_large_memory)
{
    void *ptr = allocate_memory(1000);

    cr_assert_not_null(ptr, "Expected ptr to be not NULL, got %p", ptr);
    free_memory(ptr);
}

Test(allocate_memory, test_null_memory)
{
    void *ptr = allocate_memory(0);

    cr_assert_null(ptr, "Expected ptr to be NULL, got %p", ptr);
}