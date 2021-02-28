NAME=xn

CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Wpedantic
LDFLAGS=

SRC_DIR=src
OBJ_DIR=target
TEST_DIR=tests

SRC_FILES=$(shell find $(SRC_DIR)/ -type f -name '*.c')
SRC_FILES_WITHOUT_MAIN=$(shell find $(SRC_DIR)/ -type f ! -name 'main.c' -name '*.c')
TEST_FILES=$(shell find $(TEST_DIR)/ -type f -name '*.c')

OBJ_FILES=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRC_FILES:.c=.o))

all: $(NAME)

debug: CFLAGS += -DDEBUG -g
debug: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) -o $(OBJ_DIR)/$@ $^ $(LDFLAGS)
	rm -f $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(SRC_FILES_WITHOUT_MAIN) $(TEST_FILES)
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/$@ $^ $(LDFLAGS)
	rm -f $(OBJ_FILES)
	./$(OBJ_DIR)/test

.PHONY: clean run

clean:
	rm -f $(OBJ_FILES) $(OBJ_DIR)/$(NAME)

run: all
	./$(OBJ_DIR)/$(NAME) ${args}