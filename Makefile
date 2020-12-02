CC := gcc
CFLAGS := -MMD -MP

SRC_DIR := $(wildcard src/**/*.c)
OBJ_DIR := obj
LIB_DIR := lib

LIB := $(LIB_DIR)/libalgorithms.a
SRC := $(wildcard $(SRC_DIR)/**/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all structure

all: $(LIB)

$(LIB): $(OBJ) | $(LIB_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< $@

structure: ./*
	for file in $^ ; do \
		if $${file} != README.md || $${file} != Makefile ; then \
			mkdir -p $(OBJ_DIR)/$${file} ; \
                fi; \
	done

$(OJB_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< $@

$(LIB_DIR) $(OBJ_DIR):
	mkdir -p $@
