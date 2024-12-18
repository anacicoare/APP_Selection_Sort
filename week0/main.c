#include <stdio.h>
#include <stdlib.h>

static inline void swap(int *v, int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void selectionSort(int *v, int n)
{
    for (int i = n - 1; i > 0; --i)
    {
        int max = i;
        for (int j = i - 1; j >= 0; --j)
        {
            if (v[j] > v[max])
            {
                max = j;
            }
        }
        swap(v, i, max);
    }
}

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

    // Sort each row
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
