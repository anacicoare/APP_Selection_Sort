#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

// Structure for enabling reduction on the index of elements
struct Compare
{
    int val;
    int index;
};

// Custom reduction for finding the index of the max element
#pragma omp declare reduction(maximum : struct Compare : omp_out = omp_in.val > omp_out.val ? omp_in : omp_out)

// Function to swap two elements
static inline void swap(int *v, int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

// Function to perform selection sort on a row
void selectionSort(int *v, int n)
{
    for (int i = n - 1; i > 0; --i)
    {
        struct Compare max;
        max.val = v[i];
        max.index = i;

// Parallel reduction to find the max element
#pragma omp parallel for reduction(maximum : max)
        for (int j = i - 1; j >= 0; --j)
        {
            if (v[j] > max.val)
            {
                max.val = v[j];
                max.index = j;
            }
        }

        // Swap the found maximum element with the last element
        swap(v, i, max.index);
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int rows, cols, i, j;
    int **matrix = NULL;
    FILE *file = NULL;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <in_file> ( <out_file> )\n", argv[0]);
        exit(1);
    }

    omp_set_num_threads(4); // Set the number of OpenMP threads

    // Read matrix dimensions
    file = fopen(argv[1], "r");
    fscanf(file, "%d %d", &rows, &cols);

    // Allocate memory for the matrix
    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; ++i)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; ++j)
        {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);

// Sort each row in parallel
#pragma omp parallel for
    for (i = 0; i < rows; ++i)
    {
        selectionSort(matrix[i], cols);
    }

    // Print or write sorted matrix
    if (argc < 3)
    {
        printf("Sorted matrix:\n");
        printMatrix(matrix, rows, cols);
    }
    else
    {
        file = fopen(argv[2], "w");
        fprintf(file, "%d %d\n", rows, cols);
        for (i = 0; i < rows; ++i)
        {
            for (j = 0; j < cols; ++j)
            {
                fprintf(file, "%d ", matrix[i][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }

    // Free allocated memory
    for (i = 0; i < rows; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
