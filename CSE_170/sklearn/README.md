# Lecture: Introduction to Scikit-learn – Linear Regression and Clustering

## 1. What is Scikit-learn?
- Scikit-learn (sklearn) is a popular Python library for machine learning.
- It provides simple tools for data analysis and modeling, including regression, classification, and clustering.
- Works well with NumPy and pandas.

## 2. Installing and Importing Scikit-learn
- Install with pip:
    ```bash
    pip install scikit-learn
    ```
- Import in Python:
    ```python
    import sklearn
    ```

---

## 3. Linear Regression

### What is Linear Regression?
- A method to model the relationship between one (or more) input variables (X) and an output variable (y).
- Example: Predicting house prices based on size.

### Steps in Scikit-learn
1. **Import the model:**
    ```python
    from sklearn.linear_model import LinearRegression
    ```
2. **Prepare data:**
    ```python
    # Example data: Predict y from X
    # X: hours studied, y: test score (with some variation)
    X = [[1], [2], [3], [4], [5]]
    y = [2, 5, 7, 9, 11]  # Added some variation to y values
    ```
3. **Create and train the model:**
    ```python
    model = LinearRegression()
    model.fit(X, y)
    ```
4. **Get model parameters:**
    ```python
    print('Slope (coefficient):', model.coef_)
    print('Intercept:', model.intercept_)
    ```

### Visualizing the Result
```python
import matplotlib.pyplot as plt
plt.scatter([x[0] for x in X], y, color='blue', label='Data')
plt.plot([x[0] for x in X], model.predict(X), color='red', label='Regression Line')
plt.xlabel('X')
plt.ylabel('y')
plt.legend()
plt.show()
```

---

## 4. Clustering (KMeans)

### What is Clustering?
- Clustering groups similar data points together.
- KMeans is a popular clustering algorithm that divides data into K groups.
- Example: Grouping customers by purchasing behavior.

### Steps in Scikit-learn
1. **Import the model:**
    ```python
    from sklearn.cluster import KMeans
    ```
2. **Prepare data:**
    ```python
    # Example data: 2D points
    X = [[1, 2], [1, 4], [1, 0], [10, 2], [10, 4], [10, 0]]
    
    # Visualize the data before clustering
    import matplotlib.pyplot as plt
    X_np = np.array(X)
    plt.scatter(X_np[:, 0], X_np[:, 1], color='blue', label='Data Points')
    plt.xlabel('X1')
    plt.ylabel('X2')
    plt.title('Data Before Clustering')
    plt.legend()
    plt.show()
    ```
3. **Create and fit the model:**
    ```python
    kmeans = KMeans(n_clusters=2, random_state=0)
    kmeans.fit(X)
    ```
4. **Get cluster labels and centers:**
    ```python
    print('Cluster labels:', kmeans.labels_)
    print('Cluster centers:', kmeans.cluster_centers_)
    ```

### Visualizing Clusters
```python
import numpy as np
import matplotlib.pyplot as plt
X_np = np.array(X)
plt.scatter(X_np[:, 0], X_np[:, 1], c=kmeans.labels_, cmap='viridis', label='Points')
plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], s=200, c='red', marker='X', label='Centers')
plt.xlabel('X1')
plt.ylabel('X2')
plt.legend()
plt.show()
```

---
