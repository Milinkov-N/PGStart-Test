# PGStart Test Project

Module for calculating quadratic equations in form of `ax^2 + bx + c = 0`
written in C language.

## Instructions

### Setup (Alpine/Ubuntu)

If you want to build and run this project on Ubuntu machine you can run this
command to install all the dependecies

```sh
# Alpine
sudo apk add gcc make cppcheck g++ valgrind gtest-dev clang-extra-tools doxygen

# Ubuntu
sudo apt install gcc make cppcheck g++ valgrind gtest-dev clang-format doxygen
```

### Setup (Other)

Or you can build a Docker image and then run it in the container

```sh
# Build image
docker build . -t pgstart/test:1.0

# Run container
docker run -it --rm -v "${pwd}:/app" -w /app pgstart/test:1.0
```

### Build

```sh
# Builds static library quadratic_equation.a and tests executable
make build

# Builds examples
make build-examples

# Generate documentation
make docs
```

### Run

```sh
# Tests
make check
```
