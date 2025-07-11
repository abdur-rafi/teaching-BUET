# Lecture: Introduction to NumPy

## 1. Motivation & Overview
- **Why use NumPy?**
  - Python lists are flexible but slow for large numerical data.
  - NumPy provides fast, memory-efficient arrays and mathematical functions.
  - Used in data analysis, engineering, science, and machine learning.
- **Real-world examples:**
  - Weather data analysis, image processing, financial modeling, scientific computing.

## 2. What is NumPy?
- **Brief history:**
  - NumPy stands for Numerical Python. It is the foundation for most scientific computing in Python.
- **Key features:**
  - N-dimensional arrays (ndarray)
  - Fast mathematical operations
  - Tools for linear algebra, statistics, and more

## 3. Installing and Importing NumPy
- **Installation:**
  - Open terminal/command prompt and run:
    ```bash
    pip install numpy
    ```
- **Importing:**
  - In your Python script or notebook:
    ```python
    import numpy as np
    ```

## 4. NumPy Arrays vs Python Lists
- **Python List Example:**
    ```python
    my_list = [1, 2, 3, 4]
    print(my_list)
    ```
- **NumPy Array Example:**
    ```python
    import numpy as np
    my_array = np.array([1, 2, 3, 4])
    print(my_array)
    ```
- **Differences:**
  - NumPy arrays are faster and use less memory.
  - Support element-wise operations (e.g., `my_array * 2` multiplies every element).

- **Speed Comparison: Python List vs NumPy Array**

  The following code demonstrates how to compare the speed of matrix addition using regular Python lists and NumPy arrays. This version avoids list comprehensions and uses simple for-loops for clarity:

  ```python
  import time
  import numpy as np

  # Set the size of the matrix (1000x1000)
  size = 1000

  # Create two matrices using Python lists (with for-loops)
  print("Creating two 1000x1000 matrices using Python lists...")
  py_list1 = []
  py_list2 = []
  for i in range(size):
      row1 = []
      row2 = []
      for j in range(size):
          row1.append(i)
          row2.append(i)
      py_list1.append(row1)
      py_list2.append(row2)

  # Create two matrices using NumPy arrays
  print("Creating two 1000x1000 matrices using NumPy arrays...")
  np_array1 = np.array(py_list1)
  np_array2 = np.array(py_list2)

  # Matrix addition with Python lists (using for-loops)
  print("Adding the two Python list matrices...")
  start = time.time()
  result_list = []
  for i in range(size):
      row = []
      for j in range(size):
          row.append(py_list1[i][j] + py_list2[i][j])
      result_list.append(row)
  end = time.time()
  print(f"Python list addition took: {end - start:.4f} seconds")

  # Matrix addition with NumPy arrays
  print("Adding the two NumPy array matrices...")
  start = time.time()
  result_np = np_array1 + np_array2
  end = time.time()
  print(f"NumPy array addition took: {end - start:.4f} seconds")

  # Optional: Check if the results are the same
  print("Are the results equal?", np.allclose(result_np, result_list))
  ```

  **What to expect:**
  - The code first creates two large matrices using both Python lists and NumPy arrays.
  - It then adds the matrices using both methods and measures the time taken for each.
  - NumPy will be much faster than the Python list approach.
  - The final check confirms that both methods give the same result.

  You can try similar comparisons for multiplication and other operations.

## 5. Creating NumPy Arrays
- **1D Array Example:**
    ```python
    arr_1d = np.array([1, 2, 3, 4, 5])
    print(arr_1d)
    print('Shape:', arr_1d.shape)  # (5,)
    print('Number of dimensions:', arr_1d.ndim)  # 1
    ```
- **2D Array Example:**
    ```python
    arr_2d = np.array([[1, 2, 3], [4, 5, 6]])
    print(arr_2d)
    print('Shape:', arr_2d.shape)  # (2, 3)
    print('Number of dimensions:', arr_2d.ndim)  # 2
    ```
- **3D Array Example:**
    ```python
    arr_3d = np.array([
        [[1, 2], [3, 4]],
        [[5, 6], [7, 8]]
    ])
    print(arr_3d)
    print('Shape:', arr_3d.shape)  # (2, 2, 2)
    print('Number of dimensions:', arr_3d.ndim)  # 3
    ```
- **Built-in functions:**
    ```python
    zeros = np.zeros((2, 3))      # 2x3 array of zeros
    ones = np.ones((3, 2))        # 3x2 array of ones
    # np.arange creates an array with regularly spaced values within a given range.
    # Syntax: np.arange(start, stop, step)
    arange = np.arange(0, 10, 2)  # [0, 2, 4, 6, 8]
    print('arange:', arange)
    # np.linspace creates an array of evenly spaced numbers over a specified interval.
    # Syntax: np.linspace(start, stop, num)
    linspace = np.linspace(0, 1, 5) # 5 numbers from 0 to 1 (inclusive)
    print('linspace:', linspace)
    ```
    - `np.arange(start, stop, step)`: Creates values starting from `start` up to (but not including) `stop`, spaced by `step`.
    - `np.linspace(start, stop, num)`: Creates `num` evenly spaced values from `start` to `stop` (including both endpoints).
