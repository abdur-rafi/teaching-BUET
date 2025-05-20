# Introduction to Strings in Python

# A string is a sequence of characters enclosed within single quotes (' ') or double quotes (" ").

# Example of strings
single_quoted = 'Hello, World!'
double_quoted = "Python is fun!"

# Strings can also include numbers, symbols, and spaces
mixed_string = "1234!@#$ Python 3.10"

# Multiline strings can be created using triple quotes
multiline_string = """This is a
multiline string
in Python."""


# Including special characters in strings
# How would you include a single quote in a string? or a double quote?
# You can escape quotes using the backslash (\) character
escaped_single_quote = 'It\'s a sunny day!'
escaped_double_quote = "He said, \"Python is awesome!\""

# but now, what if you want to include a backslash in your string?
# You can escape the backslash itself
escaped_backslash = "This is a backslash: \\"

# There are special characters in strings, that do some special things
# Some of them are : 
# \n - New line
# \t - Tab

# Example of using special characters
special_characters = "Hello,\n\tWorld!\nThis is a string with special characters."

# Why we need the special characters?
# For example, why we need to use \n?
# if we do not use it, how can we print the string in multiple lines?
# without using \n, we can use multiple print statements
print("Hello,")
print("World!")
print("This is a string with special characters.")
# But using \n, we can print the string in one line
print("Hello,\nWorld!\nThis is a string with special characters.")


# Whitespaces in Strings
# Whitespaces are characters that are used for spacing and do not display a visible mark.
# They include spaces, tabs, and newlines. These characters are called "whitespaces" because
# they create "empty" or "white" space in the text.

# Examples of whitespaces:
# 1. Space (' ')
# 2. Tab ('\t')
# 3. Newline ('\n')

# Why are they important?
# Whitespaces are essential for formatting and organizing text. They help in making the text
# more readable and structured.

# Example of using whitespaces:
whitespace_example = "This is a string with a space, a\ttab, and a\nnewline."

# Printing the example to observe the effect of whitespaces
print(whitespace_example)


