
# CUDA Notes

### Setup Instructions

1. first do a `sudo apt update && sudo apt upgrade -y && sudo apt autoremove` then pop over to [downloads](https://developer.nvidia.com/cuda-downloads)

2. fill in the following settings that match the device you'll be doing this course on: Operating System
   - Architecture
   - Distribution
   - Version
   - Installer Type
   
3. you'll have to run a command very similar to the one below in the "runfile section"
   ```bash
   wget https://developer.download.nvidia.com/compute/cuda/12.6.0/local_installers/cuda_12.6.0_560.28.03_linux.run
   sudo sh cuda_12.6.0_560.28.03_linux.run
   ```

4. in the end, you should be able to run `nvcc --version` and get info about the nvidia cuda compiler (version and such). Also, run `nvidia-smi` to ensure nvidia recognizes your cuda version and connected GPU

5. If `nvcc` doesn't work, run `echo $SHELL`. If it says bin/bash, add the following lines to the ~/.bashrc rile. If it says bin/zsh, add to the ~/.zshrc file. 
   ```bash
   export PATH=/usr/local/cuda-12.6/bin${PATH:+:${PATH}}
   export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/local/cuda/lib64
   ```
6. Do `source ~/.zshrc` or `source ~/.bashrc` after this then try `nvcc -V` again

7. `Alternatively`
   - run the shell script in this directory: `./cuda-installer.sh`
___

### Pointers
   ```C++
   #include <stdio.h>               // Standard input/output header file (for printf)
                                    // & "address of" operator
                                    // * "dereference" operator

   int main() {

       // Example 1
       {
         printf("\n------- Example 1 -------- \n"); 
         int x = 10;
         int* ptr = &x;                         // '&' is used to get the memory address of a variable (x)
         printf("Address of x: %p\n", ptr);     // Output: memory address of x
         printf("Value of x: %d\n", *ptr);      // Output: 10
                                                // '*' in the prev line is used to get the value of 
                                                // the memory address stored in ptr (dereferencing)
       }

       // ------------------------------------------------------------------------------------------------------------------------------------------
       // Example 2
       {
         printf("\n------- Example 2 -------- \n"); 

         int    value = 42;
         int*   ptr1  = &value;
         int**  ptr2  = &ptr1;
         int*** ptr3  = &ptr2;
         printf("Value: %d\n", ***ptr3);           // Output: 42
       }

       // ------------------------------------------------------------------------------------------------------------------------------------------
       // Example 3
       {
         printf("\n------- Example 3 -------- \n"); 

         int num = 10;
         float fnum = 3.14;
         void* vptr;

         vptr = &num;
         printf("Integer: %d\n", *(int*)vptr);     // Output: 10
                                                   // vptr is a memory address "&num" but it is stored as a void pointer (no data type)
                                                   // We can't dereference a void pointer, so we cast it to an integer pointer to store the 
                                                   // integer value at that memory address "(int*)vptr"
                                                   // Then we dereference it with the final asterisk "*" to get the value "*((int*)vptr)"

         vptr = &fnum;
         printf("Float: %.2f\n", *(float*)vptr);   // Output: 3.14
                                                   // void pointers are used when we don't know the data type of the memory address
                                                   // fun fact: malloc() returns a void pointer but we see it as a pointer to a specific data type after the 
                                                   // cast (int*)malloc(4) or (float*)malloc(4) etc.
       }

       // ------------------------------------------------------------------------------------------------------------------------------------------
       // Example 4
       {
         printf("\n------- Example 4 -------- \n"); 

         int arr[] = {12, 24, 36, 48, 60};
         int* ptr = arr;                           // ptr points to the first element of arr (default in C)

         printf("Position one: %d\n", *ptr);       // Output: 12

         for (int i = 0; i < 5; i++) {
             printf("%d\t", *ptr);
             printf("%p\t\n", ptr);
             ptr++;
         }
                                                   // Output: 
                                                   // Position one: 12
                                                   // disclaimer: the memory addresses won't be the same each time you run
                                                   // 12 0x7fff773fe780
                                                   // 24 0x7fff773fe784
                                                   // 36 0x7fff773fe788
                                                   // 48 0x7fff773fe78c
                                                   // 60 0x7fff773fe790

                                                   // notice that the pointer is incremented by 4 bytes (size of int = 4 bytes * 8 bits/bytes = 32 bits = int32) each time. 
                                                   // ptrs are 64 bits in size (8 bytes). 2**32 = 4,294,967,296 which is too small given how much memory we typically have.
                                                   // arrays are layed out in memory in a contiguous manner (one after the other rather than at random locations in the memory grid)
       }

       // ------------------------------------------------------------------------------------------------------------------------------------------
       // Example 5
       // matrix -> arr -> integers
       {
         printf("\n------- Example 5 -------- \n"); 

         int arr1[] = {1, 2, 3, 4};
         int arr2[] = {5, 6, 7, 8};
         int* ptr1 = arr1;
         int* ptr2 = arr2;
         int* matrix[] = {ptr1, ptr2};

         for (int i = 0; i < 2; i++) {
             for (int j = 0; j < 4; j++) {
                 printf("%d ", *matrix[i]++);
             }
             printf("\n");
         }
       }

       // ------------------------------------------------------------------------------------------------------------------------------------------
       // Example 6
       // Initialize pointer to NULL
       {
         printf("\n------- Example 6 -------- \n"); 

         int* ptr = NULL;
         printf("1. Initial ptr value: %p\n", (void*)ptr);

         // Check for NULL before using
         if (ptr == NULL) {
             printf("2. ptr is NULL, cannot dereference\n");
         }

         // Allocate memory
         ptr = (int*)malloc(sizeof(int));
         if (ptr == NULL) {
             printf("3. Memory allocation failed\n");
             return 1;
         }

         printf("4. After allocation, ptr value: %p\n", (void*)ptr);

         // Safe to use ptr after NULL check
         *ptr = 42;
         printf("5. Value at ptr: %d\n", *ptr);

         // Clean up
         free(ptr);
         ptr = NULL;  // Set to NULL after freeing

         printf("6. After free, ptr value: %p\n", (void*)ptr);

         // Demonstrate safety of NULL check after free
         if (ptr == NULL) {
             printf("7. ptr is NULL, safely avoided use after free\n");
         }
       }
       return 0;
   }
   ```
___

### Custom Types
- `size_t` is a size type for memory allocation
- `size_t` is an unsigned integer data type used to represent the size of objects in bytes. 
- It is guaranteed to be big enough to contain the size of the biggest object the host system can handle.
   ```C++
   #include <stdio.h>
   #include <stdlib.h>
   using namespace std;
   
   typedef struct {
      float x;
      float y;
   } Point;

   int main() {
      int arr[] = {12, 24, 36, 48, 60};

      // size_t
      size_t size = sizeof(arr) / sizeof(arr[0]);
      printf("Size of arr: %zu\n", size);                // Output: 5
      printf("size of size_t: %zu\n", sizeof(size_t));   // Output: 8 (bytes) -> 64 bits which is memory safe
      printf("int size in bytes: %zu\n", sizeof(int));   // Output: 4 (bytes) -> 32 bits

      // z -> size_t
      // u -> unsigned int
      // %zu -> size_t
      // src: https://cplusplus.com/reference/cstdio/printf/

      Point p = {1.1, 2.5};
      printf("size of Point: %zu\n", sizeof(Point));     // Output: 8 bytes = 4 bytes (float x) + 4 bytes (float y)

      return 0;
   }
   ```
___

### Type Casting

a. `static_cast<new_type>(expression)`

**Example**:
```cpp
double pi = 3.14159;
int rounded_pi = static_cast<int>(pi);
```

**Explanation**\
`static_cast` is used for implicit conversions between types. It's the most common cast and is checked at compile-time. In this example, it converts a double to an int, truncating the decimal part.


b. `dynamic_cast<new_type>(expression)`

**Example**:
```cpp
class Base { virtual void foo() {} };
class Derived : public Base { };

Base* base_ptr = new Derived;
Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
```

**Explanation**\
`dynamic_cast` is used for safe downcasting in inheritance hierarchies. It performs a runtime check and returns nullptr if the cast is not possible. It requires at least one virtual function in the base class.


c. `const_cast<new_type>(expression)`


**Example**:
```cpp
const int constant = 10;
int* non_const_ptr = const_cast<int*>(&constant);
*non_const_ptr = 20; // Modifies the const variable (undefined behavior)
```

**Explanation**\
`const_cast` is used to add or remove const (or volatile) qualifiers from a variable. It's the only C++ style cast that can do this. However, modifying a const object leads to undefined behavior.


d. `reinterpret_cast<new_type>(expression)`


**Example**:
```cpp
int num = 42;
char* char_ptr = reinterpret_cast<char*>(&num);
```

**Explanation**\
`reinterpret_cast` is the most dangerous cast. It can convert between unrelated types, like pointers to integers or vice versa. It's often used for low-level operations and should be used with extreme caution.

```c
// c-style type casting
#include <stdio.h>

int main() {
    float f = 69.69;
    int i = (int)f;
    printf("%d\n", i);  // Output: 69 ( rounded down since decimal is truncated (deletes the .69 part) )

    // to char
    char c = (char)i;
    printf("%c\n", c);  // Output: E (ASCII value of 69 -> https://www.asciitable.com/)
}
```
___

### MACROS
```c
#include <stdio.h>

// examples for each conditional macro
// #if
// #ifdef
// #ifndef
// #elif
// #else
// #endif

#define PI 3.14159
#define AREA(r) (PI * r * r)

#ifndef radius
   #define radius 7
#endif

// if elif else logic
// we can only use integer constants in #if and #elif
#if radius > 10
   #define radius 10
#elif radius < 5
   #define radius 5
#else
   #define radius 7
#endif


int main() {
    printf("Area of circle with radius %d: %f\n", radius, AREA(radius));  
    // Output: Area of circle with radius 6.900000: 149.571708
}
```
___
### Makefiles

```make
targets: prerequisites
    bash command
    possibly another bash command?
```

#### Purpose of CMakeLists.txt?

CMake is a tool that **generates Makefiles**. It is a build system generator. It is used to build, test, and package software. It is a cross-platform build system. It is used to control the software compilation process using simple platform and compiler independent configuration files.



#### What does `.PHONY` do?

Say we have a Makefile with a target named 'clean':
```make
clean:
    rm -rf build/*
```

Suppose we have a directory named 'clean' in the same directory as the Makefile. If we run `make clean`, make will not run the command in the target 'clean'. Instead, it will see that the directory 'clean' already exists and will not run the command.

In short, we essentially make a bunch of mappings from target names to commands. If we have a file or directory with the same name as a target, make will not run the command. This is where `.PHONY` comes in.

#### `:=` vs `=` in Makefiles

`=` is used for defining variables. It is called a **recursive assignment**. The value of the variable is re-evaluated each time the variable is used.

`:=` is used for defining variables. It is called a **simple assignment** or **immediate assignment**. The value of the variable is evaluated only once, at the point of definition.

Example:
```make
A = $(B)
B = hello
C := $(B)
B = world

all:
    @echo A is $(A)  # Outputs: A is world
    @echo C is $(C)  # Outputs: C is hello
```

#### What is the purpose of `@` in Makefiles?

The @ symbol prevents the command itself from being echoed to the console when the Makefile is executed.

Example:
```make
clean:
    rm -rf build/*
```

```bash
$ make clean
rm -rf build/*
```

```make
clean:
    @rm -rf build/*
```

```bash
$ make clean
$
```
___

- CPU: Central Processing Unit 
    - General purpose
    - High clock speed
    - Few cores
    - High cache
    - Low Latency
    - Low throughput

- GPU: Graphics Processing Unit 
    - Specialized
    - Low clock speed
    - Many cores
    - Low cache
    - High Latency
    - High throughput

- TPU: Tensor Processing Unit 
    - Specialized GPUs for deep learning algorithms (matrix multiplication, etc)

- FPGA: Field Programmable Gate Array 
    - Specialized hardware that can be reconfigured to perform specific tasks
    - Very low latency
    - Very high throughput
    - Very high power consumption
    - Very high cost


## What makes GPUs so fast for deep learning?
- CPU (host)
    - minimize time of one task
    - metric: latency in seconds

- GPU (device)
    - maximize throughput
    - metric: throughput in tasks per second (ex: pixels per ms)

## Typical CUDA program
1. CPU allocates CPU memory
2. CPU copies data to GPU
3. CPU launches kernel on GPU (processing is done here)
4. CPU copies results from GPU back to CPU to do something useful with it

## Some terms to remember
- kernels - GPU functions
- threads, blocks, and grid (next chapter)
- GEMM = **GE**neral **M**atrix **M**ultiplication
- SGEMM = **S**ingle precision (fp32) **GE**neral **M**atrix **M**ultiplication
- cpu/host/functions vs gpu/device/kernels
- CPU is referred to as the host. It executes functions. 
- GPU is referred to as the device. It executes GPU functions called kernels.


## Easy stuff
Host ⇒ CPU ⇒ Uses RAM sticks on the motherboard

Device ⇒ GPU ⇒ Uses on Chip VRAM (video memory for desktop PCs)

CUDA program surface level runtime:

1. copy input from host to device
2. load GPU program and execute using the transferred on-device data
3. copy results from device back to host so you can display/use it somehow

## Device VS Host naming scheme
`h_A` refers to host (CPU) for variable name “A”

`d_A` refers to device (GPU) for variable name “A” 

`__global__`\
   - is visible globally, meaning the CPU or  *host* can call these global functions. 
   - these don’t typically return anything but just do really fast operations to a variable you pass in. 
   
`__device__` \
   - Is a very cool function. 
   - This is the small job that only the GPU can call. 

`__host__` \
   - is only going to run on CPU. same as running a regular c/c++ script on CPU without cuda.

## Memory Management

- `cudaMalloc` memory allocation on VRAM only (also called global memory)
   ```
       float *d_a, *d_b, *d_c;

       cudaMalloc(&d_a, N*N*sizeof(float));
       cudaMalloc(&d_b, N*N*sizeof(float));
       cudaMalloc(&d_c, N*N*sizeof(float));
   ```

- `cudaMemcpy` can copy from device to host, host to device, or device to device (edge cases)
    - host to device ⇒ CPU to GPU
    - device to host ⇒ GPU to CPU
    - device to device ⇒ GPU location to different GPU location
    - **`cudaMemcpyHostToDevice`**, **`cudaMemcpyDeviceToHost`**, or **`cudaMemcpyDeviceToDevice`**
    
- `cudaFree` will free memory on the device

# `nvcc` compiler
- Host code
    - modifed to run kernels
    - compiled to x86 binary

- Device code
    - compiled to PTX (parallel thread execution)

    - stable across multiple GPU generations

- JIT (just-in-time)

    - PTX into native GPU instructions

    - allows for forward compatibility

## CUDA Hierarchy?
1. Kernel executes in a thread
2. Threads grouped into Thread Blocks (aka Blocks)
3. Blocks grouped into a Grid
4. Kernel executed as a Grid of Blocks of Threads

### 4 technical terms:
- `gridDim` ⇒ number of blocks in the grid
- `blockIdx` ⇒ index of the block in the grid
- `blockDim` ⇒ number of threads in a block
- `threadIdx` ⇒ index of the thread in the block

(more on this in video lectures)

## Threads
- each thread has local memory (registers) and is private to the thread
- if want to add `a = [1, 2, 3, ... N]` and `b = [2, 4, 6, ... N]` each thread would do a single add ⇒ `a[0] + b[0]` (thread 1); `a[1] + b[1]` (thread 2); etc...

## Warps
- https://en.wikipedia.org/wiki/Warp_and_weft
- Each warp is inside of a block and parallelizes 32 threads
- Instructions are issued to warps that then tell the threads what to do (not directly sent to threads)
- Warp scheduler makes the warps run
- 4 warp schedulers per SM

## Blocks
- each block has shared memory (visible to all threads in thread block)
- execute the same code on different data, shared memory space, more efficient memory reads and writes since coordination is better

## Grids
- during kernel execution, the threads within the blocks within the grid can access global memory (VRAM)
- contain a bunch of blocks. best example is grids handle batch processing, where each block in the grid is a batch element

   > Logically, the shared memory is partitioned among the blocks. This means that a thread can communicate with the other threads in its block via the shared memory chunk. 

- CUDA parallelism is scalable because their aren’t sequential block run-time dependencies.

   > [How do threads map onto CUDA cores?](https://stackoverflow.com/questions/10460742/how-do-cuda-blocks-warps-threads-map-onto-cuda-cores)

# Kernels

## Kernel Launch Params

- Type `dim3` is 3D type for grids and thread blocks which are later feed into the kernel launch configuration.
- allows for indexing of elements as vector, matrix, or volume (tensor)
   ```cpp
   dim3 gridDim(4, 4, 1);     // 4 blocks in x, 4 block in y, 1 block in z
   dim3 blockDim(4, 2, 2);    // 4 threads in x, 2 thread in y, 2 thread in z
   ```
- other type is `int` which specifies a 1D vector
   ```cpp
   int gridDim = 16;          // 16 blocks
   int blockDim = 32;         // 32 threads per block
   <<<gridDim, blockDim>>>
   // these aren't dim3 types but they are still valid if the indexing scheme is 1D
   ```

- gridDim ⇒ gridDim.x * gridDim.y * gridDim.z = # of blocks being launched
- blockDim ⇒ blockDim.x * blockDim.y * blockDim.z = # of threads per block
- total threads = (threads per block) \* # of blocks

- The execution configuration (of a global function call) is specified by inserting an expression of the form `<<<gridDim, blockDim, Ns, S>>>`, where:

  - `Dg (dim3)` specifies the dimension and size of the grid
  - `Db (dim3)` specifies the dimension and size of each block
  - `Ns (size_t)` specifies the number of bytes in shared memory that is dynamically allocated per block for this call in addition to the statically allocated memory. (typically omitted)
  - `S (cudaStream_t)` specifies the associated stream, is an optional parameter which defaults to 0.

   > source -> https://stackoverflow.com/questions/26770123/understanding-this-cuda-kernels-launch-parameters

## Thread Synchronization

- `__syncthreads()` 
  - Synchronizes execution of all threads within a block
  - Ensures all threads reach the same point in the code
  - Guarantees that memory accesses before the call are visible to all threads in the block
  - Must be reached by all threads in the block
  - Cannot be used inside divergent code paths (different if-else branches)

- `__threadfence()` 
  - Makes memory writes visible across blocks
  - Stalls the current thread until writes to shared and global memory are visible to all threads
  - Does not synchronize thread execution
  - Can be called by individual threads without requiring all threads to reach it

   - `Key Differences` 
     - `__syncthreads()` is stronger for block-level synchronization
     - `__threadfence()` is primarily used for memory visibility across blocks
     - `__syncthreads()` is a barrier synchronization, while __threadfence() is a memory fence

- `cudaDeviceSynchronize()` 
  - A host function that blocks the CPU until all previously issued commands (kernels, memory copies) on the GPU have completed.
  - Synchronizes at the device level.
  - Waits for all kernels and memory operations across all streams to complete.
  - Useful for ensuring that the host CPU waits for the GPU to finish its tasks before proceeding.
  - Can lead to idle CPU time while waiting for GPU operations, which may reduce overall performance in applications that require high throughput.

- `__syncwarps()`
  -  Synchronizes threads within a single warp (32 threads).
  - Allows threads to synchronize from different points in the code and can use a mask to specify which threads participate in the synchronization.
  - Enables synchronization in divergent code paths, making it more flexible for intra-warp communication.
  - More efficient for intra-warp operations as it minimizes waiting times by allowing only relevant threads to synchronize, thus improving performance in parallel algorithms.
  - Commonly used in reductions and other collective operations within a warp.
  
## Thread Safety

- [Is CUDA thread-safe?](https://forums.developer.nvidia.com/t/is-cuda-thread-safe/2262/2)
- when a piece of code is “thread-safe” it can be run by multiple threads at the same time
  without leading to race conditions or other unexpected behavior.

- Race conditions are where one thread starts the next task before another finishes.
  to prevent race conditions, we use a special function called `cudaDeviceSynchronize()`
  to ensure all threads are caught up before giving them a new instruction to work on.
  think about a bunch of threads racing to the finish line, some finish before others
  for some reason and you have to manually tell those “winner” threads to wait at the
  finish line for the laggers.

- If you are wondering about calling multiple GPU kernels with different CPU threads,
  refer to the link above.

## SIMD/SIMT (Single Instruction, Multiple Threads)

- [Can CUDA use SIMD instructions?](https://stackoverflow.com/questions/5238743/can-cuda-use-simd-extensions)

- Similar, to CPU SIMD (single instruction multiple data), we have single instruction multiple thread on GPU.

- Instead of running the for loop sequentially, each thread can run a single iteration of the for loop so that it appears to only take the time of one iteration. it can grow linearly if you add more and more iterations as you would expect (not enough cores to parallel process all the independent iterations of the for loop)

- Simpler than CPU
  - in-order instruction issue
  - no branch prediction
  - significantly less control than CPU architecture gives us more room for more CORES

   > Later on in the course (matmul optimization chapter), we will come back to optimzations connected to these special warp ops. [Warp Level Primitives](https://developer.nvidia.com/blog/using-cuda-warp-level-primitives/)

- https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#thread-hierarchy tells us "There is a limit to the number of threads per block, since all threads of a block are expected to reside on the same streaming multiprocessor core and must share the limited memory resources of that core. On current GPUs, a thread block may contain up to 1024 threads.", indicating 1024 threads per block, 32 threads per warp, and 32 warps per block is our theoretical limit.

## Math intrinsics
- device-only hardware instructions for fundamental math operations
- https://docs.nvidia.com/cuda/cuda-math-api/index.html
- you can use host designed operations like `log()` (host) instead of `logf()` (device) but they will run slower. these math essentials allow very math operations on the device/GPU. you can pass in `-use_fast_math` to the nvcc compiler to convert to these device only ops at the cost of barely noticeable precision error.
- `--fmad=true` for fused multiply-add

## Initialize the vector
- **rand**
  - This function generates a random integer between `0` and `RAND_MAX`, which is a constant defined in <cstdlib>. 
  - The exact value of `RAND_MAX` can vary, but it is typically at least 32767.
  
- **Casting to float**
  - `(float)rand()` converts the generated random integer into a float.
  
- **Normalization**
  - Dividing by `RAND_MAX` scales the random integer to a floating-point number between 0.0 and 1.0. 
  - Since `rand()` can return values from 0 to RAND_MAX, dividing by `RAND_MAX` ensures that the result is always in the range [0.0, 1.0].
  - The `srand` function seeds the random number generator used by functions like `rand()`. 
  - By providing a seed value, you initialize the random number generator to produce a different sequence of random numbers each time your program runs.
  
  - `time(0):`
      - This function call retrieves the current time as the number of seconds since the Unix epoch (January 1, 1970). 
      - The time function returns a value of type `time_t`, which is typically an integer representing this time in seconds.
      - The argument 0 means that we are asking for the current time.
      
  - `static_cast<unsigned int>(...)`
      - This part of the code converts the `time_t` value returned by time(0) into an `unsigned int`.
      - The reason for using `static_cast` is to ensure that the conversion is done safely and explicitly. 
      - This is important because `time_t` can be a different type on different systems (e.g., it might be a 64-bit integer on some platforms), and casting it to `unsigned int` ensures compatibility with the expected input type of `srand`.

      ```cpp
      srand(static_cast<unsigned int>(time(0)));      // Seed the random number generator
      void init_vector(float *vec, int n) {
          for (int i = 0; i < n; i++) {
              vec[i] = (float)rand() / RAND_MAX;
          }
      }
      ```

## What are Atomic Operations
    
- by “atomic” we are referring to the indivisibility concept in physics where a thing cannot be broken down further.

- An **atomic operation** ensures that a particular operation on a memory location is completed entirely by one thread before another thread can access or modify the same memory location. 

- This prevents race conditions.

- Since we limit the amount of work done on a single piece of memory per unit time throughout an atomic operation, we lose slightly to speed. It is hardware guaranteed to be memory safe at a cost of speed.

### **Integer Atomic Operations**
|Function                                           | Description                                                                          |
|---------------------------------------------------|--------------------------------------------------------------------------------------|
|**`atomicAdd(int* address, int val)`**             | Atomically adds `val` to the value at `address` and returns the old value.           |
|**`atomicSub(int* address, int val)`**             | Atomically subtracts `val` from the value at `address` and returns the old value.    |
|**`atomicExch(int* address, int val)`**            | Atomically exchanges the value at `address` with `val` and returns the old value.    |
|**`atomicMax(int* address, int val)`**             | Atomically sets the value at `address` to the maximum of the current value and `val`.|
|**`atomicMin(int* address, int val)`**             | Atomically sets the value at `address` to the minimum of the current value and `val`.|
|**`atomicAnd(int* address, int val)`**             | Atomically performs a bitwise AND of the value at `address` and `val`.               |
|**`atomicOr(int* address, int val)`**              | Atomically performs a bitwise OR of the value at `address` and `val`.                |
|**`atomicXor(int* address, int val)`**             | Atomically performs a bitwise XOR of the value at `address` and `val`.               |
|**`atomicCAS(int* address, int compare int val)`** | Atomically compares the value at `address` with `compare`, and if they are equal, replaces it with `val`. The original value is returned. |

### **Floating-Point Atomic Operations**

- **`atomicAdd(float* address, float val)`**: Atomically adds `val` to the value at `address` and returns the old value. Available from CUDA 2.0.
- Note: Floating-point atomic operations on double precision variables are supported starting from CUDA Compute Capability 6.0 using `atomicAdd(double* address, double val)`.

### From Scratch

Modern GPUs have special hardware instructions to perform these operations efficiently. They use techniques like Compare-and-Swap (CAS) at the hardware level.
You can think of atomics as a very fast, hardware-level mutex operation. It's as if each atomic operation does this:

1. lock(memory_location)
2. old_value = *memory_location
3. *memory_location = old_value + increment
4. unlock(memory_location)
5. return old_value

```cpp
__device__ int softwareAtomicAdd(int* address, int increment) {
    __shared__ int lock;
    int old;
    
    if (threadIdx.x == 0) lock = 0;
    __syncthreads();
    
    while (atomicCAS(&lock, 0, 1) != 0);  // Acquire lock
    
    old = *address;
    *address = old + increment;
    __threadfence();  // Ensure the write is visible to other threads
    
    atomicExch(&lock, 0);  // Release lock
    return old;
}
```

- Mutual Exclusion ⇒ https://www.youtube.com/watch?v=MqnpIwN7dz0&t

- "Mutual":
    - Implies a reciprocal or shared relationship between entities (in this case, threads or processes).
    - Suggests that the exclusion applies equally to all parties involved.

- "Exclusion":
    - Refers to the act of keeping something out or preventing access.
    - In this context, it means preventing simultaneous access to a resource.

```cpp
#include <cuda_runtime.h>
#include <stdio.h>

// Our mutex structure
struct Mutex {
    int *lock;
};

// Initialize the mutex
__host__ void initMutex(Mutex *m) {
    cudaMalloc((void**)&m->lock, sizeof(int));
    int initial = 0;
    cudaMemcpy(m->lock, &initial, sizeof(int), cudaMemcpyHostToDevice);
}

// Acquire the mutex
__device__ void lock(Mutex *m) {
    while (atomicCAS(m->lock, 0, 1) != 0) {
        // Spin-wait
    }
}

// Release the mutex
__device__ void unlock(Mutex *m) {
    atomicExch(m->lock, 0);
}

// Kernel function to demonstrate mutex usage
__global__ void mutexKernel(int *counter, Mutex *m) {
    lock(m);
    // Critical section
    int old = *counter;
    *counter = old + 1;
    unlock(m);
}

int main() {
    Mutex m;
    initMutex(&m);
    
    int *d_counter;
    cudaMalloc((void**)&d_counter, sizeof(int));
    int initial = 0;
    cudaMemcpy(d_counter, &initial, sizeof(int), cudaMemcpyHostToDevice);
    
    // Launch kernel with multiple threads
    mutexKernel<<<1, 1000>>>(d_counter, &m);
    
    int result;
    cudaMemcpy(&result, d_counter, sizeof(int), cudaMemcpyDeviceToHost);
    
    printf("Counter value: %d\n", result);
    
    cudaFree(m.lock);
    cudaFree(d_counter);
    
    return 0;
}
```
### MACROS

```cuda
#define CHECK_CUDA_ERROR(val) check((val), #val, __FILE__, __LINE__)
```

#### Components of the Macro
- `#define`
   - This is a preprocessor directive used to define a macro in C and C++. Macros are essentially text substitutions that the preprocessor performs before the actual compilation of the code.

- `CHECK_CUDA_ERROR(val)`
   - This part defines the name of the macro, CHECK_CUDA_ERROR, and specifies that it takes one argument, val. 
   - This argument is expected to be a CUDA API call (e.g., cudaMalloc, cudaMemcpy, etc.).

- `check(...)`
   - The macro calls a function named check, which is defined elsewhere in the code. 
   - This function is responsible for verifying whether the CUDA API call represented by val was successful.

- `(val)`
   - This passes the original value (the result of the CUDA API call) to the check function.
   - The specific use of parentheses around (val) in your macro ensures that whatever expression is passed as val is treated correctly during expansion, thus avoiding unintended consequences when the macro is invoked. This prevents operator precedence issues, avoids multiple evaluations.
   
- `#val`
   - The # operator is used to convert the argument val into a string literal. This means that if you pass a function call like cudaMalloc, it will be converted into the string "cudaMalloc" when passed to the check function. This is useful for debugging because it allows you to see which specific CUDA call caused an error.

- `__FILE__`
   - This predefined macro expands to the name of the current source file (as a string). It helps identify which file contains the CUDA call that generated an error.

- `__LINE__`
   - This predefined macro expands to the current line number in the source file. It provides information on exactly where in the code the error occurred.


## CUDA Streams

- A CUDA stream is defined as a sequence of operations (such as kernel launches and memory copies) that are executed in order. 
- Operations within the same stream are serialized, meaning they will execute one after the other. 
- However, operations from different streams can execute concurrently or out of order with respect to each other, depending on resource availability.

- Key Characteristics
   1. Sequential Execution Within Streams \
      Commands issued to a single stream will execute in the order they are called.
   
   2. Concurrent Execution Across Streams\
      Different streams can execute their commands simultaneously, allowing for overlapping computation and data transfer.
   
   3. Default Stream\
      If no specific stream is specified, operations are assigned to the default stream (also known as stream 0), which behaves synchronously with respect to other streams before CUDA 7. In newer versions, each thread can have its own default stream, enabling more concurrent execution.

- We can have multiple streams at once in CUDA, and each stream can have its own timeline. This allows us to overlap operations and make better use of the GPU.
- When training a massive language model, it would be silly to spend a ton of time loading all the tokens in and out of the GPU. 
- Streams allow us to move data around while also doing computation at all times. Streams introduce a software abstraction called "prefetching", which is a way to move data around before it is needed. 
- This is a way to hide the latency of moving data around. 
- You can think of streams as "river streams" where the direction of operations flows only forward in time (like a timeline).

- default **stream** = **stream** 0 = null **stream**

   ```cpp
   // This kernel launch uses the null stream (0)
   myKernel<<<gridSize, blockSize>>>(args);

   // This is equivalent to
   myKernel<<<gridSize, blockSize, 0, 0>>>(args);
   ```

- The execution configuration (of a global function call) is specified by inserting an expression of the form `<<<gridDim, blockDim, Ns, S>>>`, where:
  - `Dg (dim3)` specifies the dimension and size of the grid.
  - `Db (dim3)` specifies the dimension and size of each block
  - `Ns (size_t)` specifies the number of bytes in shared memory that is dynamically allocated per block for this call in addition to the statically allocated memory. (typically omitted)
  - `S (cudaStream_t)` specifies the associated stream, is an optional parameter which defaults to 0.

- `stream 1` and `stream 2` are created with different priorities. this means they are executed in a certain order at runtime. This essentially gives us more control over the concurrent execution of our kernels.
   ```cpp
   // Create streams with different priorities
   int leastPriority, greatestPriority;
   cudaStream_t stream1, stream2, stream3;

   // Creating cuda stream without priority.
   cudaStreamCreate(&stream3);

   // Launch kernels in different streams
   myKernel1<<<numBlocks1, blockSize1, 0, stream1>>>(data1);
   myKernel2<<<numBlocks2, blockSize2, 0, stream2>>>(data2);

   // Perform memory copies concurrently
   cudaMemcpyAsync(result1, d_result1, size1, cudaMemcpyDeviceToHost, stream1);
   cudaMemcpyAsync(result2, d_result2, size2, cudaMemcpyDeviceToHost, stream2);

   // Create streams with priority
   CHECK_CUDA_ERROR(cudaDeviceGetStreamPriorityRange(&leastPriority, &greatestPriority));
   CHECK_CUDA_ERROR(cudaStreamCreateWithPriority(&stream1, cudaStreamNonBlocking, leastPriority));
   CHECK_CUDA_ERROR(cudaStreamCreateWithPriority(&stream2, cudaStreamNonBlocking, greatestPriority));

   // Synchronize both streams
   cudaStreamSynchronize(stream1);
   cudaStreamSynchronize(stream2);

   // Clean up
   cudaStreamDestroy(stream1);
   cudaStreamDestroy(stream2);
   ```

- Limitations and Considerations
   1. Resource Contention\
      While multiple streams can run concurrently, they may compete for limited GPU resources (e.g., memory bandwidth), which could lead to performance degradation if not managed properly.
   
   2. Error Handling\
      Each operation in a stream should be checked for errors to ensure robust application performance.
   
   3. Complexity\
      Managing multiple streams adds complexity to code and requires careful synchronization to avoid race conditions.

## Docs
- https://developer.download.nvidia.com/CUDA/training/StreamsAndConcurrencyWebinar.pdf

## Pinned Memory
- Pinned memory, also known as page-locked memory, is a special type of memory allocation in CUDA that allows for faster data transfers between the host (CPU) and the device (GPU).
- Unlike pageable memory, which can be swapped in and out of physical memory by the operating system, pinned memory is locked in physical RAM, making it accessible for direct memory access (DMA) by the GPU.

- **Key Characteristics of Pinned Memory**
1. Direct Access by GPU\
   Pinned memory can be accessed directly by the GPU without needing an intermediate copy. This is crucial for high-performance applications where data transfer speed is a bottleneck.

2. Faster Data Transfers\
   Transfers to and from pinned memory are significantly faster (2x to 3x times) compared to pageable memory. This is because the CUDA driver does not need to perform additional copying from pageable memory to pinned memory before transferring data to the GPU.

3. Non-Swappable\
   Pages allocated as pinned memory cannot be swapped out by the operating system. This ensures that the data remains resident in RAM, which is essential for efficient DMA operations.

4. Resource Limitation\
   Pinned memory is a limited resource. Allocating too much pinned memory can reduce the amount of available physical RAM for other applications, potentially leading to performance degradation of the overall system.

5. Usage with CUDA Functions\
   Pinned memory must be allocated using specific CUDA functions such as `cudaMallocHost()` or `cudaHostAlloc()`, and it must be freed using `cudaFreeHost()`.

6. Pinned memory allows for overlapping data transfers with kernel execution, improving overall application performance.

   ```cpp
   // Allocate pinned memory
   float* h_data;
   cudaMallocHost((void**)&h_data, size);
   ```

## cudaStreamSynchronize() Function
- This function is used to block the host (CPU) until all operations in the specified CUDA stream have completed.

- The function takes a single argument, which is the CUDA stream that you want to synchronize.
   ```cpp
   // Synchronize streams
   CHECK_CUDA_ERROR(cudaStreamSynchronize(stream1));
   CHECK_CUDA_ERROR(cudaStreamSynchronize(stream2));
   ```
- By calling `cudaStreamSynchronize()`, you ensure that all operations queued in the specified stream (stream1 or stream2) are completed before proceeding to the next line of code.
- `cudaStreamSynchronize()` is a blocking call. This means that it will halt the execution of the host code until all operations in the specified stream have finished.
- As, `cudaStreamSynchronize()` can also reduce performance if overused, in applications where performance is critical, consider using `events` and `callbacks` instead of direct synchronization when possible.

## Events
- CUDA events are essential tools in CUDA programming, primarily used for synchronization and timing within GPU operations. 
- They allow developers to accurately measure the execution time of kernels and manage the flow of operations across different streams.

- Measuring kernel execution time: Events are placed before and after kernel launches to measure execution time accurately.

- CUDA events provide high-resolution timing capabilities (approximately half microsecond resolution), making them suitable for performance analysis of GPU applications. 

- Synchronizing between streams: Events can be used to create dependencies between different streams, ensuring one operation starts only after another has completed.

- Overlapping computation and data transfer: Events can mark the completion of a data transfer, signaling that computation can begin on that data.

- They are represented by the type `cudaEvent_t` and are created and destroyed using `cudaEventCreate()` and `cudaEventDestroy()`, respectively. 

- Events can be recorded in a CUDA stream, which is a sequence of operations executed on the GPU.

- CUDA events can also be shared between processes when configured appropriately. 
   This feature is beneficial in scenarios where multiple applications or processes need to coordinate their usage of GPU resources

```cpp
cudaEvent_t start, stop;
cudaEventCreate(&start);
cudaEventCreate(&stop);

cudaEventRecord(start, stream);
kernel<<<grid, block, 0, stream>>>(args);
cudaEventRecord(stop, stream);

cudaEventSynchronize(stop);
float milliseconds = 0;
cudaEventElapsedTime(&milliseconds, start, stop);
```

## Callbacks
-  By using callbacks, you can set up a pipeline where the completion of one operation on the GPU triggers the start of another operation on the CPU, which might then queue more work for the GPU. 
- When a callback is registered with a stream, it gets executed on the host after all preceding commands in that stream have completed. 
- This allows for non-blocking execution of tasks, enabling better resource utilization.

- Key Characteristics
   - Asynchronous Execution\
    Callbacks allow the CPU to perform other tasks while waiting for GPU operations to complete.
   
   - Stream-Specific\
    Each callback is associated with a specific CUDA stream, ensuring that it runs only after all commands in that stream have finished.
   
   - Blocking Behavior\
    `Callbacks` in the `default stream` will block until all commands across all streams have completed.

- Use Cases for CUDA Callbacks
   - Handling I/O Operations\
      Callbacks can be used to initiate I/O operations once a kernel completes without blocking the CPU.

   - Dynamic Task Scheduling\
      In applications where tasks depend on results from previous computations, callbacks can manage task scheduling dynamically.

   - Performance Monitoring:\
      Developers can use callbacks to log or analyze performance metrics after kernel execution.

- Limitations and Considerations
   - Thread Safety\
      Care must be taken when using shared resources within callbacks since they run in a different thread context.

   - Error Handling\
      Proper error checking should be implemented to handle potential issues during kernel execution or callback invocation.

   - Resource Management\
      Ensure that streams and resources are properly managed to avoid memory leaks or dangling pointers.

   ```cpp
   #include <stdio.h>
   #include <cuda_runtime.h>

   __global__ void myKernel() {
       // Kernel code here
   }

   void CUDART_CB MyCallback(cudaStream_t stream, cudaError_t status, void *userData) {
       printf("GPU operation completed\n");
       // Trigger next batch of work
   }

   int main() {
      cudaStream_t stream;
      cudaStreamCreate(&stream);

      // Launch kernel on the created stream
      kernel<<<grid, block, 0, stream>>>(args);
      
      // Register callback
      cudaStreamAddCallback(stream, MyCallback, nullptr, 0);

      // Wait for completion
      cudaStreamSynchronize(stream);

      // Clean up
      cudaStreamDestroy(stream);
      return 0
   }
   ```

## Using NVIDIA Nsight Systems for Profiling CUDA Programs
- `NVIDIA Nsight Systems` is a powerful tool designed for profiling and analyzing the performance of applications that utilize CUDA. 
- It provides insights into how your code interacts with the GPU and helps identify bottlenecks in performance. 
- Nsight Systems is available as both a command-line interface (CLI) and a graphical user interface (GUI).

### Installation

1. **Download and Install**:
   - Obtain `Nsight Systems` from the NVIDIA website. It is available as both a command-line interface (CLI) and a graphical user interface (GUI).
   - Follow the installation instructions specific to your operating system.

### Basic Profiling Steps

1. **Prepare Your Code**:
   - Ensure that your CUDA code is ready for profiling. You may want to include `NVTX (NVIDIA Tools Extension)` annotations to mark sections of your code for better visibility in the profiler.
   
   - NVTX 
      - `The NVIDIA Tools Extension (NVTX)` is a powerful annotation library designed to help developers profile and analyze the performance of their applications, particularly those utilizing CUDA for GPU programming. 
      - `NVTX` allows users to insert annotations into their code, which can then be visualized using NVIDIA's profiling tools, such as Nsight Systems. 
      - `NVTX` enables developers to annotate specific regions of code, functions, or events. These annotations can be used to mark the start and end of operations, making it easier to correlate CPU and GPU activities.
      - NVTX works seamlessly with NVIDIA Nsight Systems, allowing developers to visualize annotated code in a timeline view. 
      - This integration helps identify performance bottlenecks and understand the execution order of different operations.
      - By running applications with `Nsight Systems` while using `NVTX annotations`, developers can gain insights into both CPU and GPU performance metrics.
      - `NVTX` supports annotation across multiple devices, including different GPUs. 
      - Annotations can be applied using `decorators` or `context managers` in Python
         ```Python
         import nvtx
         import cupy as cp

         @nvtx.annotate("GPU Computation", color="green")
         def compute_on_gpu(data):
             # Perform computations on GPU
             result = cp.sum(data)
             return result
         ```
      - By annotating the `compute_on_gpu` function, developers can later analyze its performance in `Nsight Systems`.
      
      - In the following example, `nvtxRangePushA` begins a new range with the label `"my_function"`, which automatically ends when `nvtxRangePop` is called. This allows you to track how long `my_function` takes to execute
      
         ```c
         // C (or) C++ code using NVTX annotations
         #include "nvtx3.hpp"
         void my_function() {
            nvtxRangePushA("my_function");   // Start an NVTX range
            // ... perform operations ...
            nvtxRangePop();                  // End the NVTX range
         }
         ```

   - Example of using NVTX:
      ```python
      import torch
      torch.cuda.nvtx.range_push("My Range")
      # Your CUDA operations here
      torch.cuda.nvtx.range_pop()
      ```

2. **Run Nsight Systems**:

   - Following command is used to profile a Python script that utilizes CUDA for GPU operations.
   
      ```bash
      # This command generates `.nsys-rep` extension file, which contains detailed profiling information.
      # Optionally, a .sqlite file if additional statistics are collected.

      nsys profile --trace=cuda,nvtx --gpu-metrics-device=all python my_script.py
      ```
      - The `--trace=cuda,nvtx` option ensures that all CUDA API calls and NVTX annotations are captured. 
         
         This means that you will see detailed timing data for each CUDA operation and any NVTX ranges defined in your code.

      - The `--gpu-metrics-device=all` option instructs the profiler to collect metrics from all available GPUs. 
      
        This includes various performance metrics such as GPU utilization, memory usage, and kernel execution times.

      - The generated profiling report can be opened in NVIDIA Nsight Systems GUI for a visual representation of the profiling data, allowing you to analyze performance bottlenecks effectively.

   - You can profile your application using either the GUI or CLI. For CLI, use the following command structure:
      ```bash
      # Step 1: Compile the CUDA program
      nvcc -o my_program my_program.cu

      #(OR) Step 1: Compile the CUDA program with debug information
      nvcc -lineinfo -g -G -o my_program my_program.cu

      # Step 2: Profile the compiled program
      nsys profile -o output_file_name <your_cuda_application> --trace=cuda,nvtx --gpu-metrics-device=all ./my_program
     ```

   - The `-o` option specifies the output file name for the profiling data.
   - `-lineinfo` option enables the generation of line number information for debugging. It allows you to correlate the generated code with the original source code, which is useful for debugging purposes.
   - `-g` flag enables debugging information for the device code. It allows you to use a debugger (like cuda-gdb or Nsight) to step through your CUDA kernels.
   - `-G` option generates debug information for device code and enables additional checks (like memory checks). It is particularly useful during development and debugging but can lead to slower execution because of the added checks.
   - `-o my_program` specifies the output file name for the compiled program. In this case, the output will be an executable named `my_program`.
   - `my_program.cu` is the input CUDA source file that contains your CUDA code.
   - Using both `-g` and `-G` can significantly impact performance due to the additional debug checks and information generated. 
   - It is advisable to use these options primarily during development and debugging phases, and remove them for production builds to optimize performance.

3. **Capture Specific Ranges**:
   - To focus on specific parts of your code, you can use the `--capture-range` option
   
     ```bash
     nsys profile --capture-range=cudaProfilerApi --stop-on-range-end=true ...
     ```
   - This configuration will start profiling when `cudaProfilerStart()` is called and stop when `cudaProfilerStop()` is invoked.

### Advanced Profiling Options

1. **Select APIs to Trace**:
   - You can specify which APIs to trace by using the `-t` option. For example, to trace CUDA, NVTX, and cuDNN calls
   
     ```bash
     nsys profile -t cuda,nvtx,cudnn ...
     ```

2. **Enable Backtraces**:
   - To collect backtrace information for CUDA API calls, include the `--cudabacktrace=true` option. This allows you to see where in your code specific API calls were made.

3. **Visualizing Results**:
   - After running your application, open the generated report in the Nsight Systems GUI for detailed analysis.
   - The GUI provides a timeline view where you can see CPU and GPU activities, including kernel launches and memory transfers.

### Analyzing Performance Data

1. **Examine Timeline**:
   - In the GUI, analyze the timeline to identify idle times or inefficient memory transfers between the host and device.
   - Look for overlapping CPU and GPU activities to ensure that both resources are utilized effectively.

2. **Identify Bottlenecks**:
   - Focus on areas where significant time is spent waiting or where GPU utilization is low.
   - Use NVTX annotations to correlate specific sections of your code with performance metrics.

3. **Iterate on Optimizations**:
   - Based on insights gained from profiling, make necessary adjustments to your code.
   - Common optimizations include improving memory access patterns, reducing kernel launch overheads, and ensuring that kernels are fully utilizing available resources.

### Example Command

Here’s an example command that incorporates several options for profiling a CUDA application:

```bash
nsys profile -w true -t cuda,nvtx,cudnn,cublas \
--capture-range=cudaProfilerApi --stop-on-range-end=true \
--cudabacktrace=true -o my_cuda_profile python my_cuda_script.py
```

### Conclusion

Using NVIDIA Nsight Systems for profiling CUDA applications provides valuable insights into performance characteristics and helps identify optimization opportunities. \
By following these steps—installing the tool, preparing your code, running profiles with appropriate options, and analyzing results—you can significantly enhance the performance of your CUDA programs.\
For further details and advanced features, refer to [NVIDIA's official documentation](5).

Citations
   1. https://www.youtube.com/watch?v=Iuy_RAvguBM
   2. https://towardsdatascience.com/profiling-cuda-using-nsight-systems-a-numba-example-fc65003f8c52
   3. https://dev-discuss.pytorch.org/t/using-nsight-systems-to-profile-gpu-workload/59
   4. https://www.youtube.com/watch?v=51K5EqGqzCM
   5. https://docs.nvidia.com/nsight-compute/ProfilingGuide/index.html


## Nsight Compute

- `NVIDIA Nsight Compute` is a powerful interactive profiler designed for analyzing the performance of CUDA applications. 
- It provides detailed performance metrics and API debugging capabilities, allowing developers to optimize their GPU kernels effectively. 
- Below is a structured guide on how to utilize `Nsight Compute` for analyzing CUDA kernels.

#### Getting Started with Nsight Compute

1. Installation \
   Ensure you have the latest version of the NVIDIA CUDA Toolkit, which includes Nsight Compute.
   You can access it via the command line or through the graphical user interface (GUI).

2. Basic Command Usage \
   To start profiling a CUDA application, use the command:
   ```bash
   # Compile to cuda program for profiling
   nvcc -o example.o example.cu --lineinfo

   #This command runs the specified application and outputs kernel performance data to the console.
   ncu example.o
   ```

#### Profiling Kernels
- Setting Up Profiling
   1. Replay Modes\
      Nsight Compute supports various replay modes that allow you to capture different aspects of kernel execution.
   
   2. Configuration\
      You can configure profiling settings through the GUI or command line, specifying which metrics to collect and how to visualize them.

- Collecting Performance Metrics
   - Nsight Compute collects a wide range of metrics, including:
      1. Throughput\
         Measures how much work is done over time.
      
      2. Memory Bandwidth\
         Analyzes memory access patterns and bandwidth utilization.
      
      3. Warp State Statistics\
         Provides insights into how warps are scheduled and executed on the GPU.

- Analyzing Results
   1. Viewing Reports
      After profiling, you can view detailed reports that include:
      1. Kernel execution times.
      2. Memory usage statistics.
      3. A breakdown of performance bottlenecks.

   2. Using Baselines for Comparison
      - The baseline feature allows users to compare different profiling runs directly within Nsight Compute. This is useful for tracking performance improvements or regressions over time.

   3. Roofline Analysis
      - Roofline charts can be generated to visualize the performance headroom of your kernels against theoretical limits based on hardware capabilities. This helps in identifying optimization opportunities.

- Advanced Features
   
   1. Customizable Reports and Scripts
      Users can extend the capabilities of Nsight Compute by creating custom analysis scripts for post-processing results. This allows for tailored insights based on specific application needs.
   
   2. Integration with Development Environments
      Nsight Compute integrates with IDEs like Visual Studio, allowing for seamless profiling within your development workflow. Project settings can be transferred directly into Nsight Compute for streamlined analysis.
   
   3. Iterative Optimization Process
      Use the insights gained from profiling to iteratively optimize your kernels. Focus on identified bottlenecks, adjust memory access patterns, and refine computation strategies based on performance data.



### **NVIDIA Nsight Compute Command-Line Options**
NVIDIA Nsight Compute (ncu) provides a variety of command-line options for profiling CUDA applications. Below is a comprehensive list of options along with their descriptions:

| **Option**                     | **Description**                                                                                                           |
|--------------------------------|---------------------------------------------------------------------------------------------------------------------------|
| `-h`, `--help`                 | Displays help information about the command-line options available in Nsight Compute.                                     |
| `-o <report-name>`             | Specifies the name of the output report file where profiling results will be saved.                                       |
| `-k <kernel-name>`             | Specifies the name of the kernel to profile.                                                                              |
| `--target-processes <type>`    | Defines which processes to target for profiling (e.g., `all`, `self`, or a specific PID).                                 |
| `--section <section-name>`     | Specifies which sections of profiling data to collect (e.g., `ComputeWorkloadAnalysis`, `MemoryWorkloadAnalysis`).        |
| `--metrics <metric-list>`      | Specifies a comma-separated list of metrics to collect during profiling.                                                  |
| `--launch`                     | Launches the specified application and starts profiling immediately.                                                      |
| `--mode=attach`                | Attaches to an already running application for profiling.                                                                 |
| `--mode=launch`                | Launches an application and suspends it until connected for profiling.                                                    |
| `--duration <time>`            | Sets the duration for which profiling should occur, specified in milliseconds.                                            |
| `--nvtx`                       | Enables NVTX (NVIDIA Tools Extension) annotations for better context in profiling results.                                |
| `--print-summary`              | Outputs a summary of the profiling results directly to the console after execution.                                       |
| `--export <format>`            | Exports the profiling results in a specified format (e.g., CSV, JSON).                                                    |
| `--no-stdout`                  | Suppresses standard output from the application being profiled.                                                           |
| `--no-stdin`                   | Prevents standard input from being read by the application being profiled.                                                |
| `--set <setting-name>=<value>` | Sets specific configuration options for the profiling session (e.g., setting environment variables).                      |

#### **Usage Examples**
To run Nsight Compute with specific options, you can use commands like:

```bash
ncu -o my_report --section ComputeWorkloadAnalysis --metrics achieved_occupancy ./my_cuda_app
```
This command profiles the application `my_cuda_app`, collects data on compute workload analysis, and saves it to `my_report`.

#### **Conclusion**
These command-line options allow developers to customize their profiling sessions with NVIDIA Nsight Compute, enabling detailed performance analysis of CUDA applications tailored to their specific needs. For more advanced usage, refer to the official documentation for additional features and best practices.

#### **Resources**
   1. https://docs.nvidia.com/nsight-systems/UserGuide/index.html
   2. https://gist.github.com/agostini01/484bcfac8c5a99312e28fb6994284e9f
   3. https://docs.nvidia.com/nsight-compute/NsightComputeCli/index.html
   4. https://docs.nvidia.com/nsight-compute/NsightCompute/index.html
   5. https://docs.nvidia.com/nsight-compute/2023.1/NsightCompute/index.html

___
### CUDA Compilation Notes

#### 1. `PTX (Parallel Thread Execution) code`

   - Following command generates ptx code in the file `kernel.ptx` from its corresponding cuda code in the file `kernel.cu`. 
   
      ```
      nvcc -ptx -o kernel.ptx kernel.cu
      ```
   - PTX code is essential for scenarios where developers need to modify or inspect the intermediate representation of their CUDA kernels before final compilation into binary formats like `cubin` or `fatbin`

   - PTX code is not interpreted by a 'byte code interpreter'; instead, it is compiled into machine code by a traditional assembler called `ptxas`, which is included in the CUDA toolkit. 
   - This process generates executable binary code tailored to specific GPU architectures, allowing it to run directly on the hardware, or "on the metal".
   - The `ptxas` tool converts `PTX` code into binary code that can be executed on NVIDIA GPUs. 
   - This step is crucial for performance, as it allows the generated code to utilize the specific features and optimizations of the target GPU architecture
   - NVIDIA GPU driver does not interpret PTX directly, it does play a role in managing the execution of kernels and facilitating communication between the host and device. The driver may also handle the loading of compiled binaries at runtime

#### 2. `NVIDIA GPU Driver`
   - Role of the Driver
   
     - The NVIDIA GPU driver is responsible for managing the communication between the CUDA applications (running on the CPU) and the GPU hardware. 
     
     - It handles various tasks, including:
         - Loading compiled CUDA binaries (cubin or fatbin) into memory.
         - Managing memory allocation and data transfers between the host (CPU) and device (GPU).
         - Scheduling kernel execution on the GPU.
         
      - PTX Handling \
         When a CUDA application is executed, if it contains PTX code, the driver will invoke ptxas to compile this PTX into machine code for execution on the specific GPU architecture. This compilation happens at runtime if the PTX is not already compiled into a binary format.

      - Driver Versions: \
         It’s important to note that different versions of the NVIDIA driver may support different features of CUDA and PTX, which can impact performance and compatibility with specific GPU architectures.

#### 3. `Can cuda application contain ptx code?`
   Yes, a CUDA application can indeed contain PTX (Parallel Thread Execution) code.\
   Here are the key points regarding the inclusion and use of PTX in CUDA applications:
   
   - Forward Compatibility:\
      PTX is designed to be forward-compatible, meaning that PTX code generated for a specific compute capability can run on any GPU with a higher compute capability. This allows developers to write code that can be executed on future GPU architectures without modification.
   
  - Compilation Process\
      When a CUDA application is compiled, it can include both architecture-specific binary files (cubin) and PTX code. The CUDA runtime will automatically select the appropriate version to execute based on the capabilities of the available GPU. If a compatible cubin is available, it will be used; otherwise, the runtime will JIT (Just-In-Time) compile the PTX code into native machine code for execution.

  - Benefits of Including PTX\
      Including PTX in a CUDA application enhances its compatibility with future hardware. It allows the application to leverage new GPU features as they become available without needing recompilation, provided the PTX was generated with an appropriate target architecture.

  - JIT Compilation\
      When PTX is used, the CUDA driver will JIT-compile this code into machine-specific instructions at runtime. This process incurs some overhead but enables flexibility across different GPU architectures5.

#### 4. `CUDA Binary`

   - A CUDA binary, commonly referred to as a cubin file, is an ELF (Executable and Linkable Format) file that contains sections for CUDA executable code.
   
   - `Cubin` files include not only the executable code section but also sections for symbols, relocation information, and debug data, which are essential for linking and debugging.
   
   - By default, CUDA compiler driver "nvcc" embeds the cubin files into the host executable file. However, standalone cubin files can also be generated using the `-cubin` option with `nvcc`. 
   
      ```
      # with -cubin option nvcc compiler generates separate cuda binary i.e. `.cubin` file instead of embedding it inside host binary file.
      
      nvcc -cubin      	
      

      # These options provide verbose output about register usage, shared memory, and local memory utilization during the compilation of the CUDA program.
     
      nvcc -Xptxas="-v" 
      (or) nvcc --ptxas-options -v    
      ```

#### 5. `cuobjdump`
   - Go through following website to get more idea about "cudaobjdump" or "nvdisasm" utilities and also to know more about the options available along with cuobjdump.
      ```
      http://cseweb.ucsd.edu/classes/wi15/cse262-a/static/cuda-5.5-doc/pdf/CUDA_Binary_Utilities.pdf
      ```
   - `cuobjdump` can disassemble both `standalone cubin` files and also cubin files embedded in host executables, presenting the output in a human-readable format.
   - `cuobjdump` can extract PTX code from both the standalone `.cubin` files and from the host executable files.
   - `cuobjdump` does not provide control flow analysis, this capability is instead offered by the `nvdisasm` tool.
   - `cuobjdump` lacks the advanced display options that are available in `nvdisasm`, which offers richer output capabilities.
    
      ```Bash
      # Disassemble a standalone CUBIN file and present it in human-readable format
      cuobjdump -sass <input_file.cubin>  

      # Extract PTX code from a CUBIN file or from a host executable
      # Replace <input_file> with your CUBIN or host executable (.exe file on windows)
      cuobjdump -ptx <input_file>  

      # Dump the ELF sections of a CUBIN file in human-readable format
      cuobjdump -elf <input_file.cubin>  

      # Dump all fatbin sections from a CUBIN file
      cuobjdump --all-fatbin <input_file.cubin>  

      # Dump ELF symbol names from a CUBIN file
      cuobjdump --dump-elf-symbols <input_file.cubin>  

      # Dump CUDA assembly for all embedded CUBIN files in a host binary
      # Replace <host_executable> with your host executable file (.exe file on windows)
      cuobjdump -sass <host_executable>  
      ```

#### 6. `nvdisasm`
   - `nvdisasm` disassembles CUBIN files, presenting the output in a human-readable format.
   - It can also extract information from host executables that contain embedded CUBIN files. 
   - `nvdisasm` performs control flow analysis to annotate jump and branch targets in the disassembled output, making it easier to understand the flow of the program.
   - `nvdisasm` provides various command-line options that allow users to customize the output format and control what information is displayed.
     
     ```Bash
     # Disassemble a standalone CUBIN file and present it in human-readable format
     nvdisasm <input_file.cubin>  
     
     # Perform control flow analysis while disassembling a CUBIN file
     nvdisasm -cf <input_file.cubin>  
     
     # Turn off control flow analysis if relocation information is missing
     nvdisasm -ndf <input_file.cubin>  
     
     # Disassemble a CUBIN file and specify the architecture (e.g., SM70)
     # Specifies the architecture for disassembly; 
     # replace SM70 with the appropriate architecture version as needed.
     nvdisasm -b SM70 <input_file.cubin>  
     
     # Use advanced display options, such as sorting functions when dumping assembly for better readability.
     nvdisasm --sort-functions <input_file.cubin>  
     ```

#### 7. What is difference between cuda executable file that is `.cubin` file and `.exe` file? 
   - `CUDA Executable File (.cubin)`
      - **Format** \
      A .cubin file is an ELF (Executable and Linkable Format) formatted file specifically designed for CUDA applications. It contains compiled GPU code that can be executed directly on NVIDIA GPUs.

      - **Contents**\
      The .cubin file includes sections for CUDA executable code, symbols, relocation information, and debug information. It is primarily focused on the GPU's execution environment.

      - **Usage**\
      CUBIN files are loaded at runtime by the CUDA driver API when a CUDA application is executed. They contain the low-level machine code that the GPU understands.

      - **Generation**\
      These files can be generated separately using the nvcc compiler with the -cubin option.

   - `Host Executable File (.exe or no extension)`
      
      - **Format**\
      A host executable file is typically in a format native to the operating system, such as .exe for Windows or no extension for Linux. It contains CPU code that runs on the host machine.
      
      - **Contents**\
      The host executable may contain various sections, including the main application logic, libraries, and potentially embedded CUBIN files. It serves as the entry point for executing the application on the CPU.
      
      - **Usage**\
      This file is executed by the operating system and manages CPU tasks, including invoking CUDA kernels that run on the GPU.

      - **Generation**\
      Host executables are created by compiling source code (which may include CUDA code) using a compiler like nvcc, which can embed CUBIN files within them.

   - `Summary of Key Differences`
      
      |Feature    |	.cubin File                         |	Host Executable File                         |
      |-----------|--------------------------------------|-----------------------------------------------|
      |Format     |	ELF formatted	                     |  OS-specific format (.exe or none)            |
      |Contents   |	GPU executable code	               |  CPU executable code, possibly embedded CUBIN |
      |Usage      |	Loaded and executed by CUDA driver	|  Executed by the operating system             |
      |Generation |	Generated with `nvcc -cubin`	      |  Generated with `nvcc` (default)              |