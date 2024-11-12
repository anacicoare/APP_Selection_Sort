## Project Description

Selection Sort is a simple sorting algorithm that works by repeatedly finding the smallest element from an unsorted section of a list and placing it at the correct position of the sorted section.

## Time & Space complexity

- Time complexity: O(n^2)
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
    
2. _Memory Allocations_
     
    This screenshot displays the memory allocations made by the application during runtime. Most allocations are managed by system modules, such as _ntdll.dll_, _kernel32.dll_, and _wow64.dll_, which are essential libraries for core operations.

    - Total Allocated Memory: 52.3 KB
    - Total Allocations: 128
    - Relevant Modules:
        - `ntdll.dll`: core functions of the Windows operating system.
        - `kernel32.dll`: functions for low-level operations (process management, I/O).
        - `wow64.dll`: manages compatibility between different architectures (32-bit and 64-bit).
        
    This memory distribution indicates that the application relies mainly on system functions for its operations.
    

3. _Memory Usage Over Time_
     
    This graph shows memory usage over the application’s runtime. In the test performed, no significant increases were observed, and memory usage remained steady at 52.3 KB.

    - Memory Snapshot:
        - Time: 3.479 seconds
        - Allocations: 128
        - Total Memory Used: 52.3 KB
        
    This suggests that the application does not experience memory leaks during runtime and that no additional large allocations occur after initialization.
    
    
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
    
2. _Memory Allocations_
     
    This screenshot displays the memory allocations made by the application during runtime. Most allocations are managed by system modules, such as _ntdll.dll_, _kernel32.dll_, and _wow64.dll_, which are essential libraries for core operations.

    - Total Allocated Memory: 54.21 KB
    - Total Allocations: 128
    - Relevant Modules:
        - `ntdll.dll`: core functions of the Windows operating system.
        - `kernel32.dll`: functions for low-level operations (process management, I/O).
        - `wow64.dll`: manages compatibility between different architectures (32-bit and 64-bit).
        
    This memory distribution indicates that the application relies mainly on system functions for its operations.
    

3. _Memory Usage Over Time_
     
    This graph shows memory usage over the application’s runtime. In the test performed, no significant increases were observed, and memory usage remained steady at 54.21 KB.

    - Memory Snapshot:
        - Time: 3.508 seconds
        - Allocations: 128
        - Total Memory Used: 54.21 KB
        
    This suggests that the application does not experience memory leaks during runtime and that no additional large allocations occur after initialization.
    
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
    
2. _Memory Allocations_
     
    This screenshot displays the memory allocations made by the application during runtime. Most allocations are managed by system modules, such as _ntdll.dll_, _kernel32.dll_, and _wow64.dll_, which are essential libraries for core operations.

    - Total Allocated Memory: 452.49 KB
    - Total Allocations: 190
    - Relevant Modules:
        - `ntdll.dll`: core functions of the Windows operating system.
        - `kernel32.dll`: functions for low-level operations (process management, I/O).
        - `wow64.dll`: manages compatibility between different architectures (32-bit and 64-bit).
        
    This memory distribution indicates that the application relies mainly on system functions for its operations, with a significant increase in memory allocated due to the larger file size.

3. _Memory Usage Over Time_
     
    This graph shows memory usage over the application’s runtime. The usage remained steady at around 452.49 KB, with no increase observed throughout the execution.

    - Memory Snapshot:
        - Time: 19.556 seconds
        - Allocations: 190
        - Total Memory Used: 452.49 KB
        
    This suggests that the application does not experience memory leaks during runtime, even with the larger file, and that no additional large allocations occur after initialization.
    
    
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

    

