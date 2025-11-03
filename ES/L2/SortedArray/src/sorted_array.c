#include "sorted_array.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _SortedArray {
    void** array;
    size_t num_el;
    size_t capacity;
    unsigned int (*precedes)(const void*, const void*);
} SortedArray;

SortedArray* sorted_array_init(size_t capacity, unsigned int (*precedes_fun)(const void*, const void*)) {
    SortedArray* array = malloc(sizeof(SortedArray));
    array->capacity = capacity;
    array->num_el = 0;
    array->precedes = precedes_fun;
    array->array = malloc(array->capacity * sizeof(void*));
    return array;
}

unsigned int sorted_array_is_empty(SortedArray* array) {
    if (array == NULL) {
        printf("array is NULL\n");
        exit(EXIT_FAILURE);
    }
    return array->num_el == 0;
}

void sorted_array_add(SortedArray* array, const void* elem) {
    if (array->capacity == array->num_el) {
        array->capacity *= 2;
        array->array = realloc(array->array, array->capacity * sizeof(void*));
    }

    unsigned long index = 0;
    while (index < array->num_el && array->precedes(array->array[index], elem)) {
        ++index;
    }

    for (unsigned long i = array->num_el; i > 0; --i) {
        array->array[i] = array->array[i - 1];
    }

    array->array[index] = (void*) elem;
    ++array->num_el;
}

void sorted_array_freemem(SortedArray* array) {
    free(array->array);
    free(array);
}