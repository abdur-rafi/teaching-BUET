# Dynamic Memory Allocation in C

## Memory Segments in a C Program
A running C program uses several memory segments:
- **Code/Text:** Stores the program instructions.
- **Data:** Stores global and static variables.
- **Stack:** Stores function call information and local variables. Automatically managed.
- **Heap:** Used for dynamic memory allocation (e.g., with `malloc`). You must manage this memory yourself.

---

## How to Return an Array from a Function?
Suppose you want a function to create and return an array. What happens if you try to return a pointer to a local array?

```c
#include <stdio.h>

int* make_array() {
    int arr[5] = {1, 2, 3, 4, 5}; // Local array (lives on the stack)
    return arr; // Problem: returning pointer to local variable
}

int main() {
    int *p = make_array();
    printf("First element: %d\n", p[0]); // May print garbage or crash
    return 0;
}
```
**Problem:** The array `arr` is destroyed when `make_array` ends. The pointer `p` in `main` points to invalid memory (undefined behavior).

---

## Solution: Use Dynamic Memory Allocation
We can allocate memory inside the function using `malloc`. This memory stays valid until we `free` it, even after the function returns.

```c
#include <stdio.h>
#include <stdlib.h>

int* make_array() {
    int *arr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) arr[i] = i + 1;
    return arr; // OK: arr points to heap memory
}

int main() {
    int *p = make_array();
    printf("First element: %d\n", p[0]); // Safe
    free(p); // Don't forget to free!
    return 0;
}
```

---

Dynamic memory allocation lets you request memory at runtime (while the program is running), instead of at compile time. This is useful for:
- Allocating large arrays (to avoid stack overflow; you do not need to understand stack overflow)
- Sharing arrays between functions (e.g., returning arrays from functions)
- Saving memory by allocating just what you need (e.g., for strings of different lengths)

## Key Functions
- `malloc(size)`: Allocates a block of memory of `size` bytes. Returns a pointer to the beginning of the block. Example: `malloc(10 * sizeof(int))` allocates space for 10 integers.
- `calloc(n, size)`: Allocates memory for an array of `n` elements, each of `size` bytes, and initializes all bytes to zero. Example: `calloc(10, sizeof(int))` allocates and zeroes space for 10 integers.
- `realloc(ptr, new_size)`: Changes the size of the memory block pointed to by `ptr` to `new_size` bytes. The contents will be unchanged up to the minimum of the old and new sizes. Example: `realloc(arr, 20 * sizeof(int))` resizes the block for 20 integers.
- `free(ptr)`: Releases the memory block pointed to by `ptr` so it can be reused by the system. Example: `free(arr)`.

All are in `<stdlib.h>`.

**Note:**
- `NULL` is a special value that means "no valid address" or "nothing". In C, `NULL` is basically zero, and no valid address of allocated memory starts with 0.
- If `malloc` (or similar functions) cannot allocate memory, it returns `NULL`.
- Always check if the pointer returned by `malloc` is `NULL` before using it. If you use a `NULL` pointer, your program may crash.

---

## Example: Allocating a Large Array 
Suppose you want to process a very large number of elements (e.g., 1 million). Declaring `int arr[1000000];` may cause a stack overflow. Dynamic memory allocation uses the heap, which is much larger.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 1000000; // 1 million
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Use the array (e.g., set all to 1)
    for (int i = 0; i < n; i++) arr[i] = 1;
    printf("First: %d, Last: %d\n", arr[0], arr[n-1]);
    free(arr);
    return 0;
}
```

---

## Example 2: 2D Array (Matrix)
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;
    int **mat = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
        mat[i] = (int*)malloc(cols * sizeof(int));
    // Fill and print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = i + j;
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    // Free memory
    for (int i = 0; i < rows; i++) free(mat[i]);
    free(mat);
    return 0;
}
```

---

