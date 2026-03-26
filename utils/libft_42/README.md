*This project has been created as part of the 42 curriculum by traomeli.*

# Libft

## Description

**Libft** is a custom C library developed as part of the 42 curriculum.
The goal of this project is to recreate a set of standard C library functions,
as well as additional utility functions, in order to strengthen fundamental programming skills such as memory management,
pointer manipulation, and modular code design.
This library serves as a foundation for many future projects at 42 and is intended to be reused throughout the curriculum.

## Instructions

### Compilation

This will generate the static library file:

```bash
make libft.a
```

### Makefile Rules

```bash
make
make clean
make fclean
make re
```

### Usage

```c
#include "libft.h"
```

```bash
cc your_file.c libft.a
```

## Library Content

### Linked List Structure

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
```

## Functions Overview

### Character & Type Checking

| Function   | Return Type | Description                                   |
| ---------- | ----------- | --------------------------------------------- |
| ft_isalpha | int         | Checks if the character is alphabetic         |
| ft_isdigit | int         | Checks if the character is a digit            |
| ft_isalnum | int         | Checks if the character is alphanumeric       |
| ft_isascii | int         | Checks if the character is an ASCII character |
| ft_isprint | int         | Checks if the character is printable          |
| ft_toupper | int         | Converts a character to uppercase             |
| ft_tolower | int         | Converts a character to lowercase             |

### Memory Manipulation

| Function   | Return Type | Description                       |
| ---------- | ----------- | --------------------------------- |
| ft_memset  | void *      | Fills memory with a constant byte |
| ft_bzero   | void        | Sets memory to zero               |
| ft_memcpy  | void *      | Copies memory area                |
| ft_memmove | void *      | Copies memory area safely         |
| ft_memchr  | void *      | Searches for a byte in memory     |
| ft_memcmp  | int         | Compares memory areas             |
| ft_calloc  | void *      | Allocates and zeroes memory       |

### String Manipulation

| Function    | Return Type | Description                                       |
| ----------- | ----------- | ------------------------------------------------- |
| ft_strlen   | size_t      | Returns the length of a string                    |
| ft_strdup   | char *      | Duplicates a string                               |
| ft_strchr   | char *      | Locates a character in a string                   |
| ft_strrchr  | char *      | Locates a character in a string (last occurrence) |
| ft_strncmp  | int         | Compares two strings                              |
| ft_strnstr  | char *      | Locates a substring                               |
| ft_strlcpy  | size_t      | Copies string with size limit                     |
| ft_strlcat  | size_t      | Concatenates string with size limit               |
| ft_substr   | char *      | Extracts a substring                              |
| ft_strtrim  | char *      | Trims characters from a string                    |
| ft_split    | char **     | Splits a string into an array                     |
| ft_strmapi  | char *      | Applies a function to each character              |
| ft_striteri | void        | Applies a function to each character by reference |
| ft_itoa     | char *      | Converts an integer to a string                   |

### Conversion

| Function | Return Type | Description                     |
| -------- | ----------- | ------------------------------- |
| ft_atoi  | int         | Converts a string to an integer |

### File Descriptor Output

| Function      | Return Type | Description                              |
| ------------- | ----------- | ---------------------------------------- |
| ft_putchar_fd | void        | Outputs a character to a file descriptor |
| ft_putstr_fd  | void        | Outputs a string to a file descriptor    |
| ft_putendl_fd | void        | Outputs a string followed by a newline   |
| ft_putnbr_fd  | void        | Outputs an integer                       |

## Resources

* GNU C Library Documentation
* man pages
* 42 subject PDF and evaluation guidelines

### Use of AI

AI tools were used for concept clarification, code review, debugging assistance, and README documentation guidance. All implementation and final code decisions were made by the student.
