#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    //
    // Example with INTEGER
    //

    // Initialize a vector to hold integers
    Vector* vector = vector_init(sizeof(int), 2);
    if (!vector)
    {
        fprintf(stderr, "Failed to initialize vector\n");
        return EXIT_FAILURE;
    }

    // Add some integers to the vector
    int values[] = {1, 2, 3};
    for (size_t i = 0; i < 3; i++)
    {
        if (!vector->push(vector, &values[i]))
        {
            fprintf(stderr, "Failed to push element\n");
            vector->free(vector);
            return EXIT_FAILURE;
        }
    }

    // Print elements in the vector
    printf("Vector elements:\n");
    for (size_t i = 0; i < vector->getLength(vector); i++)
    {
        int* value = (int*)vector->get(vector, i);
        printf("Element %zu: %d\n", i, *value);
    }

    // Remove the last element
    int* removedValue = (int*)vector->pop(vector);
    if (removedValue)
    {
        printf("Removed element: %d\n", *removedValue);
    }
    else
    {
        printf("Failed to remove element\n");
    }

    // Print elements after removal
    printf("Vector elements after pop:\n");
    for (size_t i = 0; i < vector->getLength(vector); i++)
    {
        int* value = (int*)vector->get(vector, i);
        printf("Element %zu: %d\n", i, *value);
    }

    // Clear the vector
    vector->clear(vector);
    printf("Vector elements after clearing:\n");
    if (vector->getLength(vector) == 0)
    {
        printf("Vector is empty.\n");
    }
    else
    {
        for (size_t i = 0; i < vector->getLength(vector); i++)
        {
            int* value = (int*)vector->get(vector, i);
            printf("Element %zu: %d\n", i, *value);
        }
    }

    // Free the vector
    vector->free(vector);

    return EXIT_SUCCESS;
}
