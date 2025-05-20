# Computers store data as binary (0s and 1s). To represent text, each character is assigned a unique number.
# This process is called character encoding. Unicode is a widely used standard for encoding characters.

# Example: Encoding and decoding characters using Unicode

# Get the Unicode code point of a character
char = 'A'
unicode_code = ord(char)  # ord() converts a character to its Unicode code point
print(f"The Unicode code point of '{char}' is: {unicode_code}")

# Convert the Unicode code point back to a character
decoded_char = chr(unicode_code)  # chr() converts a code point back to a character
print(f"The character for Unicode code point {unicode_code} is: '{decoded_char}'")

# Unicode allows representation of characters from various languages
char_emoji = '😊'
unicode_code_emoji = ord(char_emoji)
print(f"The Unicode code point of '{char_emoji}' is: {unicode_code_emoji}")
decoded_emoji = chr(unicode_code_emoji)
print(f"The character for Unicode code point {unicode_code_emoji} is: '{decoded_emoji}'")

# This encoding ensures that text can be stored, transmitted, and rendered consistently across systems.