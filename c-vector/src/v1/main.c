#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    //
    //Example with INTEGER
    //

    // Initialize a vector to hold integers
    struct Vector* vector = vector_init(sizeof(int), 2);
    if (!vector)
    {
        fprintf(stderr, "Failed to initialize vector\n");
        return EXIT_FAILURE;
    }

    // Add some integers to the vector
    int values[] = {1, 2, 3};
    for (size_t i = 0; i < 3; i++)
    {
        if (!vector_push(vector, &values[i]))
        {
            fprintf(stderr, "Failed to push element\n");
            vector_free(vector);
            return EXIT_FAILURE;
        }
    }

    // Print elements in the vector
    printf("Vector elements:\n");
    for (size_t i = 0; i < vector_getLength(vector); i++)
    {
        int* value = (int*)vector_get(vector, i);
        printf("Element %zu: %d\n", i, *value);
    }

    // Remove the last element
    int* removedValue = (int*)vector_pop(vector);
    printf("Removed element: %d\n", *removedValue);

    // Print elements after removal
    printf("Vector elements after pop:\n");
    for (size_t i = 0; i < vector_getLength(vector); i++)
    {
        int* value = (int*)vector_get(vector, i);
        printf("Element %zu: %d\n", i, *value);
    }

    // Clear the vector
    vector_clear(vector);
    printf("Vector elements after clearing:\n");
    for (size_t i = 0; i < vector_getLength(vector); i++)
    {
        int* value = (int*)vector_get(vector, i);
        printf("Element %zu: %d\n", i, *value);
    }

    // Free the vector
    vector_free(vector);

    return EXIT_SUCCESS;
}