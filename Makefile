CC=gcc

MODULE_SRC=$(wildcard **/**/*.c)
MODULE_OBJ=$(patsubst %.c,%.o,$(MODULE_SRC))

TEST_SRC=$(wildcard test/*.c)
TEST_OBJ=$(patsubst %.c,%.o,$(TEST_SRC))

test: $(MODULE_OBJ) $(TEST_OBJ)
	$(CC) -o $@.exe $^

.PHONY: clean memory_check

clean:
	rm -rf test.exe **/**/*.o **/*.o

memory_check:
	valgrind --leak-check=yes --show-reachable=yes ./test.exe
