## Lab Assignment: Getting Organized with Classes and Objects in Python

**Learning Objectives:**
By the end of this lab, you will be able to:
* Understand why classes are a powerful way to organize data and functions.
* Differentiate between a **class** (blueprint) and an **object** (instance).
* Create simple classes with attributes and methods.
* Understand the basic role of `self` in class methods.
* Appreciate the benefits of using classes for managing multiple related pieces of information, especially through a practical comparison.

---

### Preliminary Section: A Quick Review of Functions

**Introduction:**
Before we explore new ways of organizing code with classes, let's quickly review a concept you're already familiar with: **functions**. Functions are fundamental building blocks in Python that allow you to group related statements into a single reusable unit. They help make your code more organized, readable, and prevent repetition.

**Activity P.1: Understanding Functions**

1.  **Defining and Calling a Simple Function:**
    Recall how you define a function using the `def` keyword, give it a name, and potentially include parameters.
    ```python
    def greet_user(name):
        """This function takes a name and prints a greeting."""
        message = f"Hello, {name}! Welcome to the system."
        print(message)

    # Calling the function
    greet_user("Alice")
    greet_user("Bob")
    ```
    * **Question P.1.1:** What is the purpose of the `name` inside the parentheses in `def greet_user(name):`? What do we call `name` in this context?

2.  **Functions with Return Values:**
    Functions can also perform calculations or operations and then give a result back using the `return` keyword.

    ```python
    def calculate_area_rectangle(length, width):
        """This function calculates the area of a rectangle."""
        area = length * width
        return area

    # Calling the function and storing its returned value
    room_area = calculate_area_rectangle(5, 8)
    print(f"The area of the room is: {room_area} square units.")

    desk_area = calculate_area_rectangle(1.5, 0.8)
    print(f"The area of the desk is: {desk_area} square units.")
    ```
    * **Question P.1.2:** When we call `calculate_area_rectangle(5, 8)`, what are `5` and `8` called?
    * **Question P.1.3:** What does the `return area` statement do? Why is it useful to have functions return values?

**Your Understanding:**
You've just refreshed your memory on how functions allow you to define a block of code once and reuse it multiple times. You pass information *into* functions via **arguments** (which correspond to **parameters** in the function definition), and functions can give results *back* using `return`.

---

**Answers for Preliminary Section:**

**Question P.1.1:** What is the purpose of the `name` inside the parentheses in `def greet_user(name):`? What do we call `name` in this context?
* **Answer:** `name` is a **parameter**. Its purpose is to act as a placeholder for the data that will be passed into the function when it's called. The function uses this `name` to perform its operation (in this case, constructing a greeting message).

**Question P.1.2:** When we call `calculate_area_rectangle(5, 8)`, what are `5` and `8` called?
* **Answer:** `5` and `8` are called **arguments**. They are the actual values that are supplied to the function's parameters (`length` and `width`) when the function is executed.

**Question P.1.3:** What does the `return area` statement do? Why is it useful to have functions return values?
* **Answer:** The `return area` statement sends the calculated `area` value back to the place where the function was called. It's useful because it allows functions to produce a result that can then be used in other parts of your program (e.g., stored in a variable, printed, or used in further calculations), rather than just performing an action and ending. This makes functions versatile tools for processing data.

---

### Part 1: Functions vs. "Built-in Object Methods"

**Introduction:**
You've been using Python for a while now, and you've worked with various data types like numbers, strings, lists, and sets. You've also written your own functions. Today, we're going to bridge a gap between what you've done and a new powerful concept.

**Activity 1.1: Observing List, String & Set Operations**

1.  **Recall List Methods:**
    * Think about how you've added items to a list, or removed them.
    * Look at this code:
        ```python
        my_shopping_list = ["milk", "eggs", "bread"]
        my_shopping_list.append("cheese") # How does 'append' work?
        my_shopping_list.remove("eggs")  # How does 'remove' work?
        print(my_shopping_list)

        another_list = [10, 20, 30]
        another_list.clear() # How does 'clear' work?
        print(another_list)
        ```
    * **Question 1.1.1:** When you used `.append()` or `.remove()` on `my_shopping_list`, did you pass the list itself as an argument to these functions (like `append(my_shopping_list, "cheese")`)? Or did you call them directly "on" the list?
    * **Question 1.1.2:** How is this different from a user-defined function you've written, like `def calculate_sum(num1, num2):` where you pass `num1` and `num2` *into* the function?

