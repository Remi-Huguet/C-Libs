#include "macros.h"
#include "memory.h"
#include <unistd.h>

void free_memory(void *ptr)
{
    if (ptr == NULL_POINTER) return;
    block_t *block = (block_t*)ptr - 1;

    block->free = 1;
    if (block->next && block->next->free) {
        block->size += sizeof(block_t) + block->next->size;
        block->next = block->next->next;
        if (block->next) {
            block->next->prev = block;
        }
        free_memory((void *)(block + 1));
    }
    if (block->prev && block->prev->free) {
        block->prev->size += sizeof(block_t) + block->size;
        block->prev->next = block->next;
        if (block->next) {
            block->next->prev = block->prev;
        }
        free_memory((void *)(block->prev + 1));
    }
    if (!block->next) {
        if (block->prev) {
            block->prev->next = NULL_BLOCK;
        } else {
            head = NULL_BLOCK;
        }
        brk(block);
    }
}