- **Array shapes and dimensions:**
    ```python
    arr = np.array([[1, 2, 3], [4, 5, 6]])
    print(arr.shape)  # (2, 3)
    print(arr.ndim)   # 2
    ```

## 6. Array Operations
- **Element-wise operations:**
    ```python
    a = np.array([1, 2, 3])
    b = np.array([4, 5, 6])
    print(a + b)  # [5 7 9]
    print(a * b)  # [4 10 18]
    print(a ** 2) # [1 4 9]
    ```
- **Broadcasting basics:**
    ```python
    arr = np.array([1, 2, 3])
    print(arr + 10)  # [11 12 13]
    ```
- **Useful functions:**
    ```python
    arr = np.array([1, 2, 3, 4])
    print(np.sum(arr))   # 10
    print(np.mean(arr))  # 2.5
    print(np.max(arr))   # 4
    ```

## 6a. Matrix Operations
- **Creating 2D arrays (matrices):**
    ```python
    mat = np.array([[1, 2], [3, 4]])
    ```
- **Matrix addition and subtraction:**
    ```python
    a = np.array([[1, 2], [3, 4]])
    b = np.array([[5, 6], [7, 8]])
    print(a + b)  # [[ 6  8]
                 #  [10 12]]
    print(a - b)  # [[-4 -4]
                 #  [-4 -4]]
    ```
- **Matrix multiplication:**
    ```python
    # Element-wise multiplication
    print(a * b)  # [[ 5 12]
                 #  [21 32]]
    # Matrix multiplication
    print(np.dot(a, b))  # [[19 22]
                        #  [43 50]]
    print(a @ b)         # Same as above
    ```
- **Transpose:**
    ```python
    print(a.T)  # [[1 3]
               #  [2 4]]
    ```
- **Identity, inverse, determinant:**
    ```python
    print(np.eye(3))  # 3x3 identity matrix
    print(np.linalg.inv(mat))  # Inverse
    print(np.linalg.det(mat))  # Determinant
    ```

## 6b. Calculating Min, Max, Average, and Standard Deviation

- **For 1D arrays:**
    ```python
    arr_1d = np.array([10, 20, 30, 40, 50])
    print('Min:', np.min(arr_1d))
    print('Max:', np.max(arr_1d))
    print('Average (Mean):', np.mean(arr_1d))
    print('Standard Deviation:', np.std(arr_1d))
    ```

- **For 2D arrays:**
    ```python
    arr_2d = np.array([[1, 2, 3], [4, 5, 6]])
    print('Min:', np.min(arr_2d))
    print('Max:', np.max(arr_2d))
    print('Average (Mean):', np.mean(arr_2d))
    print('Standard Deviation:', np.std(arr_2d))
    # Min, max, mean, std for each column
    print('Column-wise min:', np.min(arr_2d, axis=0))
    print('Column-wise max:', np.max(arr_2d, axis=0))
    print('Column-wise mean:', np.mean(arr_2d, axis=0))
    print('Column-wise std:', np.std(arr_2d, axis=0))
    # Min, max, mean, std for each row
    print('Row-wise min:', np.min(arr_2d, axis=1))
    print('Row-wise max:', np.max(arr_2d, axis=1))
    print('Row-wise mean:', np.mean(arr_2d, axis=1))
    print('Row-wise std:', np.std(arr_2d, axis=1))
    ```

## 7. Indexing and Slicing
- **Basics:**
    ```python
    arr = np.array([1, 2, 3, 4, 5])
    print(arr[0])  # 1
    print(arr[1:4])  # [2 3 4]
    ```
- **2D Arrays:**
    ```python
    mat = np.array([[1, 2, 3], [4, 5, 6]])
    print(mat[0, 1])  # 2
    print(mat[:, 1])  # [2 5]
    print(mat[0, :])  # [1 2 3]
    ```
- **Boolean indexing:**
    ```python
    arr = np.array([1, 2, 3, 4, 5])
    print(arr[arr > 2])  # [3 4 5]
    
    # 2D array example
    mat = np.array([[1, 2, 3], [4, 5, 6]])
    # Get all elements greater than 3
    print(mat[mat > 3])  # [4 5 6]
    # Get all even elements
    print(mat[mat % 2 == 0])  # [2 4 6]
    ```

## 8. Practical Examples

- **Image Processing (Grayscale and RGB)**
- Loading and manipulating images using NumPy and matplotlib.

