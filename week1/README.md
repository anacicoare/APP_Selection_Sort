## Parallelization using only OpenMP

### Parallel Reduction for Finding Maximum:

- Each iteration in selectionSort uses a custom OpenMP reduction (```#pragma omp parallel for reduction(maximum:max)```) to distribute the task of finding the maximum element across threads.

### Parallel Sorting of Rows:

- Sorting of individual rows is independent, so OpenMP is used (#pragma omp parallel for) to handle different rows in parallel.

## Profiling

### Small file

![WhatsApp Image 2024-11-19 at 00 44 30](https://github.com/user-attachments/assets/ad97272a-ca79-41e9-adaa-95252d3a6030)

![WhatsApp Image 2024-11-19 at 00 44 40](https://github.com/user-attachments/assets/9da7da64-e07c-4fea-85b6-324c214f30f4)

![WhatsApp Image 2024-11-19 at 00 44 50](https://github.com/user-attachments/assets/503519eb-57ff-4713-88e6-755ecb1fcb83)

![WhatsApp Image 2024-11-19 at 00 45 11](https://github.com/user-attachments/assets/adf10f61-a8f5-433d-8255-db2026f22c41)

### Medium file

![WhatsApp Image 2024-11-19 at 00 36 38](https://github.com/user-attachments/assets/5146c413-5684-4d9f-91ea-2d59436ce19f)

![WhatsApp Image 2024-11-19 at 00 36 18](https://github.com/user-attachments/assets/8700252e-87d3-49eb-a6e0-589b4387e6f4)

![WhatsApp Image 2024-11-19 at 00 36 06](https://github.com/user-attachments/assets/13b21474-5afd-4c3b-a3d3-bfdc800de0c0)

![WhatsApp Image 2024-11-19 at 00 35 40](https://github.com/user-attachments/assets/af647d1a-3d7d-4981-9284-731e2e11bed1)


### Big file

![WhatsApp Image 2024-11-19 at 00 39 34](https://github.com/user-attachments/assets/85b3fda7-9f7f-42ad-99f3-39d2bb21cdf6)

![WhatsApp Image 2024-11-19 at 00 40 00](https://github.com/user-attachments/assets/75bd0db4-ed26-44bd-9776-742135975b8f)

![WhatsApp Image 2024-11-19 at 00 40 16](https://github.com/user-attachments/assets/610656ee-54c9-4f2e-899d-85a0affaae08)

![WhatsApp Image 2024-11-19 at 00 41 07](https://github.com/user-attachments/assets/b8d66e6c-6bee-4d45-8f55-dca31ce45909)
