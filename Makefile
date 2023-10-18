CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -pedantic -std=gnu89
SRCS = *.c
TARGET = hsh

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
