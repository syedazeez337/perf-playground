include ../../toolchain.mk

CC ?= gcc
CFLAGS += -std=c11 -Wall -Wextra -Werror

BIN := bench/bench_factorial
SRC := factorial.c

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

.PHONY: clean
clean:
	rm -f $(BIN)
