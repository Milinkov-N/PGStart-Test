NAME          := quadratic_equation

CC            := gcc
CXX           := g++

CFLAGS        := -Wall -Werror -Wextra
CXXFLAGS      := -std=c++17
LDFLAGS       := -lgtest -lgtest_main

BUILD_DIR     := build
SRC_DIR       := src
TESTS_DIR     := tests
EXAMPLES_DIR  := examples
INCLUDE       := include

LIB           := $(NAME).a
SRC           := $(NAME).c
SRC           := $(SRC:%=$(SRC_DIR)/%)
OBJ           := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TESTS_SRC     := main.cc
TESTS_SRC     := $(TESTS_SRC:%=$(TESTS_DIR)/%)
TESTS_OBJ     := $(TESTS_SRC:$(TESTS_DIR)/%.cc=$(BUILD_DIR)/%.o)

EXAMPLES_SRC  := basic_example.c
EXAMPLES_SRC  := $(EXAMPLES_SRC:%=$(EXAMPLES_DIR)/%)
EXAMPLES_OBJ  := $(EXAMPLES_SRC:$(EXAMPLES_DIR)/%.c=$(BUILD_DIR)/%.o)

TESTS_EXE     := $(NAME)_tests.exe

all: check build-examples valgrind docs

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -std=c11 $(CFLAGS) -I$(INCLUDE) -c -o $@ $<

$(BUILD_DIR)/%.o: $(EXAMPLES_DIR)/%.c
	$(CC) -std=c11 $(CFLAGS) -I$(INCLUDE) -c -o $@ $<

$(BUILD_DIR)/%.o: $(TESTS_DIR)/%.cc
	$(CXX) $(CFLAGS) $(CXXFLAGS) -I$(INCLUDE) -c -o $@ $<

$(LIB): $(OBJ)
	ar -rcs $(BUILD_DIR)/$(LIB) $^ 

build: clang-format $(TESTS_OBJ) $(LIB)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -I$(INCLUDE) $(TESTS_OBJ) $(LDFLAGS) \
		$(BUILD_DIR)/$(LIB) \
		-o $(BUILD_DIR)/$(TESTS_EXE)

rebuild: clean build

build-examples: clang-format $(EXAMPLES_OBJ) $(LIB)
	$(CC) -std=c11 $(CFLAGS) -I$(INCLUDE) \
		$(EXAMPLES_OBJ) $(BUILD_DIR)/$(LIB) \
		-o $(BUILD_DIR)/basic_example.exe

check: build
	./$(BUILD_DIR)/$(TESTS_EXE)

valgrind: build
	CK_FORK=no valgrind \
		--vgdb=no \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=$(BUILD_DIR)/RESULT_VALGRIND.txt \
		./$(BUILD_DIR)/$(TESTS_EXE)

clang-format:
	clang-format --Werror src/*.c include/*.h tests/*.cc examples/*.c -n

.PHONY: docs
docs:
	doxygen

clean:
	rm -rf ./$(BUILD_DIR)/*
