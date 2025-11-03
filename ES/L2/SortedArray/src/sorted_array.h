#ifndef SORTEDARRAY_LIBRARY_H
#define SORTEDARRAY_LIBRARY_H

#include <stdio.h>

typedef struct _SortedArray SortedArray;

SortedArray* sorted_array_init(size_t capacity, unsigned int (*precedes_fun)(const void*, const void*));
unsigned int sorted_array_is_empty(SortedArray* array);
void sorted_array_add(SortedArray* array, const void* elem);
void sorted_array_freemem(SortedArray* array);

#endif // SORTEDARRAY_LIBRARY_H