## Lab Worksheet: Finding and Arranging Data in C

**Course:** CSE 296
---

### **Objectives:**

Upon completion of this lab, students will be able to:

* Understand basic ways to find specific data in an array.
* Understand basic ways to arrange data in a specific order in an array.
* Write C programs to find items in an array using two different methods.
* Write a C program to arrange items in an array using one method.
* See how fast these different methods perform when dealing with many items.

---

### **Part 1: Finding Data in an Array**

**Introduction:** Finding is the process of locating a specific item within a collection of items (like numbers in an array). We will explore two common methods for finding data: Linear Search and Binary Search.

#### **Task 1.1: Linear Search (Checking One by One)**

**Concept:** Linear Search is the simplest way to find an item. It works by looking at each item in the array, one after another, until it finds what it's looking for or reaches the end of the array.

**Steps for this method:**

1.  Start at the very first item in your array.
2.  Compare the current item with the item you are trying to find.
3.  If they are the same, you found it! Stop and remember where you found it (its position).
4.  If they are not the same, move to the next item in the array.
5.  Keep repeating steps 2-4 until you find the item or you run out of items to check.
6.  If you checked all items and didn't find it, that means the item is not in the array.

**Implementation (C Code Structure):**

```c
#include <stdio.h>

// Function to perform Linear Search (checking one by one)
int linearSearch(int arr[], int size, int target) {
    // Your code here
    // Use a loop to go through each number in the 'arr' list
    // Inside the loop, check if the current number is equal to 'target'
    // If it is, return the position (index) of that number
    // If the loop finishes and you haven't returned, it means the number wasn't found, so return -1
    return -1; // Placeholder
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculates how many numbers are in the list
    int target1 = 50; // An item we expect to find
    int target2 = 95; // An item we do not expect to find
    int result;

    printf("Numbers in our list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Test Case 1: Searching for an item that is in the list
    result = linearSearch(arr, size, target1);
    if (result != -1) {
        printf("Item %d found at position %d using Linear Search.\n", target1, result);
    } else {
        printf("Item %d not found using Linear Search.\n", target1);
    }

    // Test Case 2: Searching for an item that is NOT in the list
    result = linearSearch(arr, size, target2);
    if (result != -1) {
        printf("Item %d found at position %d using Linear Search.\n", target2, result);
    } else {
        printf("Item %d not found using Linear Search.\n", target2);
    }

    return 0;
}
```

**Exercise 1.1.1:** Complete the `linearSearch` function in the provided C code structure. Compile and run the code to check if it works correctly.

#### **Task 1.2: Binary Search**

**Concept:** Binary Search is a much faster way to find an item, but it has a very important requirement: the list **must be sorted** (arranged in increasing or decreasing order). It works by repeatedly cutting the search area in half. Imagine finding a word in a dictionary – you don't start from page 1, you open to the middle and decide which half to look in next.

**Steps for this method:**

1.  Find the item in the very middle of your list.
2.  Compare the middle item with the item you are trying to find.
    a.  If they are the same, you found it! Stop and remember its position.
    b.  If the middle item is *smaller* than what you're looking for, it means your item must be in the *right half* of the list (since it's sorted). So, ignore the left half.
    c.  If the middle item is *larger* than what you're looking for, it means your item must be in the *left half* of the list. So, ignore the right half.
3.  Now, repeat steps 1-2 with the remaining half of the list.
4.  Keep doing this until you find the item or the part of the list you're looking in becomes empty (meaning the item isn't there).

**Implementation (C Code Structure):**

```c
#include <stdio.h>

// Function to perform Binary Search (divide and conquer)
int binarySearch(int arr[], int size, int target) {
    int low = 0; // Starting position of our search area
    int high = size - 1; // Ending position of our search area

    // Your code here
    // Use a loop that continues as long as 'low' is less than or equal to 'high'
    // Inside the loop:
    // 1. Calculate 'mid' (the middle position: low + (high - low) / 2)
    // 2. Check if arr[mid] is equal to 'target'. If yes, return 'mid'.
    // 3. If arr[mid] is less than 'target', update 'low' to mid + 1 (look in the right half)
    // 4. If arr[mid] is greater than 'target', update 'high' to mid - 1 (look in the left half)
    return -1; // Placeholder
}

int main() {
    // IMPORTANT: This list MUST be sorted (arranged in order) for Binary Search to work!
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target1 = 70; // An item we expect to find
    int target2 = 25; // An item we do not expect to find
    int result;

    printf("Sorted numbers in our list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Test Case 1: Searching for an item that is in the list
    result = binarySearch(arr, size, target1);
    if (result != -1) {
        printf("Item %d found at position %d using Binary Search.\n", target1, result);
    } else {
        printf("Item %d not found using Binary Search.\n", target1);
    }

    // Test Case 2: Searching for an item that is NOT in the list
    result = binarySearch(arr, size, target2);
    if (result != -1) {
        printf("Item %d not found using Binary Search.\n", target2);
    } else {
        printf("Item %d not found using Binary Search.\n", target2);
    }

    return 0;
}
```

**Exercise 1.2.1:** Complete the `binarySearch` function in the provided C code structure. Compile and run the code to check if it works correctly.

---

### **Part 2: Arranging Data in a List**

**Introduction:** Arranging (or sorting) is the process of putting items in a specific order (like from smallest to largest or largest to smallest). We will implement a simple arranging method called Bubble Sort.

#### **Task 2.1: Bubble Sort (Swapping Neighbors)**

**Concept:** Bubble Sort is a straightforward way to arrange items. It repeatedly goes through the list, compares two neighboring items, and swaps them if they are in the wrong order. It keeps doing this until no more swaps are needed, which means the list is fully arranged. Think of bubbles rising to the surface – larger numbers "bubble up" to their correct positions.

**Steps for this method (to arrange from smallest to largest):**

1.  Start at the beginning of the list.
2.  Compare the first item with the second. If the first is larger than the second, swap their positions.
3.  Then, compare the second item with the third. If the second is larger than the third, swap their positions.
4.  Continue this process for the entire list, comparing each pair of neighbors and swapping if they are out of order. After one full pass through the list, the largest item will have "bubbled up" to its correct last position.
5.  Now, repeat steps 1-4 for the remaining unsorted part of the list (ignoring the last item, which is now in place).
6.  Keep repeating these passes until a full pass happens with no swaps at all. This means the list is fully arranged.

**Implementation (C Code Structure):**

```c
#include <stdio.h>

// Function to perform Bubble Sort (arranging by swapping neighbors)
void bubbleSort(int arr[], int size) {
    int i, j;
    int temp; // A temporary space to hold a number during a swap
    int swapped; // A flag to tell us if any swap happened in a pass

    // Your code here
    // The outer loop (for 'i') controls how many passes we make through the list.
    // The inner loop (for 'j') goes through the list, comparing and swapping neighbors.
    // Use the 'swapped' flag: if no swaps occur in an entire inner loop, the list is sorted, so you can stop early.
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, size); // Call your function to arrange the list

    printf("Arranged list (using Bubble Sort): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```

**Exercise 2.1.1:** Complete the `bubbleSort` function in the provided C code structure. Compile and run the code to check if it works correctly.

---

### **Part 3: Seeing How Fast They Run**

**Introduction:** How fast a method runs becomes very important when you have a lot of items to process. We will measure the time it takes for our finding methods to work on large lists and compare them.

**Important Note about Time Measurement:**
The code snippets below include lines that calculate how long parts of your program take to run. **You do not need to write this time-measuring code yourself or understand how it works.** Just know that these specific lines are there to give you a measurement of the time taken.

#### **Task 3.1: Speed Test for Finding Methods**

In real-world situations, you often need to find many items in a list, not just one. For example, imagine a huge email service like Gmail. Every time a user tries to log in, the system needs to quickly check if that email address exists among billions of accounts. This check happens millions of times a day! In such cases, the choice of finding method becomes extremely important for how quickly the system responds to each login attempt. We will simulate this by performing many searches.

