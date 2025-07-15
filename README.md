# C++ Module 09 - STL Containers and Algorithms

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![macOS](https://img.shields.io/badge/macOS-000000?style=for-the-badge&logo=apple&logoColor=white)
![42](https://img.shields.io/badge/42-Project-00BABC?style=for-the-badge)
![Score](https://img.shields.io/badge/Score-100%25-brightgreen?style=for-the-badge)

## 📋 Project Overview

C++ Module 09 is the tenth project in the 42 school C++ curriculum, introducing the **Standard Template Library (STL)** with a focus on containers and algorithms in C++98. This module comprises three exercises—**Bitcoin Exchange**, **Reverse Polish Notation (RPN)**, and **PmergeMe**—designed to teach the use of STL containers (`std::map`, `std::stack`, `std::vector`, `std::deque`) and utilities (`std::stringstream`, `std::swap`, `<iomanip>`) while implementing practical algorithms and data processing tasks. It enforces strict C++98 compliance, explicit namespace usage, and no forbidden functions (e.g., `printf`, `alloc`, `free`). Memory management is verified with `valgrind` to ensure no leaks, and outputs adhere to 42’s coding standards (newline-terminated, no `using namespace`).

## ✨ Key Features

- **Exercise 00: Bitcoin Exchange**:
  - Implements a program (`btc`) that calculates the value of Bitcoin amounts on specific dates using a CSV database (`data.csv`).
  - Uses `std::map` to store Bitcoin exchange rates by date, with validation for dates (YYYY-MM-DD) and values (0 to 1000).
  - Processes an input file with lines in the format `date | value`, outputting the product of value and exchange rate.
  - Handles errors (e.g., invalid dates, values, or file access) with descriptive messages.
- **Exercise 01: Reverse Polish Notation**:
  - Implements a program (`RPN`) that evaluates Reverse Polish Notation expressions (e.g., `3 4 +`) using `std::stack`.
  - Supports operations (+, -, *, /) with single-digit operands (< 10), outputting the result or error messages for invalid expressions.
- **Exercise 02: PmergeMe**:
  - Implements the Ford-Johnson merge-insertion sort algorithm using `std::vector` and `std::deque` to sort positive integer sequences.
  - Measures and compares sorting time for both containers in seconds with microsecond precision (e.g., `0.000015 seconds`).
  - Handles input validation (positive integers only) and errors (e.g., `Exception: invalid input: -5`).
  - Supports large inputs (e.g., 3000 elements) with Jacobsthal sequence optimization.
- **C++98 Compliance**:
  - Compiled with `-Wall -Wextra -Werror -std=c++98`.
  - No `using namespace`, `friend`, or forbidden functions (`printf`, `alloc`, `free`).
  - Uses STL containers (`std::map`, `std::stack`, `std::vector`, `std::deque`) and utilities (`std::swap`, `std::stringstream`, `<iomanip>`).
- **Norm Compliance**:
  - Adheres to 42’s coding standards, with newline-terminated outputs and no memory leaks (verified with `valgrind`).

## 🛠️ Prerequisites

- **Operating System**: UNIX-based (Linux, macOS, etc.).
- **Compiler**: `c++` (GCC or Clang, C++98 compatible).
- **Build Tool**: `make`.
- **Debugger**: `valgrind` for memory leak detection.

## 🚀 Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/mde-agui/Cpp09.git
   cd Cpp09
   ```

2. Navigate to an exercise directory and compile:
   ```bash
   cd ex00
   make
   ```
   Repeat for `ex01` and `ex02`. This creates executables (`btc`, `RPN`, `PmergeMe`).

## 📖 Usage

Each exercise is independent and run from its respective directory.

### Exercise 00: Bitcoin Exchange
```bash
cd ex00
./btc test.txt
```
Output (using `data.csv` excerpt):
```
2011-01-03 => 3 = <3 * rate from 2011-01-03>
2011-01-03 => 2 = <2 * rate from 2011-01-03>
2011-01-03 => 1 = <1 * rate from 2011-01-03>
2011-01-03 => 1.2 = <1.2 * rate from 2011-01-03>
2011-01-09 => 1 = <1 * rate from 2011-01-09 or closest prior date>
Error: invalid value => -1
Error: invalid date => 2001-42-42
2012-01-11 => 1 = 7.1
Error: invalid value => 2147483648
```

### Exercise 01: Reverse Polish Notation
```bash
cd ex01
./RPN "3 4 + 2 *"
```
Output:
```
14
```
Invalid input example:
```bash
./RPN "3 + +"
```
Output:
```
Error: invalid expression
```

### Exercise 02: PmergeMe
```bash
cd ex02
./PmergeMe 9 1 18 7 11 2 17 12 14 10 4 3 6 16 8 13 15 5 20 19
```
Output:
```
Before: 9 1 18 7 11 2 17 12 14 10 4 3 6 16 8 13 15 5 20 19
After: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
Time to process a range of 20 elements with std::vector: 0.000015 seconds
Time to process a range of 20 elements with std::deque: 0.000029 seconds
```

Test with random inputs:
```bash
./PmergeMe $(shuf -i 1-30 -n 30 | tr "\n" " ")
```
Output:
```
Before: <random sequence of 30 integers>
After: <sorted sequence, e.g., 1 2 3 ... 30>
Time to process a range of 30 elements with std::vector: <e.g., 0.000022> seconds
Time to process a range of 30 elements with std::deque: <e.g., 0.000046> seconds
```

Check for memory leaks:
```bash
valgrind ./btc test.txt
valgrind ./RPN "3 4 +"
valgrind ./PmergeMe 3 1 4 2 5
```

## 📂 Project Structure

```
cpp_module_09/
├── ex00/                   # Bitcoin Exchange: BTC value calculator
│   ├── Makefile
│   ├── main.cpp
│   ├── BitcoinExchange.hpp
│   ├── BitcoinExchange.cpp
│   └── data.csv
├── ex01/                   # RPN: Reverse Polish Notation calculator
│   ├── Makefile
│   ├── main.cpp
│   ├── RPN.hpp
│   ├── RPN.cpp
├── ex02/                   # PmergeMe: Ford-Johnson merge-insertion sort
│   ├── Makefile
│   ├── main.cpp
│   ├── PmergeMe.hpp
│   ├── PmergeMe.cpp
└── README.md               # This file
```

## 🛠️ Makefile Commands

Each exercise has its own `Makefile` with the following commands:

| Command       | Description                              |
|---------------|------------------------------------------|
| `make`        | Builds the executable (`btc`, `RPN`, `PmergeMe`). |
| `make clean`  | Removes object files.                    |
| `make fclean` | Removes object files and executable.     |
| `make re`     | Rebuilds the project from scratch.       |

**Note**: The provided `Makefile` for Ex00 incorrectly names the executable `btc` (correct) but references `MutantStack` in the success message. Update the `Makefile` to reflect `BitcoinExchange` (e.g., `echo -e "$(GREEN)BitcoinExchange is ready to process!$(RESET)"`).

## 🔍 Technical Details

- **C++ Concepts Covered**:
  - **STL Containers**:
    - Ex00: `std::map` stores Bitcoin exchange rates with dates as keys, providing O(log n) lookup.
    - Ex01: `std::stack` manages operands in LIFO order for RPN calculations.
    - Ex02: `std::vector` (contiguous memory) and `std::deque` (segmented memory) store sequences for sorting.
  - **Algorithms**: Ex02 implements the Ford-Johnson merge-insertion sort with Jacobsthal sequence optimization. Ex00 and Ex01 rely on STL container operations (e.g., `lower_bound` in `std::map`).
  - **File I/O**: Ex00 uses `std::ifstream` and `std::stringstream` to parse CSV and input files.
  - **Time Measurement**: Ex02 uses `gettimeofday` for microsecond-precision timing.
  - **Memory Management**: Ensures no memory leaks with proper STL container usage, verified by `valgrind`.
  - **Error Handling**: Validates inputs (e.g., dates/values in Ex00, RPN expressions in Ex01, positive integers in Ex02) with descriptive error messages.
- **Constraints**:
  - Compiled with `-Wall -Wextra -Werror -std=c++98`.
  - No `using namespace`, `friend`, or forbidden functions (`printf`, `alloc`, `free`).
  - Different containers used across exercises (`std::map` in Ex00, `std::stack` in Ex01, `std::vector`/`std::deque` in Ex02).
  - Outputs end with newlines.
- **External Functions**:
  - Allowed: `std::map`, `std::stack`, `std::vector`, `std::deque`, `std::swap`, `std::stringstream`, `std::ifstream`, `std::cout`, `std::cerr`, `std::endl`, `<iomanip>`, `gettimeofday`, `std::atof`.
- **Performance Insight**:
  - Ex00: `std::map`’s O(log n) lookup is efficient for finding closest exchange rates.
  - Ex01: `std::stack` ensures O(1) push/pop for RPN calculations.
  - Ex02: `std::vector` typically outperforms `std::deque` due to contiguous memory, reducing cache misses.

### Explanation of STL (Standard Template Library)
- **Definition**: The Standard Template Library (STL) is a set of C++ template classes and functions in the C++ Standard Library, providing reusable, type-safe, and efficient data structures (containers), algorithms, and iterators. Introduced in C++98, it simplifies tasks like data storage, sorting, and processing.
- **Components**:
  - **Containers**: Data structures to store objects, such as:
    - `std::map`: Associative container with key-value pairs, used in Ex00 to store Bitcoin exchange rates by date with O(log n) access.
    - `std::stack`: LIFO stack, used in Ex01 for RPN operand management with O(1) push/pop.
    - `std::vector`: Dynamic array with contiguous memory, used in Ex02 for efficient random access and appending.
    - `std::deque`: Double-ended queue with segmented memory, used in Ex02 for performance comparison.
  - **Algorithms**: Generic functions (e.g., `std::sort`, `std::find`). Not used in this module due to custom algorithm requirements (e.g., Ford-Johnson in Ex02).
  - **Iterators**: Objects that traverse containers (e.g., `map::iterator`, `vector::iterator`, `deque::iterator`).
  - **Utilities**: Support classes like `std::pair` and functions like `std::swap` (used in Ex02 for pair sorting) and `std::stringstream` (used in Ex00/Ex01 for parsing).
- **Usage in Module 09**:
  - **Ex00 (Bitcoin Exchange)**: `std::map` stores date-rate pairs, with `lower_bound` for finding closest dates. `std::ifstream` and `std::stringstream` parse CSV and input files.
  - **Ex01 (RPN)**: `std::stack` manages operands in LIFO order. `std::stringstream` parses input tokens.
  - **Ex02 (PmergeMe)**: `std::vector` and `std::deque` store sequences for sorting. `std::swap` sorts pairs, and `<iomanip>` formats timing output.
  - **Iterators**: Used implicitly in container operations (e.g., `map::lower_bound` in Ex00, `vector::insert` in Ex02).
- **Why It Matters**:
  - **Reusability**: STL containers reduce the need for custom data structures.
  - **Type Safety**: Templates ensure compile-time type checking, preventing runtime errors.
  - **Performance**: STL implementations are optimized (e.g., `std::map`’s balanced tree, `std::vector`’s contiguous memory).
  - **Extensibility**: Containers work with user-defined types meeting STL requirements (e.g., copyable types).
- **Example**:
  ```cpp
  std::map<std::string, float> m;
  m["2011-01-03"] = 0.3; // Store date-rate pair
  std::stack<int> s;
  s.push(4); s.push(2); // LIFO: pop order 2, 4
  std::vector<int> v;
  v.push_back(3); v.insert(v.begin() + 1, 2); // Output: 3, 2
  std::swap(v[0], v[1]); // Output: 2, 3
  ```

## 📝 Notes

- **Implementation Details**:
  - **Ex00**: `std::map` uses `lower_bound` to find the closest prior exchange rate for a given date. Validates dates (YYYY-MM-DD, post-2009) and values (0 to 1000).
  - **Ex01**: RPN calculator validates single-digit operands (< 10) and operators (+, -, *, /), using `std::stack` for LIFO processing.
  - **Ex02**: Ford-Johnson algorithm uses Jacobsthal sequence (0, 1, 3, 5, 11, ...) to optimize pend element insertion. Timing is measured with `gettimeofday`.
  - Input validation ensures correct inputs (e.g., valid dates/values in Ex00, RPN expressions in Ex01, positive integers in Ex02).
- **Testing**:
  - **Ex00**: Tests valid/invalid dates, values, and file formats (e.g., `test.txt`).
  - **Ex01**: Tests valid/invalid RPN expressions (e.g., `3 4 +`, `3 + +`).
  - **Ex02**: Tests small inputs (e.g., 5 elements), large inputs (e.g., 3000 elements), duplicates, odd-sized inputs, and invalid inputs.
  - `valgrind` ensures no memory leaks across all exercises.
- **Evaluation**:
  - Outputs match subject requirements (e.g., `date => value = result` in Ex00, RPN results in Ex01, sorted sequences and timing in Ex02).
  - Adheres to 42’s Norminette equivalent (manual checks for line length, naming).

## 📜 License

This project is licensed under the [MIT License](LICENSE).

## 👤 Author

**mde-agui**  
GitHub: [mde-agui](https://github.com/mde-agui)

---

⭐️ If you find this project useful, consider giving it a star on GitHub!
