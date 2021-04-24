CC=gcc

MODULE_SRC=$(wildcard **/**/*.c)
MODULE_OBJ=$(patsubst %.c,%.o,$(MODULE_SRC))

TEST_SRC=test/main.c
TEST_OBJ=test/main.o

test: $(MODULE_OBJ) $(TEST_OBJ)
	$(CC) -o $@.exe $^

.PHONY: clean memory_check

clean:
	rm -rf test.exe **/**/*.o **/*.o

memory_check:
	valgrind --leak-check=yes --show-reachable=yes ./test.exe
