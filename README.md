# mini-libc

## Overview

**mini-libc** is a minimalistic implementation of the standard C library (`libc`) for Linux systems on `x86_64` architecture.  
It provides core functionalities such as string manipulation, memory management, I/O operations, and process support using direct Linux system calls (`syscall`).  
This library is **freestanding**, meaning it does not depend on any external libraries and can serve as a lightweight replacement for the system `libc` (like glibc).

The goal is to understand how the standard library works under the hood and implement essential functionalities manually.

---

## Features

### String Manipulation (`<string.h>`)

Implemented functions for common string operations:

- `strcpy`, `strncpy` – copy strings
- `strcat`, `strncat` – concatenate strings
- `strlen` – measure string length
- `strcmp`, `strncmp` – compare strings
- `strstr`, `strrstr` – find substrings
- `strchr`, `strrchr` – search for characters
- `memcpy`, `memmove` – copy memory blocks
- `memset` – fill memory with a value
- `memcmp` – compare memory blocks

### Input/Output (`<stdio.h>` & `<unistd.h>`)

- `puts()` – print strings to standard output
- Low-level I/O functions using Linux syscalls:
  - `open`, `close` – open and close files
  - `read`, `write` – read from and write to file descriptors
  - `lseek` – move file pointer
  - `stat`, `fstat` – file status
  - `truncate`, `ftruncate` – adjust file size
- `sleep`, `nanosleep` – implement delays in seconds or nanoseconds

All I/O functions are implemented directly using `syscall()`, providing a low-level interface to the kernel without relying on existing libc functions.

### Memory Management (`<stdlib.h>` & `<sys/mman.h>`)

- `malloc`, `free` – dynamic memory allocation
- `calloc` – allocate zero-initialized memory
- `realloc`, `realloc_array` – resize allocated memory
- `mmap`, `mremap`, `munmap` – map and unmap memory regions

Memory is tracked with a simple linked-list structure (`mem_list`) to manage allocated regions efficiently.

### Process Support

- Minimal syscall-based process support, enabling features like sleeping and interacting with file descriptors.
- Implements error handling with `errno`, which is set appropriately on syscall failures.

---

## Architecture

- `src/` – contains the implementation of all functions
- `include/` – header files defining the API
- `internal/` – internal helper files, e.g., memory list and architecture-specific syscall definitions
- `syscall.c` – generic syscall interface
- `arch/x86_64/syscall_arch.h` – architecture-specific syscall wrappers

All functions are implemented using **Linux system calls**, avoiding any dependency on existing libc functions.

---
## Design Notes

- **Freestanding Implementation:**  
  mini-libc does not rely on glibc or any other system library functions.

- **System Calls:**  
  All I/O, memory, and process operations are implemented using Linux syscalls.

- **Memory Management:**  
  A linked-list tracks allocated memory blocks for `malloc`, `free`, and `realloc`.

- **Error Handling:**  
  Functions set `errno` on failure, similar to standard libc behavior.

---

## Resources

- [GNU libc manual](https://www.gnu.org/software/libc/manual/html_mono/libc.html)  
- [musl libc source](https://elixir.bootlin.com/musl/latest/source)  
- [Linux syscall reference](https://man7.org/linux/man-pages/dir_section_2.html)
