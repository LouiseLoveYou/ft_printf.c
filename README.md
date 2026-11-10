*This project has been created as part of the 42 curriculum by Kisella.*

# 🌙 ft_printf

## 📝 Description

ft_printf is an individual project from the 42 school curriculum. The goal is to recreate the standard C `printf()` function by implementing a custom version called `ft_printf()`.

This project introduces variadic functions in C and develops a better understanding of formatted output, argument handling, conversions and data representation.

The implementation reproduces the behavior of the original `printf()` without implementing its buffer management.

## 🔹 Conversions

**🔠 Character and string**
- `%c` — Prints a single character.
- `%s` — Prints a string.

**📍 Pointers**
- `%p` — Prints a pointer address in hexadecimal.

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

## 🧠 Technical considerations

- 💻 Written in C.
- 📏 Follows the 42 Norm.
- 🧪 Compiled with `-Wall -Wextra -Werror`.
- ⚙️ Uses a Makefile to automate compilation.
- 📦 Generates the static library `libftprintf.a`.
- 🔄 Uses variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`).
- 📤 Uses `write()` to print characters.
- 🔗 Uses Libft for authorized functions.

### 🔍 Algorithm

The format string is processed character by character.

- Regular characters are printed directly.
- When `%` is encountered, the next character identifies the conversion.
- The corresponding argument is retrieved using `va_arg()`.
- A dedicated function handles the conversion.
- The number of printed characters is counted and returned.

### 🗂️ Data structures

The mandatory implementation mainly relies on:

- `va_list` to manage variable arguments.
- A pointer to navigate through the format string.
- Integer counters to track printed characters.

The project uses a modular approach with dedicated helper functions for each conversion, making the code easier to maintain and understand.

## 📚 Resources

- 📖 [printf() — Linux Manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- 📘 [C Reference — Variadic Functions](https://en.cppreference.com/w/c/variadic.html)
- 🐧 [Linux man-pages](https://man7.org/linux/man-pages/)
- 💻 [GNU Make Documentation](https://www.gnu.org/software/make/manual/make.html)

### 🤖 AI usage

AI tools may be used as learning support to clarify variadic functions, understand documentation, explore C concepts and help structure the README.

All code must be understood, tested and verified by the author in accordance with the 42 curriculum guidelines.

## 👩‍💻 Author

**Louise** 💜

🎓 42 Student  
🔑 Login: `Kisella`

---

*Made with ☕, C and a little bit of lo-fi.* 🌙