#include <criterion/criterion.h>
#include "macros.h"

void *allocate_memory(size_t size);
void free_memory(void *ptr);
void *reallocate_memory(void *ptr, size_t new_size);

Test(reallocate_memory, test_null_ptr)
{
    char *ptr = NULL_POINTER;
    ptr = reallocate_memory(ptr, 10);

    cr_assert_not_null(ptr, "Expected ptr to be not NULL, got %p", ptr);
    free_memory(ptr);
}

Test(reallocate_memory, null_size)
{
    char *ptr = allocate_memory(10);
    ptr = reallocate_memory(ptr, 0);

    cr_assert_null(ptr, "Expected ptr to be NULL, got %p", ptr);
    free_memory(ptr);
}

Test(reallocate_memory, less_memory)
{
    char *ptr = allocate_memory(10);
    ptr = reallocate_memory(ptr, 5);

    cr_assert_not_null(ptr, "Expected ptr to be NULL, got %p", ptr);
    free_memory(ptr);
}

Test(reallocate_memory, same_memory)
{
    char *ptr = allocate_memory(10);
    ptr = reallocate_memory(ptr, 10);

    cr_assert_not_null(ptr, "Expected ptr to be NULL, got %p", ptr);
    free_memory(ptr);
}

Test(reallocate_memory, more_memory)
{
    void *ptr = allocate_memory(10);
    ptr = reallocate_memory(ptr, 15);

    cr_assert_not_null(ptr, "Expected ptr to be NULL, got %p", ptr);
    free_memory(ptr);
}