# Set variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
TARGET = detect-palindrome
SRC = detect-palindrome.c

# Set default target
all: $(TARGET)

# Compile the program with the flags
$(TARGET): $(SRC) detect-palindrome.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Delete the binary on clean
clean:
	rm -f $(TARGET)

# Tells make that clean and all is not a real file but rather a command
.PHONY: all clean
