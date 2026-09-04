CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2

TARGET := term3d
SRC := src/main.c src/vec3.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
