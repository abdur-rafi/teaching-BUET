# Sample string
text = "  Hello, World! Welcome to Python Programming.  "

# strip() - Removes leading and trailing whitespaces
result_strip = text.strip()
print("strip():", result_strip)

# lstrip() - Removes leading whitespaces
result_lstrip = text.lstrip()
print("lstrip():", result_lstrip)

# rstrip() - Removes trailing whitespaces
result_rstrip = text.rstrip()
print("rstrip():", result_rstrip)

# lower() - Converts all characters to lowercase
result_lower = text.lower()
print("lower():", result_lower)

# upper() - Converts all characters to uppercase
result_upper = text.upper()
print("upper():", result_upper)

# title() - Converts the first character of each word to uppercase
result_title = text.title()
print("title():", result_title)

# split() - Splits the string into a list
result_split = text.split(sep=" ")
print("split():", result_split)

# join() - Joins elements of a list into a string
words = ["Python", "is", "fun"]
result_join = " ".join(words)
print("join():", result_join)

# replace() - Replaces a substring with another substring
result_replace = text.replace("World", "Universe")
print("replace():", result_replace)

# find() - Finds the first occurrence of a substring
result_find = text.find("Python")
print("find():", result_find)

# count() - Counts occurrences of a substring
result_count = text.count("o")
print("count():", result_count)

# startswith() - Checks if the string starts with a specific substring
result_startswith = text.startswith("  Hello")
print("startswith():", result_startswith)

# endswith() - Checks if the string ends with a specific substring
result_endswith = text.endswith("Programming.  ")
print("endswith():", result_endswith)

# isalpha() - Checks if all characters are alphabetic
result_isalpha = "Hello".isalpha()
print("isalpha():", result_isalpha)

# isdigit() - Checks if all characters are digits
result_isdigit = "12345".isdigit()
print("isdigit():", result_isdigit)
