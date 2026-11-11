*This project has been created as part of the 42 curriculum by Kisella.*

# 🌙 ft_printf

## 📝 Description

ft_printf is an individual project from the 42 school curriculum. The goal is to recreate the standard C `printf()` function by implementing a custom version called `ft_printf()`.

This project introduces variadic functions in C and develops a better understanding of formatted output, argument handling, conversions and data representation.

The implementation reproduces the behavior of the original `printf()` without implementing its buffer management. Like the original, `ft_printf()` returns the number of characters printed, or `-1` if an error occurs.

The bonus part (flags `-0.# +` and field width) is not implemented.

## 🔹 Conversions

**🔠 Character and string**
- `%c` — Prints a single character.
- `%s` — Prints a string (`(null)` if the pointer is `NULL`).

**📍 Pointers**
- `%p` — Prints a pointer address in hexadecimal, prefixed with `0x` (`(nil)` for a `NULL` pointer).

**🔢 Numbers**
- `%d` — Prints a decimal number.
- `%i` — Prints an integer in base 10.
- `%u` — Prints an unsigned decimal number.

**💻 Hexadecimal**
- `%x` — Prints a hexadecimal number in lowercase.
- `%X` — Prints a hexadecimal number in uppercase.

**✨ Special**
- `%%` — Prints a percent sign.

## ⚙️ Instructions

### 🏗️ Compilation

Compile the library:

```bash
make
```

Remove object files:

```bash
make clean
```

Remove object files and the compiled library:

```bash
make fclean
```

Recompile the entire project:

```bash
make re
```

### 🚀 Usage

Include the library header in your C project:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lftprintf -o program
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

## 🗂️ Project structure

- 📄 `ft_printf.h` — Header with the prototypes.
- 📄 `ft_printf.c` — `ft_printf()` and its internal helpers `ft_handle()` and `ft_translate()`.
- 📄 `ft_usefull.c` — Output functions: `ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_putbase`, `ft_putptr`.
- 📄 `Makefile` — Builds `libftprintf.a`.

## 🧠 Technical considerations

- 💻 Written in C.
- 📏 Follows the 42 Norm.
- 🧪 Compiled with `-Wall -Wextra -Werror`.
- ⚙️ Uses a Makefile to automate compilation.
- 📦 Generates the static library `libftprintf.a` with `ar`.
- 🔄 Uses variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`).
- 📤 Uses `write()` to print characters.

## 🔍 Algorithm and justification

### Chosen algorithm

The format string is processed **character by character, in a single pass**.

- Regular characters are printed directly with `ft_putchar()`.
- When `%` is encountered, `ft_handle()` reads the next character, which identifies the conversion.
- `ft_translate()` retrieves the matching argument with `va_arg()` (using the type that corresponds to the conversion) and calls the dedicated output function.
- The number of printed characters is accumulated and returned.
- If a `write()` fails, the `-1` is propagated up to `ft_printf()`, which stops and returns `-1`.
- A `NULL` format and a lone `%` at the end of the string are detected, so the function never reads invalid memory.

**Justification — why a single pass without a buffer?**
Each character is written as soon as it is read. The logic stays simple and easy to verify, the return value is the exact count of written characters, and no memory is allocated, so there is nothing to free and no leak is possible. The trade-off is that many small `write()` calls are slower than buffered output, but the subject explicitly excludes buffer management.

**Justification — why `va_list` is passed by pointer.**
The cursor on the variable arguments must advance in `ft_printf()` each time a helper calls `va_arg()`. Passing a `va_list` by value does not guarantee that, so `ft_handle()` and `ft_translate()` receive a `va_list *`.

**Justification — why a dispatch function with `if` statements.**
`ft_translate()` maps each conversion letter to its type and its output function. Adding a new conversion only requires adding one line, which keeps the code extensible. `if` statements are used because the Norm forbids `switch`.

**Justification — why one function for every base.**
`ft_putbase(nb, base)` prints an `unsigned long` in any base, using the base string as a lookup table:

1. it computes the length of the base string;
2. if `nb` is greater than or equal to that length, it calls itself with `nb / len` to print the leading digits first;
3. it then prints the character `base[nb % len]`.

It is reused for `%u` (`"0123456789"`), `%x` (`"0123456789abcdef"`), `%X` (`"0123456789ABCDEF"`) and `%p` (lowercase hexadecimal after the `0x` prefix). This avoids duplicated code, and choosing lowercase or uppercase only means passing a different string. An `unsigned long` is used so that a 64-bit pointer fits without loss.

### Chosen data structures

- `va_list`: manages the variable arguments. It is the natural structure for variadic functions, since it keeps track of the current argument.
- A string and an integer index: navigate through the format. The index is passed by pointer to `ft_handle()` so that it can skip the conversion letter.
- Integer counters: track the number of printed characters.
- Constant strings (`"0123456789abcdef"`, etc.): used as lookup tables to turn a digit into its character, which is simpler and safer than arithmetic on ASCII codes.

**Justification — why these structures?**
Nothing more complex is needed: no dynamic array, list or buffer is required to print in a single pass. Using only stack variables and constant strings keeps the code short, avoids allocation errors and makes every function easy to test on its own.

## 🧪 Testing

The output and the return value of `ft_printf()` were compared with the original `printf()` on edge cases such as `INT_MIN`, `INT_MAX`, `0`, `-1` with `%u`, `UINT_MAX`, `NULL` with `%s` and `%p`, `NULL` as format, `%%`, an empty string and a string without any `%`. The project was also checked with the Francinette tester.

## 📚 Resources

- 📖 [printf() — Linux Manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- 📘 [C Reference — Variadic Functions](https://en.cppreference.com/w/c/variadic.html)
- 🐧 [Linux man-pages](https://man7.org/linux/man-pages/)
- 💻 [GNU Make Documentation](https://www.gnu.org/software/make/manual/make.html)

### 🤖 AI usage

AI (Claude) was used as a learning support during the project, not to write it. It was used for:

- **Concepts:** explaining how variadic functions work (`va_list`, `va_arg`, why a type must be given), why a `va_list` should be passed by pointer, what a cast is, and how a recursive base conversion works.
- **Code review:** pointing out mistakes in the functions I wrote (missing `return`, wrong types, misplaced braces, uninitialized variables, Norm issues) and giving hints, with occasional one-line fixes. I wrote and corrected the code myself.
- **Makefile and header:** reviewing them for errors.
- **Testing:** suggesting edge cases to compare against the original `printf()`, and providing a small test program.
- **README:** helping to structure and proofread this file.

All code was understood, tested and verified by me.

## 👩‍💻 Author

**Louise** 💜

🎓 42 Student  
🔑 Login: `Kisella`

---

*Made with ☕, C and a little bit of lo-fi.* 🌙