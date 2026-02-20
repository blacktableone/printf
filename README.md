*This project has been created as part of the 42 curriculum by nisu.*

# ft_printf

## Description
Discover a popular and versatile C function: `ft_printf`. The goal of this project is to understand how variadic functions work in C — functions that can accept a variable number of arguments — by building `printf` from scratch.

The library handles the following format specifiers:

| Specifier | Output |
|-----------|--------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address in hexadecimal |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Literal percent sign |

## Instructions
The implementation is split across three `.c` files and one header for clarity:

**`ft_printf.c`** — The core entry point. It loops through the format string character by character. When it encounters a `%` followed by another character, it delegates to `ft_handle_format()` which uses a chain of `if/else if` conditions to call the right output helper based on the specifier. The function accumulates a `count` of bytes written and returns it at the end, mimicking the return value of the real `printf`.

**`ft_printf_helper1.c`** — Contains three low-level output helpers:
- `ft_putchar`: Writes a single character using `write()`.
- `ft_putstr`: Iterates through a string and calls `ft_putchar` on each character. Handles `NULL` by printing `(null)`.
- `ft_putnbr`: Prints a signed integer recursively. Handles the edge case of `INT_MIN` (`-2147483648`) separately because negating it would cause an integer overflow.

**`ft_printf_helper2.c`** — Contains three more helpers for less common types:
- `ft_puthex`: Recursively converts a number to hexadecimal using a string as a lookup table (`"0123456789abcdef"` or the uppercase version). The recursive approach naturally prints digits from most significant to least significant.
- `ft_putptr`: Prepends `"0x"` then calls `ft_puthex` to print a pointer's address.
- `ft_putnbr_unsigned`: Like `ft_putnbr` but without negative number handling.

## Resources
- [A general gitbook by Laura & Simon, from Switzerland (42 Lausanne)](https://42-cursus.gitbook.io/guide)
### AI Usage
Claude (claude.ai) was used to:
- Generate this `README.md` based on the project's source code and the 42 README requirements.
- Explain the concept of va_list, va_start, va_end & va_arg
