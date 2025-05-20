# Demonstrating basic operations on strings

# String concatenation
str1 = "Hello"
str2 = "World"
concatenated = str1 + " " + str2
print("Concatenated String:", concatenated)

# String repetition
repeated = str1 * 3
print("Repeated String:", repeated)

# Checking membership
is_present = "H" in str1
print("Is 'H' in str1?:", is_present)

not_present = "Z" not in str2
print("Is 'Z' not in str2?:", not_present)

# String length
length = len(str1)
print("Length of str1:", length)