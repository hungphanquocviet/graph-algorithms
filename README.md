# Graph Algorithms

This repository contains implementations of various graph algorithms in C++ that I found particularly interesting. Each directory is independent and self-contained, featuring a Makefile, a header file, an implementation file, and a test file. There is no strict organizational structure across the repository, meaning each directory can be treated individually (though this is not really good software practice) :).

## Testing Framework

The test files use the Google Test Suite, which you can install as follows:

### Installation Instructions

1. Clone the GoogleTest repository into the `graph-algorithm` directory:

    ```bash
    git clone https://github.com/google/googletest.git
    ```

2. Navigate to the `googletest` directory:

    ```bash
    cd googletest
    ```

3. Build GoogleTest:

    ```bash
    cmake .
    make clean
    make all
    ```

**Note:** Ensure that `cmake` is installed on your system before proceeding.

## Creation Date

- Initial creation: September 2, 2024