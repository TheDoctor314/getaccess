CC = gcc
SRC = getaccess.c
CC_FLAGS = -Wall -Werror -Wpedantic
EXEC = getaccess

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) -o $(EXEC) $(CC_FLAGS) $(SRC)

clean: $(EXEC)
	rm $(EXEC)