```c
#include <stdio.h>
#include <stdlib.h> // For rand() (random numbers) and malloc()/free() (managing memory)
#include <time.h>   // For clock() (measuring time)

// >>> PASTE YOUR LINEAR SEARCH FUNCTION HERE (from Task 1.1) <<<
// Your function should have the signature: int linearSearch(int arr[], int size, int target)
// For example:
// int linearSearch(int arr[], int size, int target) {
//     // Your code goes here
// }


// >>> PASTE YOUR BINARY SEARCH FUNCTION HERE (from Task 1.2) <<<
// Your function should have the signature: int binarySearch(int arr[], int size, int target)
// Remember, Binary Search assumes the list is sorted.
// For example:
// int binarySearch(int arr[], int size, int target) {
//     // Your code goes here
// }


// Function to fill a list with random numbers (for Linear Search)
void generateRandomArray(int arr[], int size) {
    srand(time(NULL)); // Makes sure we get different random numbers each time we run
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000; // Random numbers up to 1,000,000
    }
}

// Function to fill a list with numbers already in sorted order (for Binary Search)
void generateSortedArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i; // Numbers from 0 to size-1, already perfectly sorted
    }
}


int main() {
    int large_list_size = 1000000; // This controls how many numbers are in our test list
    int num_searches = 10000;      // How many times we will search for items

    // We create two large lists in computer memory
    int* list_for_linear_search = (int*)malloc(large_list_size * sizeof(int));
    int* list_for_binary_search = (int*)malloc(large_list_size * sizeof(int));

    if (list_for_linear_search == NULL || list_for_binary_search == NULL) {
        printf("Not enough memory to create the large lists!\n");
        return 1;
    }

    // Fill the list for Linear Search with random numbers (it does not need to be sorted)
    generateRandomArray(list_for_linear_search, large_list_size);

    // Fill the list for Binary Search with numbers already sorted (this is required for Binary Search)
    generateSortedArray(list_for_binary_search, large_list_size);
    printf("Successfully prepared lists for searching.\n\n");


    // Prepare items to search for
    // We'll search for 'num_searches' items, some present, some not.
    // The targets are chosen within the range of numbers generated for the sorted list (0 to large_list_size-1)
    int* search_targets = (int*)malloc(num_searches * sizeof(int));
    if (search_targets == NULL) {
        printf("Memory allocation for search targets failed!\n");
        free(list_for_linear_search);
        free(list_for_binary_search);
        return 1;
    }

    srand(time(NULL) + 1); // New seed for targets
    for (int i = 0; i < num_searches / 2; i++) {
        // Pick existing items from the range 0 to large_list_size-1
        search_targets[i] = rand() % large_list_size; 
    }
    for (int i = num_searches / 2; i < num_searches; i++) {
        // Pick non-existing items (outside the range 0 to large_list_size-1)
        search_targets[i] = large_list_size + (rand() % 1000000); 
    }


    clock_t start_time, end_time; // Variables to store start and end times
    double time_spent_in_seconds; // Variable to store the duration

    printf("--- Speed Test for Finding Methods (List Size: %d numbers, %d searches) ---\n", large_list_size, num_searches);

    // Test Linear Search (checking one by one) repeatedly
    printf("Starting Linear Search (repeatedly)....\n");
    start_time = clock(); // Record the start time
    for (int i = 0; i < num_searches; i++) {
        linearSearch(list_for_linear_search, large_list_size, search_targets[i]);
    }
    end_time = clock(); // Record the end time
    time_spent_in_seconds = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Total time for Linear Search (%d searches): %f seconds\n\n", num_searches, time_spent_in_seconds);

    // Test Binary Search (divide and conquer) repeatedly
    printf("Starting Binary Search (repeatedly)....\n");
    start_time = clock();
    for (int i = 0; i < num_searches; i++) {
        binarySearch(list_for_binary_search, large_list_size, search_targets[i]);
    }
    end_time = clock();
    time_spent_in_seconds = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Total time for Binary Search (%d searches): %f seconds\n", num_searches, time_spent_in_seconds);

    free(list_for_linear_search);  // Release the memory used by the large list for linear search
    free(list_for_binary_search);  // Release memory for the large list for binary search
    free(search_targets);          // Release memory for search targets
    return 0;
}
```

**Exercise 3.1.1:** Add your functions `linearSearch` and `binarySearch` from task 1 here, then compile and run the program. Observe the total times it takes for Linear Search and Binary Search when performing many searches on the large lists.

**Expected Results and Why:**

When you perform many searches, the difference in speed between the two methods becomes very clear:

* **Linear Search** will take a significant amount of time. For each item it searches, it might have to check almost every entry in the list, especially if the item isn't there or is near the end. Since millions of login attempts happen, these small delays add up quickly, resulting in a very long total time.

* **Binary Search**, on the other hand, will be incredibly fast for the same number of searches. Because it repeatedly halves the search area, it finds items (or determines they are absent) in very few steps, even in a list of billions. When you repeat this very fast process many times, the total time remains incredibly low.

This shows that for situations where you frequently need to find items in a large list, it's very important to keep the list organized (sorted) and use a smart finding method like Binary Search. While setting up a sorted list initially might take some time, the massive speed benefits you gain from all the subsequent quick searches make it well worth the effort for large-scale, repeated lookup tasks.

---

### **Submission Guidelines**
### Submission Instructions

1. **Organize your files as follows:**
    - Create a folder named with your student ID (e.g., `20231234`)
    - Rename each C code file according to the task, using a relevant suffix:
        - `linear_search.c`
        - `binary_search.c`
        - `bubble_sort.c`
        - `speed_test.c`
    - Save the output of your speed test program as `speed_test_output.txt`

    2. **Folder Structure Example:**
        ```
        20231234/
        ├── linear_search.c
        ├── binary_search.c
        ├── bubble_sort.c
        ├── speed_test.c
        └── speed_test_output.txt
        ```

    3. **Compress your folder:**
        - Zip the folder named with your student ID (e.g., `20231234.zip`)

4. **Submit the zipped folder.**

---