## How 2D Matrix Allocation Works
When you allocate a 2D matrix like this:
```c
int **mat = malloc(rows * sizeof(int*));
for (int i = 0; i < rows; i++)
    mat[i] = malloc(cols * sizeof(int));
```
- `mat` is a pointer to an array of pointers. Each `mat[i]` is a pointer to a row (an array of `int`).
- First, you allocate memory for the array of row pointers.
- Then, for each row, you allocate memory for the actual data (the columns).
- This way, you can access elements as `mat[i][j]`.
- Don't forget to free each row and then the array of pointers:
  ```c
  for (int i = 0; i < rows; i++) free(mat[i]);
  free(mat);
  ```

---

## Example 3: Structures with Dynamic Memory
Suppose you want to store names of students:
```c
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char *name;
    int id;
};

int main() {
    struct Student s;
    s.name = (char*)malloc(50 * sizeof(char)); // up to 49 chars
    printf("Enter name: ");
    scanf("%49s", s.name);
    s.id = 123;
    printf("Name: %s, ID: %d\n", s.name, s.id);
    free(s.name);
    return 0;
}
```

---

## Example 4: Saving Memory with Dynamic Allocation (Strings)
Suppose you want to store a list of names entered by the user. If you use a 2D array like `char names[5][100];`, every name uses 100 bytes, even if most names are much shorter. This wastes memory.

With dynamic memory allocation, you can allocate just enough space for each name:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar(); // consume newline
    char **names = malloc(n * sizeof(char*));
    char temp[100];
    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i+1);
        fgets(temp, 100, stdin);
        int len = strlen(temp);
        if (len > 0 && temp[len-1] == '\n') temp[len-1] = '\0'; // remove newline
        names[i] = malloc(len + 1); // allocate just enough
        strcpy(names[i], temp);
    }
    printf("\nNames entered:\n");
    for (int i = 0; i < n; i++) printf("%s\n", names[i]);
    for (int i = 0; i < n; i++) free(names[i]);
    free(names);
    return 0;
}
```

## How String Array Allocation Works
When you store strings using dynamic memory:
```c
char **names = malloc(n * sizeof(char*));
for (int i = 0; i < n; i++) {
    names[i] = malloc(length_of_string + 1); // +1 for null terminator
    // copy the string into names[i]
}
```
- `names` is a pointer to an array of pointers. Each `names[i]` is a pointer to a string (an array of `char`).
- You first allocate memory for the array of string pointers.
- For each string, you allocate just enough memory to store it.
- This saves memory compared to a fixed-size 2D array.
- Free each string and then the array of pointers:
  ```c
  for (int i = 0; i < n; i++) free(names[i]);
  free(names);
  ```

---

## Tips
- Always `free` memory you allocate.
- Check if `malloc`/`calloc` returns `NULL` (allocation failed).
- For 2D arrays, free each row, then the array of pointers.

---

## Why You Must Free Memory Properly
When you use `malloc` (or similar functions), the memory is taken from the heap and is not automatically returned to the system when you are done using it. If you forget to free memory:
- The memory stays reserved and cannot be used again while your program runs. This is called a **memory leak**.
- If your program runs for a long time or allocates memory many times, it can eventually use up all available memory and crash or slow down the system.
- Always free each block of memory you allocate with `malloc`, `calloc`, or `realloc` when you no longer need it.
- For 2D arrays or arrays of strings, free each row/string first, then the array of pointers.

**Caution:**
- After you free memory, the pointer still holds the old address, but you are not allowed to use it anymore. Accessing memory after it is freed is called **dangling pointer** usage and can cause crashes or bugs.
- To avoid mistakes, you can set the pointer to `NULL` after freeing:
  ```c
  free(arr);
  arr = NULL;
  ```
- Now, if you accidentally use the pointer, it is easier to detect the error (since `NULL` is not a valid address).

**Summary:**
> Freeing memory is your responsibility in C. Not freeing memory wastes resources and can cause your program to misbehave. Never use memory after it has been freed.

---

**Summary:**
Dynamic memory allocation is essential for flexible programs. Practice with arrays, 2D arrays, and structures to get comfortable.
