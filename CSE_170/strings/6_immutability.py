# Demonstrating the immutability of strings in Python

# Initial string
original_string = "Hello, World!"

# Attempting to change a character in the string
# This will raise an error because strings are immutable
original_string[7] = 'w'

# Correct way to create a modified string
modified_string = original_string[:7] + 'w' + original_string[8:]
print("Original String:", original_string)
print("Modified String:", modified_string)