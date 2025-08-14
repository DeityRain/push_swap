# Libft + ft_printf + get_next_line

This repository contains three core C projects developed as part of the 42 curriculum:

1. **Libft** – A custom C library implementing standard libc-like functions.
2. **ft_printf** – A reimplementation of the standard `printf` function with basic format specifiers.
3. **get_next_line** – A function to read a line from a file descriptor, handling memory management and buffering.

---

## 🛠 Compilation

To compile everything into a static library:

make

This will generate libft.a, which you can link to your projects:

gcc my_program.c -L. -lft

---

📜 Function List


1. Libft Functions

Function	Description

ft_isdigit	Checks if a character is a decimal digit.
ft_isalpha	Checks if a character is alphabetic.
ft_isalnum	Checks if a character is alphanumeric.
ft_isascii	Checks if a character is an ASCII character.
ft_isprint	Checks if a character is printable.
ft_strlen	Returns the length of a string.
ft_toupper	Converts a lowercase letter to uppercase.
ft_tolower	Converts an uppercase letter to lowercase.
ft_strncmp	Compares two strings up to n characters.
ft_memcmp	Compares two memory areas.
ft_atoi		Converts a string to an integer.
ft_memset	Fills memory with a constant byte.
ft_bzero	Sets memory to zero.
ft_memcpy	Copies memory area.
ft_memmove	Copies memory area with overlap handling.
ft_strlcpy	Copies a string to a buffer.
ft_strlcat	Appends a string to a buffer.
ft_strchr	Finds first occurrence of a character in a string.
ft_strrchr	Finds last occurrence of a character in a string.
ft_memchr	Finds a byte in a memory block.
ft_strnstr	Locates a substring in a string.
ft_strdup	Duplicates a string.
ft_calloc	Allocates and zeroes memory.
ft_substr	Extracts a substring from a string.
ft_strjoin	Concatenates two strings into a new string.
ft_strtrim	Trims characters from both ends of a string.
ft_split	Splits a string into an array of substrings.
ft_itoa		Converts an integer to a string.
ft_strmapi	Applies a function to each character of a string (returns a new string).
ft_striteri	Applies a function to each character of a string (in place).
ft_putnbr_fd	Outputs an integer to a file descriptor.
ft_putstr_fd	Outputs a string to a file descriptor.
ft_putchar_fd	Outputs a character to a file descriptor.
ft_putendl_fd	Outputs a string followed by a newline to a file descriptor.


2. ft_printf Functions

Function		Description

ft_printf		Main formatted output function (like printf).
ft_char_handler		Handles %c specifier.
ft_string_handler	Handles %s specifier.
ft_decimal_handler	Handles %d and %i specifiers.
ft_pourcent_handler	Handles %% specifier.
ft_uint_base10_handler	Handles %u specifier.
ft_hex_handler		Handles %x and %X specifiers.
ft_pointer_handler	Handles %p specifier.
ft_conv_handler		Dispatches to the correct handler based on format specifier.
ft_is_specificator	Checks if a character is a valid format specifier.


3. get_next_line Functions

Function	Description

get_next_line	Reads the next line from a file descriptor.

Constants:

    BUFFER_SIZE (default: 42) – Number of bytes read at a time.

    FD_MAX (default: 1024) – Maximum number of file descriptors supported.

---

📌 Usage Examples

Using libft:

#include "libft.h"

int main(void)
{
    char *str = "Hello";
    ft_putendl_fd(str, 1);
    return 0;
}


