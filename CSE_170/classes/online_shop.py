# product
# name, description, price, id

# customer
# name, number, address

# ShoppingCart
# products and their quantity

class Product:
    def __init__(self, name, description, price, product_id):
        self.name = name
        self.description = description
        self.price = price
        self.product_id = product_id

    def print_info(self):
        print(f"Product ID: {self.product_id}")
        print(f"Name: {self.name}")
        print(f"Description: {self.description}")
        print(f"Price: ${self.price:.2f}")


class ShoppingCart:
    def __init__(self):
        self.items = []
    
    def add_item_to_cart(self, product, quantity):
        self.items.append([product, quantity])
    
    def remove_item_from_cart(self, product, quantity):
        new_items = []
        for cart_product, cart_product_quantity in self.items:
            if cart_product.product_id != product.product_id:
                new_items.append([cart_product, cart_product_quantity])
            else:
                if cart_product_quantity > quantity:
                    new_items.append([cart_product, cart_product_quantity - quantity])
                elif cart_product_quantity == quantity:
                    continue
                else:
                    print("Cannot remove more than available in the cart.")
        
        self.items = new_items
    
    def print_cart(self):
        for product, quantity in self.items:
            product.print_info()
            print(f"Quantity: {quantity}")
                


class Customer:
    def __init__(self, name, number, address, cart):
        self.name = name
        self.number = number
        self.address = address
        self.cart = cart

    def print_info(self):
        print(f"Name: {self.name}")
        print(f"Number: {self.number}")
        print(f"Address: {self.address}")

    def add_product(self, product, quantity):
        self.cart.add_item_to_cart(product, quantity)
        print(f"Added {quantity} of {product.name} to {self.name}'s cart.")
        # lskdsd
    
    def remove_product(self, product, quantity):
        self.cart.remove_item_from_cart(product, quantity);
        print(f"Removed {quantity} of {product.name} to {self.name}'s cart.")
        # askjdf





products = [
    Product('Laptop', 'High-performance laptop', 1200, 1),
    Product('Smartphone', 'Latest model smartphone', 800, 2),
    Product('Headphones', 'Noise-cancelling headphones', 200, 3),
    Product('Smartwatch', 'Stylish smartwatch', 300, 4),
    Product('Tablet', 'Portable tablet', 400, 5)
]

customers = [
    Customer("Alice", "123-456-7890", "123 Main St", ShoppingCart()),
    Customer("Bob", "987-654-3210", "456 Elm St", ShoppingCart()),
    Customer("Charlie", "555-555-5555", "789 Oak St", ShoppingCart())
]


customers[0].add_product(products[0], 1)

print("Printing cart information: ")
customers[0].cart.print_cart()

customers[2].add_product(products[1], 2)
customers[2].cart.print_cart()

