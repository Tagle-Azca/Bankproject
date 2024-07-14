# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC_DIRS = $(shell find . -type d)
OBJ_DIR = obj
BIN_DIR = bin
SRCS = $(shell find . -name '*.c')
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)
TARGET = $(BIN_DIR)/BankProject

# Regla principal
all: $(TARGET)

# Crear binario
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Regla para compilar archivos .c en archivos .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# Incluir dependencias
-include $(DEPS)

# Limpiar archivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean