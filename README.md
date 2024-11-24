
# Set ADT Using AVL Tree

This repository contains an implementation of a Set Abstract Data Type (ADT) using a balanced AVL tree as part of UNSW's COMP2521 22T2 Assignment 1. It demonstrates the implementation of standard set operations with efficient time complexity.

## Features

1. **Basic Set Operations**:
   - **SetInsert**: Adds an element to the set.
   - **SetContains**: Checks if an element exists in the set.
   - **SetSize**: Returns the number of elements in the set.
   - **SetShow**: Prints the set's elements in sorted order.

2. **Set Operations**:
   - **SetUnion**: Returns the union of two sets.
   - **SetIntersection**: Returns the intersection of two sets.
   - **SetDifference**: Returns the difference of two sets (elements in Set1 not in Set2).
   - **SetEquals**: Determines if two sets are equal.
   - **SetSubset**: Determines if one set is a subset of another.

3. **Advanced Operations**:
   - **SetFloor**: Finds the largest element less than or equal to a given number.
   - **SetCeiling**: Finds the smallest element greater than or equal to a given number.

4. **Cursor Operations**:
   - Allows sequential traversal through set elements (under development).

## Time Complexity Analysis

| Operation         | Time Complexity | Description                                 |
|-------------------|-----------------|---------------------------------------------|
| **SetInsert**     | O(log n)        | Balancing during AVL tree insertion.       |
| **SetContains**   | O(log n)        | Search in AVL tree.                        |
| **SetUnion**      | O(n + m)        | Traverse both sets and combine elements.   |
| **SetIntersection** | O(n + m)      | Traverse and match elements.               |
| **SetDifference** | O(n + m)        | Traverse and find elements unique to one set. |
| **SetEquals**     | O(n + m)        | Compare two sets for equality.             |
| **SetSubset**     | O(n + m)        | Verify if all elements in Set1 are in Set2. |
| **SetFloor**      | O(log n)        | Search for the largest fitting element.    |
| **SetCeiling**    | O(log n)        | Search for the smallest fitting element.   |

## File Structure

- **`Set.c`**: Implementation of the Set ADT.
- **`Set.h`**: Interface for the Set ADT.
- **`SetStructs.h`**: Internal data structures (e.g., AVL tree nodes).
- **`test.c`**: Tests for basic Set operations.
- **`testSet.c`**: Comprehensive tests for all functions.
- **`analysis.txt`**: Complexity analysis and documentation.
- **`Makefile`**: Automates compilation.

## Compilation and Execution

1. **Compilation**:
   Use the provided `Makefile` to compile all files:
   ```bash
   make
   ```

2. **Execution**:
   Run the tests to verify functionality:
   ```bash
   ./test       # Basic tests
   ./testSet    # Comprehensive tests
   ```

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/Set-ADT.git
   ```

2. Navigate to the project directory:
   ```bash
   cd Set-ADT
   ```

3. Build and test the project:
   ```bash
   make
   ./test
   ./testSet
   ```

## Acknowledgments

This project was developed as part of UNSW's COMP2521 course, focusing on data structures and algorithms. Special thanks to the instructors and course materials for providing a comprehensive framework for learning.
