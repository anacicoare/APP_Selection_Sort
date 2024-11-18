## Project Description

Selection Sort is a simple sorting algorithm that works by repeatedly finding the smallest element from an unsorted section of a list and placing it at the correct position of the sorted section.

This algorithm is applied on matrix rows representing students' grades for each school subject.

## Time & Space complexity

- Time complexity: O(n^3)
- Space complexity: O(1)

## CPU Time and Memory

This document provides screenshots and analysis of resource usage (memory and CPU) for our application. The tests were conducted to evaluate memory consumption, resource allocations, and CPU usage distribution, considering the app’s debugging and optimization settings.

**Small file**

1. _CPU Usage_
     
    This graph illustrates CPU usage and the primary functions used by the application during execution.
    - Main Functions:
        - `[External Code]`: Represents code from external modules (system DLLs).
        - `mainCRTStartup`: Initialization function for C/C++ applications.
        - `_scrt_common_main]` and `_scrt_common_main_seh`: Functions for initialization and exception handling in C/C++ applications.
    - CPU Distribution:
        - Total CPU Used: `100%`, of which _External Code_: `80%` and _File System_: `20%`
        
    The application primarily uses functions from external code, indicating a high dependency on system libraries and minimal CPU-intensive calculations within the application itself.
   ![cpu](https://github.com/user-attachments/assets/66be377c-bd2e-4fb0-8113-7e0fbf6d1a15)


3. _Memory Allocations_
     
    This screenshot displays the memory allocations made by the application during runtime. Most allocations are managed by system modules, such as _ntdll.dll_, _kernel32.dll_, and _wow64.dll_, which are essential libraries for core operations.

    - Total Allocated Memory: 52.3 KB
    - Total Allocations: 128
    - Relevant Modules:
        - `ntdll.dll`: core functions of the Windows operating system.
        - `kernel32.dll`: functions for low-level operations (process management, I/O).
        - `wow64.dll`: manages compatibility between different architectures (32-bit and 64-bit).
        
    This memory distribution indicates that the application relies mainly on system functions for its operations.
     ![mem1](https://github.com/user-attachments/assets/c251e7db-8b19-4c59-bf88-662e34c18ea8)
    

4. _Memory Usage Over Time_
     
    This graph shows memory usage over the application’s runtime. In the test performed, no significant increases were observed, and memory usage remained steady at 52.3 KB.

    - Memory Snapshot:
        - Time: 3.479 seconds
        - Allocations: 128
        - Total Memory Used: 52.3 KB
        
    This suggests that the application does not experience memory leaks during runtime and that no additional large allocations occur after initialization.
    ![mem2](https://github.com/user-attachments/assets/16abb16d-dbd6-4f66-abda-60fd2f567f91)

    
**Medium file**

1. _CPU Usage_
     
   This graph illustrates CPU usage and the primary functions used by the application during execution.
    - Main Functions:
        - `[External Code]`: Represents code from external modules (system DLLs).
        - `mainCRTStartup`: Initialization function for C/C++ applications.
        - `_scrt_common_main]` and `_scrt_common_main_seh`: Functions for initialization and exception handling in C/C++ applications.
        - `ucrtbased.dll`: Additional external module used during the application runtime.
    - CPU Distribution:
        - Total CPU Used: `100%`, of which _External Code_: `75%` and _I/O Operations_: `25%`
        
    The application primarily uses functions from external code, indicating a high dependency on system libraries and minimal CPU-intensive calculations within the application itself.
    ![cpuM](https://github.com/user-attachments/assets/3a3f80ee-d197-4abe-8b5a-3b96628756d8)


2. _Memory Allocations_
     
    This screenshot displays the memory allocations made by the application during runtime. Most allocations are managed by system modules, such as _ntdll.dll_, _kernel32.dll_, and _wow64.dll_, which are essential libraries for core operations.

    - Total Allocated Memory: 54.21 KB
    - Total Allocations: 128
    - Relevant Modules:
        - `ntdll.dll`: core functions of the Windows operating system.
        - `kernel32.dll`: functions for low-level operations (process management, I/O).
        - `wow64.dll`: manages compatibility between different architectures (32-bit and 64-bit).
        
    This memory distribution indicates that the application relies mainly on system functions for its operations.
    ![mem1M](https://github.com/user-attachments/assets/f18e543a-d6e6-4b07-864b-ec409e806bfd)


3. _Memory Usage Over Time_
     
    This graph shows memory usage over the application’s runtime. In the test performed, no significant increases were observed, and memory usage remained steady at 54.21 KB.

    - Memory Snapshot:
        - Time: 3.508 seconds
        - Allocations: 128
        - Total Memory Used: 54.21 KB
        
    This suggests that the application does not experience memory leaks during runtime and that no additional large allocations occur after initialization.
    ![mem2M](https://github.com/user-attachments/assets/d7d01008-8f86-4744-913f-f37375385cd7)


**Large file**

1. _CPU Usage_
     
   This graph illustrates CPU usage and the primary functions used by the application during execution.
    - Main Functions:
        - `selectionSort`: The primary function handling sorting, responsible for the majority of CPU usage.
        - `[External Code]`: Represents code from external modules (system DLLs).
        - `ntoskrnl.exe`: System call handling low-level operations.
        - `main`: Main function initializing the application.
        - `__CheckForDebuggerJustMyCode`: A check function used by Visual Studio to monitor debugging.
    - CPU Distribution:
        - Total CPU Used: `100%`,with selectionSort consuming the majority of CPU time, of which _I/O Operations_: 99.3%, _Kernel_: 0.6%, _Graphics_: <0.1% and _File System_: <0.1%
        
    This indicates that the selectionSort function is highly CPU-intensive, with a large dependency on I/O operations due to reading and writing data.
![WhatsApp Image 2024-fg11-11 at 21 59 08](https://github.com/user-attachments/assets/9d7c853c-78b2-4612-8ebe-32ef13b6dc2c)


2. _Memory Allocations_
     
    This screenshot displays the memory allocations made by the application during runtime. Most allocations are managed by system modules, such as _ntdll.dll_, _kernel32.dll_, and _wow64.dll_, which are essential libraries for core operations.

    - Total Allocated Memory: 452.49 KB
    - Total Allocations: 190
    - Relevant Modules:
        - `ntdll.dll`: core functions of the Windows operating system.
        - `kernel32.dll`: functions for low-level operations (process management, I/O).
        - `wow64.dll`: manages compatibility between different architectures (32-bit and 64-bit).
        
    This memory distribution indicates that the application relies mainly on system functions for its operations, with a significant increase in memory allocated due to the larger file size.
![WhatsApp Image 2024-11werf-11 at 22 01 48](https://github.com/user-attachments/assets/99d27aaa-af8b-435d-a3b2-a431eb296453)


3. _Memory Usage Over Time_
     
    This graph shows memory usage over the application’s runtime. The usage remained steady at around 452.49 KB, with no increase observed throughout the execution.

    - Memory Snapshot:
        - Time: 19.556 seconds
        - Allocations: 190
        - Total Memory Used: 452.49 KB
        
    This suggests that the application does not experience memory leaks during runtime, even with the larger file, and that no additional large allocations occur after initialization.
     ![WhatsApp Image 2024-11edfcs-11 at 22 03 22](https://github.com/user-attachments/assets/cae3b828-3d94-42b5-820a-49481bf6f7ae)

    
## Comparative Analysis: Small, Medium, and Large Files

1. _CPU Usage_
     
    - `Small and Medium Files`: Both rely primarily on external system libraries, with minimal CPU usage dedicated to main code processing. Both files show significant dependency on External Code.
    - `Large File`: The CPU is mostly consumed by the selectionSort function due to sorting a larger dataset, with a significant increase in I/O operations. This indicates that the algorithm’s CPU requirements scale with file size.
    
2. _Memory Allocations_
     
    - `Memory Usage Consistency`: The small and medium files show minimal and consistent memory usage, while the large file shows a substantial increase in memory allocations.
    - `Dependence on System Modules`: In all cases, memory allocations are handled by system libraries (ntdll.dll, kernel32.dll, and wow64.dll), indicating reliance on core OS functions for memory management.

3. _Memory Usage Over Time_
     
    - `Memory Stability`: All file sizes demonstrated stable memory usage over time, suggesting that the application does not experience memory leaks, even when processing larger files.
    - `Effect of File Size`: The larger file required a substantial increase in initial memory usage, but this remained stable once allocated, indicating efficient memory handling.    

## Small file

![WhatsApp Image 2024-11-18 at 23 27 36](https://github.com/user-attachments/assets/97e14f1c-f0c5-4fc8-a79d-bd25deff933c)

![WhatsApp Image 2024-11-18 at 23 28 13](https://github.com/user-attachments/assets/e97fb76e-fd52-4c6c-b64d-9efced72a944)

![WhatsApp Image 2024-11-18 at 23 29 21](https://github.com/user-attachments/assets/f8c7bec3-2340-42c5-a907-e4cfa5fc17c9)

![WhatsApp Image 2024-11-19 at 00 16 53](https://github.com/user-attachments/assets/3489ebe1-48b9-411a-ab7f-8809958f1091)

## Medium file

![WhatsApp Image 2024-11-19 at 00 14 17](https://github.com/user-attachments/assets/ccf9ef8f-3937-4e70-a51a-413481ab7535)

![WhatsApp Image 2024-11-19 at 00 14 34](https://github.com/user-attachments/assets/f1e9af12-48b1-4200-bac1-18fb0b97c03b)

![WhatsApp Image 2024-11-19 at 00 15 02](https://github.com/user-attachments/assets/d85a1c59-e807-45c2-9b1f-a097840a38d7)

![WhatsApp Image 2024-11-19 at 00 15 41](https://github.com/user-attachments/assets/5722f3f4-e9a9-4907-9276-d2854d768835)


## Big file

![WhatsApp Image 2024-11-19 at 00 11 06](https://github.com/user-attachments/assets/531f8523-3c3a-434d-874d-ef96c619340f)

![WhatsApp Image 2024-11-19 at 00 11 21](https://github.com/user-attachments/assets/b922a962-e5cf-48b7-ad25-8b78fa1ee985)

![WhatsApp Image 2024-11-19 at 00 11 56](https://github.com/user-attachments/assets/c45da7b1-2ce1-48c6-8269-de504ba624b0)

![WhatsApp Image 2024-11-19 at 00 17 46](https://github.com/user-attachments/assets/271f401a-0d19-4742-b9f9-8491e5b483c9)


