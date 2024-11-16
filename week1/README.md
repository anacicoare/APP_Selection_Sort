## Parallelization using only OpenMP

### Parallel Reduction for Finding Maximum:

- Each iteration in selectionSort uses a custom OpenMP reduction (```#pragma omp parallel for reduction(maximum:max)```) to distribute the task of finding the maximum element across threads.

### Parallel Sorting of Rows:

- Sorting of individual rows is independent, so OpenMP is used (#pragma omp parallel for) to handle different rows in parallel.