2.  **Recall String Methods:**
    * Consider how you've manipulated text.
    * Look at this code:
        ```python
        my_greeting = "hello world"
        capitalized_greeting = my_greeting.capitalize() # How does 'capitalize' work?
        print(capitalized_greeting)

        my_name = "Alice"
        is_alpha = my_name.isalpha() # How does 'isalpha' work?
        print(is_alpha)
        ```
    * **Question 1.1.3:** Similar to lists, how do you call `capitalize()` or `isalpha()`? Are you passing the string *into* a separate function?

3.  **Recall Set Methods:**
    * Remember how sets are used for unique collections and operations like adding or removing elements.
    * Look at this code, paying attention to how the sets are created:
        ```python
        my_favorite_colors = set(["red", "blue", "green"]) # Using set() constructor
        my_favorite_colors.add("yellow") # How does 'add' work?
        my_favorite_colors.discard("blue") # How does 'discard' work?
        print(my_favorite_colors)

        all_colors = set(["red", "blue", "green", "yellow", "purple"]) # Using set() constructor
        new_colors = set(["orange", "cyan"]) # Using set() constructor
        union_set = all_colors.union(new_colors) # How does 'union' work?
        print(union_set)
        ```
    * **Question 1.1.4:** How do you call `add()`, `discard()`, or `union()`? Are you passing the set *into* a separate function?
    * **Question 1.1.5:** What do you notice about the way `append`, `remove`, `capitalize`, `isalpha`, `add`, `discard`, and `union` are used compared to your typical user-defined functions? (Hint: Think about what they operate *on*.)

**Your Observation:**
You've observed that these are special types of functions (we call them **methods**) that "belong" to the data they operate on (like a list, a string, or a set). They are called using the `.` (dot) notation: `data.method()`. This concept of bundling data and functions together is a core idea in today's topic!

---

**Answers for Part 1:**

**Question 1.1.1:** When you used `.append()` or `.remove()` on `my_shopping_list`, did you pass the list itself as an argument to these functions (like `append(my_shopping_list, "cheese")`)? Or did you call them directly "on" the list?
* **Answer:** We called them directly "on" the list using the **dot notation** (`.append()`, `.remove()`). We didn't pass `my_shopping_list` as an explicit argument.

**Question 1.1.2:** How is this different from a user-defined function you've written, like `def calculate_sum(num1, num2):` where you pass `num1` and `num2` *into* the function?
* **Answer:** With user-defined functions like `calculate_sum(num1, num2)`, you explicitly provide all the data (arguments) that the function needs to operate on. The list and string methods, however, seem to already "know" which list or string they are supposed to work with because they are called *on* that specific list or string.

**Question 1.1.3:** Similar to lists, how do you call `capitalize()` or `isalpha()`? Are you passing the string *into* a separate function?
* **Answer:** No, similar to lists, we call them directly "on" the string using the dot notation (`.capitalize()`, `.isalpha()`). We don't pass the string as a separate argument.

**Question 1.1.4:** How do you call `add()`, `discard()`, or `union()`? Are you passing the set *into* a separate function?
* **Answer:** Similar to lists and strings, we call these methods directly "on" the set using the dot notation (`.add()`, `.discard()`, `.union()`). We don't pass the set itself as a separate argument.

**Question 1.1.5:** What do you notice about the way `append`, `remove`, `capitalize`, `isalpha`, `add`, `discard`, and `union` are used compared to your typical user-defined functions? (Hint: Think about what they operate *on*.)
* **Answer:** The main difference is that these methods are called *on* a **specific piece of data** (a list, a string, a set). They seem to be "attached" to that data and operate directly on it. Our typical user-defined functions, on the other hand, usually take the data as arguments. This suggests that these methods are a way to **bundle operations directly with the data they affect**.

