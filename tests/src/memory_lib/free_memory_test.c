#include <criterion/criterion.h>
#include "macros.h"

void *allocate_memory(size_t size);
void free_memory(void *ptr);

Test(free_memory, test_small_memory)
{
    void *ptr = allocate_memory(10);

    free_memory(ptr);
    ptr = NULL_POINTER;
    cr_assert_null(ptr, "Expected ptr to be NULL, got %p", ptr);
}

Test(free_memory, test_medium_memory)
{
    void *ptr = allocate_memory(100);

    free_memory(ptr);
    ptr = NULL_POINTER;
    cr_assert_null(ptr, "Expected ptr to be NULL, got %p", ptr);
}

Test(free_memory, test_large_memory)
{
    void *ptr = allocate_memory(1000);

    free_memory(ptr);
    ptr = NULL_POINTER;
    cr_assert_null(ptr, "Expected ptr to be NULL, got %p", ptr);
}

Test(free_memory, test_null_memory)
{
    void *ptr = allocate_memory(0);

    free_memory(ptr);
    cr_assert_null(ptr, "Expected ptr to be NULL, got %p", ptr);
}