# CPP Modules

<div align="center">
  <img src="https://img.shields.io/badge/42-Project-blue" alt="42 Project Badge">
  <img src="https://img.shields.io/badge/C%2B%2B-98-00599C?style=flat&logo=c%2B%2B" alt="C++ Badge">
  <img src="https://img.shields.io/badge/OOP-Programming-green" alt="OOP Badge">
</div>

## 💡 About

CPP Modules is a collection of 10 modules designed to introduce Object-Oriented Programming in C++. This project progressively covers fundamental concepts of modern C++, from basics to advanced topics like templates and STL, while adhering to the C++98 standard.

## 🛠️ Usage

### Requirements
* C++ compiler (c++)
* Make
* C++98 standard

### Instructions

**1. Compiling**
```bash
$ git clone https://github.com/Wdaoudi/cpp-modules
$ cd cpp-modules/cpp0X/ex0X
$ make
```

**2. Running**
```bash
$ ./[executable_name]
```

## 📋 Modules Overview

### Module Structure
| Module | Concepts | Exercises |
|--------|----------|-----------|
| **CPP00** | Namespaces, classes, member functions, stdio streams | Megaphone, PhoneBook, Account |
| **CPP01** | Memory allocation, pointers to members, references | BraiiiiiiinnnzzzZ, Moar brainz!, HI THIS IS BRAIN, Unnecessary violence, Sed is for losers, Harl |
| **CPP02** | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | My First Orthodox Class, Fixed-point numbers, BSP |
| **CPP03** | Inheritance | ClapTrap, ScavTrap, FragTrap, DiamondTrap |
| **CPP04** | Subtype polymorphism, abstract classes, interfaces | Polymorphism, I don't want to set the world on fire, Abstract class, Interface & recap |
| **CPP05** | Repetition and Exceptions | Bureaucrat, Form up maggots!, No you need form 28B..., At least this beats coffee-making |
| **CPP06** | C++ casts | Scalar conversion, Serialization, Identify real type |
| **CPP07** | C++ templates | Start with a few functions, Iter, Array |
| **CPP08** | Templated containers, iterators, algorithms | Easy find, Span, Mutated abomination |
| **CPP09** | STL | Bitcoin Exchange, RPN, PmergeMe |

## ⚙️ Key Concepts

### Learning Progression
* **C++ Basics**: Transition from C to C++ with classes and namespaces
* **Memory Management**: Dynamic allocation, RAII, references vs pointers
* **Core OOP**: Orthodox Canonical Form, constructors, destructors
* **Inheritance**: Single, multiple, and diamond problem
* **Polymorphism**: Virtual functions, abstract classes, interfaces
* **Error Handling**: Custom exceptions
* **Type Casting**: static_cast, dynamic_cast, const_cast, reinterpret_cast
* **Generic Programming**: Function and class templates
* **STL**: Containers, iterators, algorithms

### Orthodox Canonical Form
From Module 02 onwards, all classes must implement:
```cpp
class ClassName {
    public:
        ClassName();                                 // Default constructor
        ClassName(const ClassName& src);             // Copy constructor
        ClassName& operator=(const ClassName& rhs);  // Copy assignment operator
        ~ClassName();                                // Destructor
};
```

## 🚨 Rules and Restrictions

* **C++98 standard** mandatory
* Forbidden:
  * `using namespace <ns_name>` and `friend` keywords
  * C functions (`*printf()`, `*alloc()`, `free()`)
  * STL before Module 08
  * Boost libraries
* Compilation flags: `c++ -Wall -Wextra -Werror -std=c++98`
* Memory leak management required
* One Makefile per exercise

## 📚 Project Examples

### Module 00 - PhoneBook
A simple phonebook demonstrating class usage
```bash
$ ./phonebook
ADD
SEARCH
EXIT
```

### Module 05 - Bureaucrat
Bureaucracy system with exception handling
```cpp
try {
    Bureaucrat bob(75, "Bob");
    Form form("Budget Request", 50, 25);
    bob.signForm(form);
} catch (std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

### Module 09 - Bitcoin Exchange
Calculate Bitcoin value at a given date
```bash
$ ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
```

## 🧪 Testing

Each module includes its own tests. Example:
```bash
$ cd cpp01/ex00
$ make
$ ./Brainz
```

## 📖 Resources
* [C++ Reference](https://en.cppreference.com/)
* [Learn C++](https://www.learncpp.com/)
* [ISO C++98 Standard](https://www.iso.org/standard/25845.html)
* [42 Coding Standard](https://github.com/42School/norminette)

## 🗣️ Author

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/Wdaoudi">
        <img src="https://github.com/Wdaoudi.png" width="100px;" alt="wdaoudi-"/>
        <br />
        <sub><b>wdaoudi-</b></sub>
      </a>
    </td>
  </tr>
</table>

## 📝 License

This project is [MIT](LICENSE) licensed.