---

### Part 2: Grouping Data & Functions with Classes - The Blueprint

**Introduction:**
Imagine you're building a system for your university. You have many students, and each student has a name, ID, major, and maybe a GPA. Also, you want to be able to enroll them in courses or display their information.

**Activity 2.1: Our First Class - The `Student` Blueprint**

* A **class** is like a blueprint or a template. It describes what a "Student" *is* (what data it has) and what a "Student" *can do* (what actions it can perform).
* It's not an actual student, but the *definition* of what all students will be like.

1.  **Define the `Student` Class:**
    In your Python environment, type out and run the following code:
    ```python
    class Student:
        # The __init__ method is special: it runs automatically when you create a new Student
        def __init__(self, name, student_id, major):
            self.name = name          # Each student will have a name
            self.student_id = student_id  # Each student will have an ID
            self.major = major        # Each student will have a major
            self.courses_enrolled = [] # Start with no courses enrolled

        # This is a method (a function that belongs to a Student)
        def enroll_course(self, course_name):
            self.courses_enrolled.append(course_name)
            print(f"{self.name} enrolled in {course_name}.")

        # Another method to display student information
        def display_info(self):
            print(f"\n--- Student Info ---")
            print(f"Name: {self.name}")
            print(f"ID: {self.student_id}")
            print(f"Major: {self.major}")
            print(f"Courses: {', '.join(self.courses_enrolled) if self.courses_enrolled else 'None'}")
            print(f"--------------------")
    ```
    * **Question 2.1.1:** Look at the `__init__` method. What do you think the purpose of the `self` parameter is? (Don't worry about perfect technical terms, just your guess.)
    * **Question 2.1.2:** What about `self.name = name`? What's the difference between `self.name` and just `name` here?

2.  **Creating "Actual" Students (Objects/Instances):**
    The class is just a blueprint. To get an actual student, we create an **object** (also called an **instance**) from that blueprint.

    Add these lines below your `Student` class definition and run the script:
    ```python
    # Creating individual student objects from the Student blueprint
    student1 = Student("Rahim Ahmed", "2023-001", "Computer Science")
    student2 = Student("Nadia Begum", "2023-002", "Business Administration")

    # Using the methods that belong to these student objects
    student1.enroll_course("Introduction to Programming")
    student1.enroll_course("Calculus I")
    student2.enroll_course("Principles of Marketing")

    # Displaying information for each student
    student1.display_info()
    student2.display_info()
    ```
    * **Question 2.2.1:** What is `student1` in this code? Is it a class or an object?
    * **Question 2.2.2:** What happens if you try to access `Student.name` directly (e.g., `print(Student.name)`)? Why do you think this is the case?
    * **Question 2.2.3:** How did `student1.display_info()` know to print Rahim Ahmed's details, and `student2.display_info()` know to print Nadia Begum's details? What role do you think `self` played?

**Your Understanding:**
You've now created your first class and objects! You've seen that:
* A **class** is a blueprint (like `Student`).
* An **object** is a specific item created from that blueprint (like `student1` or `student2`).
* The `__init__` method helps set up the initial characteristics (**attributes**) of an object when it's created.
* **Methods** (like `enroll_course` and `display_info`) are functions that belong to the objects created from the class, and they use `self` to refer to the specific object they are acting upon.

---

**Answers for Part 2:**

**Question 2.1.1:** Look at the `__init__` method. What do you think the purpose of the `self` parameter is? (Don't worry about perfect technical terms, just your guess.)
* **Answer:** `self` seems to represent the specific student object that is being created or is performing an action. It's like a placeholder for "**this particular student**" or "**this instance**."

**Question 2.1.2:** What about `self.name = name`? What's the difference between `self.name` and just `name` here?
* **Answer:** `name` (without `self.`) is the value that is passed into the `__init__` method when we create a new `Student` (e.g., "Rahim Ahmed"). `self.name` is where that value gets *stored* **within the `student` object itself**. So, `self.name` becomes an "attribute" of that specific student object.

**Question 2.2.1:** What is `student1` in this code? Is it a class or an object?
* **Answer:** `student1` is an **object** (or instance) of the `Student` class.

**Question 2.2.2:** What happens if you try to access `Student.name` directly (e.g., `print(Student.name)`)? Why do you think this is the case?
* **Answer:** It would cause an error (an `AttributeError`). `Student` is the blueprint; it doesn't have a specific `name` itself. Only individual *objects* created from the `Student` blueprint, like `student1` or `student2`, have their own `name`.

**Question 2.2.3:** How did `student1.display_info()` know to print Rahim Ahmed's details, and `student2.display_info()` know to print Nadia Begum's details? What role do you think `self` played?
* **Answer:** When `student1.display_info()` is called, Python automatically passes `student1` as the `self` argument to the `display_info` method. So, inside `display_info`, `self.name` refers to `student1.name` (Rahim Ahmed). When `student2.display_info()` is called, `self` becomes `student2`, and `self.name` refers to `student2.name` (Nadia Begum). `self` makes sure the method operates on the correct, specific object's data.

---

### Part 3: The Power of Organization - A Comparison

**Introduction:**
Let's consider a simple scenario: an online store where customers can add products to a shopping cart. We'll first try to manage this *without* classes, and then *with* classes, to clearly see the benefits.

**Scenario:** We need to keep track of:
* Different **Products**: each has a name and a price.
* A **Shopping Cart**: which contains various products and their quantities.
* A **Customer**: who owns a shopping cart.

**Activity 3.1: Building the E-commerce System WITHOUT Classes**

In a new Python file or cell, try to implement this system using only variables, lists, dictionaries, and functions (no classes!).

```python
# --- Our "Global" Store Inventory (without classes) ---
# Each product is a dictionary
products_inventory = {
    "P001": {"name": "Gaming Laptop", "price": 85000.00},
    "P002": {"name": "27-inch Monitor", "price": 18000.00},
    "P003": {"name": "Mechanical Keyboard", "price": 5500.00},
    "P004": {"name": "Wireless Mouse", "price": 1200.00},
}

# --- Customer Data (without classes) ---
# A dictionary to store customer carts. Key: customer_id, Value: list of (product_id, quantity) tuples
customer_carts = {} # e.g., {"C001": [("P001", 1), ("P002", 2)]}

# --- Functions to manage the system (without classes) ---

def display_all_products():
    print("\n--- Available Products (No Classes) ---")
    for prod_id, details in products_inventory.items():
        print(f"ID: {prod_id}, Name: {details['name']}, Price: BDT {details['price']:.2f}")
    print("---------------------------------------")

def add_to_cart(customer_id, product_id, quantity):
    if product_id not in products_inventory:
        print(f"Error: Product ID {product_id} not found.")
        return False

    product_info = products_inventory[product_id]

    # Add to customer's cart
    if customer_id not in customer_carts:
        customer_carts[customer_id] = []
    
    # Simply append the item to the cart, even if it's a duplicate product
    customer_carts[customer_id].append((product_id, quantity))

    print(f"Added {quantity} x {product_info['name']} to cart for {customer_id}.")
    return True

def display_cart(customer_id):
    print(f"\n--- Shopping Cart for {customer_id} (No Classes) ---")
    if customer_id not in customer_carts or not customer_carts[customer_id]:
        print("Cart is empty.")
        return

    total_value = 0
    for prod_id, quantity in customer_carts[customer_id]:
        product_info = products_inventory[prod_id]
        item_price = product_info["price"] * quantity
        total_value += item_price
        print(f"  {product_info['name']} (ID: {prod_id}) x {quantity} = BDT {item_price:.2f}")
    print(f"Total Cart Value: BDT {total_value:.2f}")
    print("---------------------------------------------")

# --- Run a simple scenario (without classes) ---
print("--- Scenario WITHOUT Classes ---")
display_all_products()

add_to_cart("C001", "P001", 1) # Ali buys 1 Laptop
add_to_cart("C001", "P002", 2) # Ali buys 2 Monitors
add_to_cart("C001", "P001", 1) # Ali buys another Laptop - this will now be a separate entry
add_to_cart("C002", "P004", 3) # Bithi buys 3 Mice

display_cart("C001")
display_cart("C002")

print("\n--- All Carts after shopping (No Classes) ---")
print(customer_carts)
print("--------------------------------------------------")
```

* **Question 3.1.1:** How is information about a product (like its name and price) stored in this scenario?
* **Question 3.1.2:** Imagine you have 100 products and 50 customers. How easy or difficult do you think it would be to manage `products_inventory` and `customer_carts`? Why?
* **Question 3.1.3:** If you wanted to add a "discount" feature where each product could have a different discount percentage, how would you add that information to `products_inventory`? And how would you update the `add_to_cart` and `display_cart` functions to use it?

**Activity 3.2: Building the E-commerce System WITH Classes**

Now, let's redesign the same system using classes. This time, we'll have:
* A `Product` class for each item.
* A `ShoppingCart` class that a customer "has".
* A `Customer` class for each shopper.

```python
# --- E-commerce System WITH Classes ---

class Product:
    def __init__(self, product_id, name, price):
        self.product_id = product_id
        self.name = name
        self.price = price
        print(f"Product '{self.name}' created.")

    def display_product_info(self):
        print(f"  ID: {self.product_id}, Name: {self.name}, Price: BDT {self.price:.2f}")


class ShoppingCart:
    def __init__(self):
        self.items = [] # This list will now hold tuples: (Product_object, quantity)

    def add_item(self, product_obj, quantity):
        if quantity <= 0:
            print("  Quantity must be positive.")
            return

        # Simply append the product object and its quantity as a tuple
        self.items.append((product_obj, quantity))
        
        print(f"  Added {quantity} x {product_obj.name} to cart.")


    def remove_item(self, product_obj_to_remove, quantity_to_remove):
        if quantity_to_remove <= 0:
            print("  Quantity to remove must be positive.")
            return

        item_removed = False
        # Create a new list for items that remain after removal
        new_items_list = [] 
        
        # We need a flag to ensure we only remove/adjust one matching entry per call for simplicity
        found_and_handled = False 

        for product_in_cart, quantity_in_cart in self.items:
            if not found_and_handled and product_in_cart.product_id == product_obj_to_remove.product_id:
                if quantity_in_cart <= quantity_to_remove:
                    # If current quantity is less than or equal to quantity to remove, just skip this item (effectively remove all)
                    print(f"  Removed all {quantity_in_cart} x {product_obj_to_remove.name} from cart.")
                else:
                    # Reduce quantity and add the updated item to the new list
                    new_items_list.append((product_in_cart, quantity_in_cart - quantity_to_remove))
                    print(f"  Removed {quantity_to_remove} x {product_obj_to_remove.name} from cart. {quantity_in_cart - quantity_to_remove} remaining.")
                found_and_handled = True # Mark as handled for this call
                item_removed = True
            else:
                # Keep other items as they are
                new_items_list.append((product_in_cart, quantity_in_cart))

        self.items = new_items_list # Update the cart's items list

        if not item_removed:
            print(f"  '{product_obj_to_remove.name}' not found in cart or no matching quantity to remove.")


    def get_total_price(self):
        total = 0
        for product_obj, quantity in self.items: # Unpack the tuple
            total += product_obj.price * quantity
        return total

    def display_cart(self):
        print("\n--- Shopping Cart Contents ---")
        if not self.items:
            print("  Cart is empty.")
            return
        for product_obj, quantity in self.items: # Unpack the tuple
            print(f"  {product_obj.name} (ID: {product_obj.product_id}) x {quantity} = BDT {product_obj.price * quantity:.2f}")
        print(f"  Total Cart Value: BDT {self.get_total_price():.2f}")
        print("------------------------------")


class Customer:
    def __init__(self, customer_id, name):
        self.customer_id = customer_id
        self.name = name
        self.shopping_cart = ShoppingCart() # Each customer gets their own ShoppingCart object
        print(f"\nCustomer '{self.name}' created.")

    def add_to_cart(self, product_obj, quantity):
        print(f"{self.name} is adding to cart:")
        self.shopping_cart.add_item(product_obj, quantity)

    def remove_from_cart(self, product_obj, quantity):
        print(f"{self.name} is removing from cart:")
        self.shopping_cart.remove_item(product_obj, quantity)

    def view_my_cart(self):
        self.shopping_cart.display_cart()

    def checkout(self):
        total = self.shopping_cart.get_total_price()
        if total > 0:
            print(f"\n--- {self.name} Checking Out ---")
            print(f"  Final Cart Total: BDT {total:.2f}")
            print("  Payment processed successfully! Your items are on their way.")
            self.shopping_cart.items = [] # Clear the cart after checkout
            print("  Cart cleared.")
            print("------------------------------")
        else:
            print(f"\n{self.name}'s cart is empty. Nothing to checkout.")


# --- Run a simple scenario (WITH Classes) ---
print("\n--- Scenario WITH Classes ---")

# 1. Create some products (objects of the Product class)
store_laptop = Product("P001", "Gaming Laptop", 85000.00)
store_monitor = Product("P002", "27-inch Monitor", 18000.00)
store_keyboard = Product("P003", "Mechanical Keyboard", 5500.00)
store_mouse = Product("P004", "Wireless Mouse", 1200.00)

print("\n--- All Products in the Store ---")
store_laptop.display_product_info()
store_monitor.display_product_info()
store_keyboard.display_product_info()
store_mouse.display_product_info()
print("---------------------------------")


# 2. Create a customer (an object of the Customer class)
customer_ali = Customer("C001", "Ali Hossain")

# 3. Customer Ali interacts with their cart
customer_ali.add_to_cart(store_laptop, 1)
customer_ali.add_to_cart(store_monitor, 2)
customer_ali.add_to_cart(store_keyboard, 1)
customer_ali.add_to_cart(store_laptop, 1) # This will now add a second (laptop, 1) entry

# Ali views their cart
customer_ali.view_my_cart()

# Ali removes an item
customer_ali.remove_from_cart(store_monitor, 1)

# Ali views cart again
customer_ali.view_my_cart()

# Another customer
customer_bithi = Customer("C002", "Bithi Akter")
customer_bithi.add_to_cart(store_mouse, 5)
customer_bithi.add_to_cart(store_laptop, 1)
customer_bithi.view_my_cart()

# Ali checks out
customer_ali.checkout()

# Bithi checks out
customer_bithi.checkout()

print("\n--- Scenario Complete ---\n")
```

---

**Activity 3.3: Comparing the Approaches**

After running both the "Without Classes" and "With Classes" scenarios, consider the following questions:

* **Question 3.3.1 (Organization):**
    * In the "Without Classes" scenario, how is information about a product (like its name and price) stored? Where is the list of items in a customer's cart stored?
    * In the "With Classes" scenario, where are the `name` and `price` for a `Product`? What kind of data structure does `ShoppingCart`'s `items` list now hold, and what does each element of that structure contain?
    * Which approach do you think keeps related information together more clearly? Why?

* **Question 3.3.2 (Action & Data):**
    * In the "Without Classes" scenario, the `add_to_cart` function directly modifies the `customer_carts` dictionary. If you wanted to ensure product names were always capitalized when displayed, where would you put that logic?
    * In the "With Classes" scenario, if you wanted to ensure product names were always capitalized when displayed via `display_product_info()`, where would you implement that?
    * Which approach seems to make it easier to link behavior directly to the data it acts upon?

* **Question 3.3.3 (Scalability / Multiple Customers):**
    * Imagine you need to support 10 different customers shopping simultaneously. In the "Without Classes" scenario, how would you manage each customer's separate cart?
    * In the "With Classes" scenario, how do you handle multiple customers? What happens when you create `customer_ali` and `customer_bithi`?
    * Which approach seems more scalable (easier to handle many similar items/users)?

* **Question 3.3.4 (Readability & Understanding):**
    * Look at the `add_to_cart` function versus the `Customer.add_to_cart()` and `ShoppingCart.add_item()` methods. Which code is easier to read and understand what's happening at a glance?
    * When you see `customer_ali.add_to_cart(store_laptop, 1)`, what does that line of code intuitively tell you?

* **Question 3.3.5 (Your Conclusion):**
    Based on this comparison, explain in your own words why **classes and objects are helpful for organizing code, especially when you have multiple similar "things" (like products, customers, or carts) that have their own data and actions.**

---

**Answers for Part 3:**

**Question 3.3.1 (Organization):**
* **Without Classes:** Product information (name, price) is stored in the `products_inventory` dictionary. Each customer's cart is stored in the `customer_carts` dictionary. These are separate, global data structures.
* **With Classes:** The `name` and `price` are **attributes** *inside* each `Product` object. The `ShoppingCart`'s `items` list now holds **tuples**, where each tuple contains a **`Product` object** (representing the specific item bought) and its **`quantity`**.
* **Which approach is clearer?** The "With Classes" approach is much clearer. All the data that belongs to a specific "thing" (like a product, or an item in a cart, or a customer) is **bundled together *inside* that thing's object**. This makes it easier to see what information belongs to what.

**Question 3.3.2 (Action & Data):**
* **Without Classes:** If you wanted to ensure product names were always capitalized when displayed, you would need to add that capitalization logic inside the `display_all_products` function and potentially anywhere else a product name is printed (e.g., in `display_cart`).
* **With Classes:** If you wanted to ensure product names were always capitalized when displayed via `display_product_info()`, you would implement that logic directly within the `display_product_info` method of the `Product` class itself (e.g., `print(f"Name: {self.name.capitalize()}")`).
* **Which approach seems to make it easier to link behavior directly to the data it acts upon?** The "With Classes" approach. The `Product` object itself is responsible for knowing how to display its own information, including how its name should be formatted. This keeps related data and behavior together.

**Question 3.3.3 (Scalability / Multiple Customers):**
* **Without Classes:** To support 10 different customers, you would need to add new entries to `customer_carts` for each customer (e.g., `"C003": [], "C004": []`, etc.). You'd manage each cart by its customer ID within that one large dictionary.
* **With Classes:** When you need a new customer, you simply create a new `Customer` object (e.g., `customer_bithi = Customer("C002", "Bithi Akter")`). Each new customer automatically gets their own independent `ShoppingCart` object inside them, and that shopping cart manages its own list of `(product_obj, quantity)` tuples. You don't need to manually manage separate cart variables or entries in a global dictionary for each customer.
* **Which approach is more scalable?** The "With Classes" approach is much more scalable. You can create as many independent `Product`, `ShoppingCart`, and `Customer` objects as you need, and each one manages its own data and behavior without interfering with others, even though they can interact.

**Question 3.3.4 (Readability & Understanding):**
* **Without Classes:** The `add_to_cart` function can become quite long and complex, handling multiple pieces of data (products and customer carts) and various checks. It operates on global data structures.
* **With Classes:** When you see `customer_ali.add_to_cart(store_laptop, 1)`, it intuitively tells you that "the customer Ali is performing an action (adding something to their cart), and they are adding the specific product 'store_laptop' with a quantity of 1." The actions (`add_to_cart`, `remove_from_cart`, `checkout`) are clearly linked to the object that performs them (`customer_ali`).
* **Which code is easier to read?** The "With Classes" code is generally easier to read and understand because it models the real world more closely. Objects perform actions, and those actions are clearly associated with the objects themselves.

**Question 3.3.5 (Your Conclusion):**
* **Answer:** Classes and objects are extremely helpful for organizing code because they allow us to bundle **related data (attributes) and the actions that operate on that data (methods) into self-contained units**. Instead of having separate lists and dictionaries scattered around that functions then manipulate, a class lets us define a "thing" (like a Product, a Shopping Cart, or a Customer) that manages its *own* information and *own* behavior.
    * This makes the code much clearer and easier to understand, as it directly reflects how we think about real-world entities.
    * It also makes the code easier to manage when you have many of the same "things" (multiple products, multiple customers, multiple carts), because each object is independent and handles its own details.
    * Changes or additions to how a "thing" behaves can be made in just one place (its class definition), making the code more robust and easier to maintain.