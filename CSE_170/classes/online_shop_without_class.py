# product
# name, description, price, id

# customer
# name, number, address

# ShoppingCart
# products and their quantity

productNames = ['Laptop', 'Smartphone', 'Headphones', 'Smartwatch', 'Tablet']
productDescriptions = ['High-performance laptop', 'Latest model smartphone', 'Noise-cancelling headphones', 'Stylish smartwatch', 'Portable tablet']
productPrices = [1200, 800, 200, 300, 400]

customerNames = ['Alice', 'Bob', 'Charlie']
customerNumbers = ['123-456-7890', '987-654-3210', '555-555-5555']
customerAddresses = ['123 Main St', '456 Elm St', '789 Oak St']

shoppingCartOfCustomers = [
    [], [], []
]

def add_product_to_cart(customer_index, product_index, quantity):
    shoppingCartOfCustomers[customer_index].append((productNames[product_index], quantity))
    print("Product added to cart.")