**Grayscale Image Example:**
```python
import numpy as np
import matplotlib.pyplot as plt

# Load a grayscale image
image = plt.imread('grayscale_image.png')  # Use a PNG or JPG file
print('Image shape:', image.shape)

# Show the original image
plt.imshow(image, cmap='gray')
plt.title('Original Grayscale Image')
plt.show()

# Invert the image (negative)
inverted = 1. - image
plt.imshow(inverted, cmap='gray')
plt.title('Inverted Grayscale Image')
plt.show()

# Thresholding: Make all pixels above 128 white, below 128 black
thresholded = (image > .5) * 1
plt.imshow(thresholded, cmap='gray')
plt.title('Thresholded Grayscale Image')
plt.show()

# Crop the image (e.g., top-left 100x100 region)
cropped = image[:100, :100]
plt.imshow(cropped, cmap='gray')
plt.title('Cropped Grayscale Image')
plt.show()

# Flip the image vertically
flipped_v = np.flipud(image)
plt.imshow(flipped_v, cmap='gray')
plt.title('Vertically Flipped Grayscale Image')
plt.show()

# Flip the image horizontally
flipped_h = np.fliplr(image)
plt.imshow(flipped_h, cmap='gray')
plt.title('Horizontally Flipped Grayscale Image')
plt.show()

# Transpose the image (swap rows and columns)
transposed = np.transpose(image)
plt.imshow(transposed, cmap='gray')
plt.title('Transposed Grayscale Image')
plt.show()
```


## 9. Practice Problems

1. **Given a 4x4 matrix:**
    ```python
    matrix = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]])
    ```
    Perform the following operations (using numpy functions):
    - Print the maximum and minimum values in the matrix.
    - Print the average of each row and each column.
    - Print the transpose of the matrix.
    - Print the inverse of the matrix (if it exists).
    - Print the determinant of the matrix.
    - Print the adjoint of the matrix.
    - Print the Primary diagonal elements.
    - Print the Secondary diagonal elements.
    - Create a new matrix with only the secondary diagonal elements of the original matrix.
    - Create a new matrix with the primary diagonal elements set to 0.
    - Create a new matrix where in each row, only the elements which are greater than the average of that row are kept, and others are set to 0.
    - Create a new matrix containing the upper triangular part of the original matrix (including the diagonal).
    - Create a new matrix containing the lower triangular part of the original matrix (including the diagonal).
    - Replace all even numbers in the matrix with 0.




## 9a. Solutions to Practice Problems

Below are NumPy code snippets for each matrix operation in the practice problems:

```python
import numpy as np

matrix = np.array([[1, 2, 3, 4],
                   [5, 6, 7, 8],
                   [9, 10, 11, 12],
                   [13, 14, 15, 16]])

# 1. Maximum and minimum values
print('Max:', np.max(matrix))
print('Min:', np.min(matrix))

# 2. Average of each row and column
print('Row averages:', np.mean(matrix, axis=1))
print('Column averages:', np.mean(matrix, axis=0))

# 3. Transpose
print('Transpose:\n', matrix.T)

# 4. Inverse (if exists)
try:
    print('Inverse:\n', np.linalg.inv(matrix))
except np.linalg.LinAlgError:
    print('Inverse does not exist.')

# 5. Determinant
print('Determinant:', np.linalg.det(matrix))

# 6. Adjoint
adjoint = np.linalg.inv(matrix).T * np.linalg.det(matrix)
print('Adjoint:\n', adjoint)

# 7. Primary diagonal elements
print('Primary diagonal:', np.diag(matrix))

# 8. Secondary diagonal elements
print('Secondary diagonal:', np.diag(np.fliplr(matrix)))

# 9. Matrix with only secondary diagonal elements
sec_diag = np.zeros_like(matrix)
np.fill_diagonal(np.fliplr(sec_diag), np.diag(np.fliplr(matrix)))
print('Secondary diagonal matrix:\n', sec_diag)

# 10. Matrix with primary diagonal set to 0
mat_no_diag = matrix.copy()
np.fill_diagonal(mat_no_diag, 0)
print('Primary diagonal set to 0:\n', mat_no_diag)

# 11. Elements greater than row average kept, others set to 0
row_avg = np.mean(matrix, axis=1, keepdims=True)
gt_avg = np.where(matrix > row_avg, matrix, 0)
print('Elements > row avg:\n', gt_avg)

# 12. Upper triangular part (including diagonal)
print('Upper triangular:\n', np.triu(matrix))

# 13. Lower triangular part (including diagonal)
print('Lower triangular:\n', np.tril(matrix))



# 14. Replace all even numbers with 0
even_zero = np.where(matrix % 2 == 0, 0, matrix)
print('Even numbers replaced with 0:\n', even_zero)
```

## 10. Image Manipulation Practice Problems

Try these image manipulation problems using NumPy and matplotlib:

1. Load the grayscale image, transpose the array and display it.
2. Load the grayscale image, move the top half of the image to the bottom half and the bottom half to the top half, and display the result.

## 10a. Solutions to Image Manipulation Practice Problems

Below are NumPy code snippets for each image manipulation problem:

```python
import numpy as np
import matplotlib.pyplot as plt

# Load the grayscale image
image = plt.imread('grayscale.png')  # Use the correct filename if different
print('Image shape:', image.shape)

# 1. Transpose the array and display it
transposed = np.transpose(image)
plt.imshow(transposed, cmap='gray')
plt.title('Transposed Grayscale Image')
plt.show()


# 2. Move the top half to the bottom and the bottom half to the top, then display
h = image.shape[0] // 2
swapped = image.copy()
swapped[:h] = image[h:]
swapped[h:] = image[:h]
plt.imshow(swapped, cmap='gray')
plt.title('Top/Bottom Halves Swapped')
plt.show()
```



