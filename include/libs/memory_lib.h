#ifndef MEMORY_LIB_H_
#define MEMORY_LIB_H_

void *allocate_memory(size_t size);
void free_memory(void *ptr);
void *reallocate_memory(void *ptr, size_t new_size);

#endif /* !MEMORY_LIB_H_ */