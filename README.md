# 42 Program Projects

Welcome to my GitHub repository for the 42 program projects. This repository contains various projects and exercises I completed during my time at 42. Below is a detailed description of the files and projects you will find here.

## Table of Contents

- [Introduction](#introduction)
- [Projects](#projects)
  - [Libft](#libft)
  - [Get Next Line](#get-next-line)
  - [ft_printf](#ft_printf)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The 42 program is an innovative software engineering school that focuses on project-based learning. Throughout the program, students complete various projects that cover a wide range of programming concepts and technologies. This repository serves as a portfolio of my work and progress during the 42 program.

## Projects

### Libft

**Directory:** `libft/`

Libft is a custom implementation of the standard C library functions. This project includes various utility functions for string manipulation, memory management, linked lists, and more. The goal was to get familiar with writing basic functions from scratch and understanding their inner workings.

### Get Next Line

**Directory:** `get_next_line/`

The Get Next Line project involves writing a function that reads a line from a file descriptor and returns it. This function handles various edge cases, such as reading from multiple file descriptors simultaneously and dealing with buffer sizes. The implementation includes two versions:
- `get_next_line.c`: Handles a single file descriptor.
- `get_next_line_bonus.c`: Extends functionality to handle multiple file descriptors concurrently.

### ft_printf

**Directory:** `ft_printf/`

The ft_printf project involves creating a custom implementation of the `printf` function in C. This function handles various format specifiers, flags, and width/precision modifiers. The project aims to deepen the understanding of variadic functions and formatted output in C.

## Usage

To use or test any of the projects, navigate to the respective directory and follow the instructions provided in the README file within each project directory. Generally, you can compile the projects using `make` and run the resulting executable.

### Example

For `get_next_line`:
```sh
cd get_next_line/
make
./gnl_test <input_file>
```

## Contributing

If you would like to contribute to any of the projects, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes.
4. Submit a pull request with a detailed description of your changes.

## License

This repository is licensed under the DigitalPool License. See the `LICENSE` file for more information.

---

Thank you for visiting my 42 program projects repository. If you have any questions or feedback, feel free to contact me or open an issue. Enjoy exploring the projects!
