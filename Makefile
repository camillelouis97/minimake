CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra -g -I./src

EXEC=minimake

SRC=arr_utils.c exec_rules.c minimake.c parser.c parser_struct.c option_handler.c

LIB_SRC=$(SRC:.c=.o)

VPATH=./src

.PHONY: all clean

$(EXEC): $(LIB_SRC)

all: $(EXEC)

clean:
	rm -f $(EXEC)
	rm -f *.o
	rm -rf $(MY_DIR)
