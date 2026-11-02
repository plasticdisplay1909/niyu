# Niyu Language Specification — v0

**Status:** Draft  
**Version:** 0.1.0

## 1. Introduction

Niyu is a statically typed, compiled programming language designed to offer familiar C++-style syntax with a simpler learning curve and its own identity.

The compiler is implemented in C++20.

### Design goals

- Familiar syntax for programmers coming from C and C++.
- Static type checking.
- Readable and helpful compiler errors.
- Simple language fundamentals.
- Room for original language features in future versions.

## 2. Program Structure

A Niyu program consists of declarations and function definitions.

The entry point is `main`.

```cpp
int main() {
    print("Hello, Niyu!");
    return 0;
}
```

## 3. Data Types

Initial built-in types:

| Type | Description |
|---|---|
| `int` | Integer values |
| `float` | Floating-point values |
| `bool` | Boolean values |
| `string` | Text |
| `void` | No return value |

## 4. Variables and Constants

Variables are mutable by default.

```cpp
int age = 19;
float pi = 3.14159;
bool active = true;
string name = "Niyu";

const int MAX_SIZE = 100;
```

A constant cannot be reassigned after initialization.

## 5. Operators

### Arithmetic

`+`, `-`, `*`, `/`, `%`

### Assignment

`=`, `+=`, `-=`, `*=`, `/=`

### Comparison

`==`, `!=`, `<`, `>`, `<=`, `>=`

### Logical

`&&`, `||`, `!`

### Increment and decrement

`++`, `--`

## 6. Conditional Statements

```cpp
if (age >= 18) {
    print("Adult");
} else {
    print("Minor");
}
```

## 7. Loops

### For loop

```cpp
for (int i = 0; i < 10; i++) {
    print(i);
}
```

### While loop

```cpp
int i = 0;

while (i < 5) {
    print(i);
    i++;
}
```

## 8. Functions

Functions have an explicit return type and typed parameters.

```cpp
int add(int a, int b) {
    return a + b;
}

void greet() {
    print("Hello!");
}
```

## 9. Comments

Single-line comments:

```cpp
// This is a comment
```

Multi-line comments:

```cpp
/*
   This is a
   multi-line comment.
*/
```

## 10. Input and Output

The initial version provides a built-in `print()` function.

```cpp
print("Hello");
print(42);
```

Input handling and a standard I/O library are deferred.

## 11. Scope

Variables declared inside a block `{}` are accessible only within that block.

```cpp
int main() {
    int x = 10;

    if (x > 5) {
        int y = 20;
        print(y);
    }

    // y is not accessible here
    return 0;
}
```

## 12. Initial Limitations

The first version will not support:

- Classes and objects
- Pointers and references
- Templates and generics
- User-defined structures
- Inheritance
- Exception handling
- Modules and imports
- Dynamic memory management

These may be introduced in future versions.

## 13. Future Design Direction

Niyu should not simply reproduce C++.

Future development will explore distinctive features such as:

- Type inference
- Pattern matching
- String interpolation
- Improved compiler diagnostics
- An original language feature with a clear purpose

These features are not part of v0 until formally specified.