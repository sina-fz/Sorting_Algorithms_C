# Makefile for creating the shared library libmysort.so

# Compiler and flags
CC = gcc
CFLAGS = -O3 -fPIC
TARGET = libmysort.so
SRC = mySort.c

# Rule to create the shared library
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -shared -o $(TARGET) $(SRC)

# Clean rule to remove the generated files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: clean
