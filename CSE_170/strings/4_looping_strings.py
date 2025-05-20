# Example 1: Using a for loop to iterate through each character in a string
sample_string = "Hello, World!"
print("Characters in the string:")
for char in sample_string:
    print(char)


# Example 2: Using a while loop to iterate through a string
index = 0
print("Using while loop to iterate through the string:")
while index < len(sample_string):
    print(sample_string[index])
    index += 1

# Example 3: Counting occurrences of a character in a string using a loop
char_to_count = 'l'
count = 0
for char in sample_string:
    if char == char_to_count:
        count += 1
print(f"\nThe character '{char_to_count}' appears {count} times in the string.")