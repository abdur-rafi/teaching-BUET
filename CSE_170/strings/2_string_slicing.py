
# Strings can be treated as a sequence of characters, similar to lists
my_string = "Hello, World!"

# Slicing a string (similar to slicing a list)
# A substring is a portion of a string.
# Extracting "Hello"
substring1 = my_string[:5]  # This takes characters from the start (index 0) to index 5 (exclusive).
print("Substring 1 (first 5 characters):", substring1)

# Extracting "World"
substring2 = my_string[7:12]  # This takes characters from index 7 to index 12 (exclusive).
print("Substring 2 (characters from index 7 to 11):", substring2)

# Extracting "Hello, World!" in reverse
reversed_string = my_string[::-1]  # This reverses the string by using a step of -1.
print("Reversed string:", reversed_string)
