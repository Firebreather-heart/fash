# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Iinclude 

# Source files and object files
SRC = main.c tokenizer.c cd.c defcom.c path-manage.c utils.c 
OBJ_DIR = runtime
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Target executable
TARGET = $(OBJ_DIR)/fash

# Rules
all: $(TARGET)

$(TARGET): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
