# DIRECTORIES
BIN_DIR := ./bin
OBJ_DIR := ./obj
SRC_DIR := ./src

# TARGET
LOS_SHELL := $(BIN_DIR)/shell.app

# SOURCE FILES
C_SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')

# OBJECT FILES
C_OBJ_FILES := $(C_SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# PROGRAMS
CC := x86_64-los-gcc
CC_FLAGS := -g -c

LD := x86_64-los-gcc

# BASE RULES
all: dirs $(LOS_SHELL)

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(BIN_DIR)/*

# COMPILATION RULES
.SECONDEXPANSION:

$(LOS_SHELL): $(C_OBJ_FILES)
	$(LD) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $$(@D)/.
	$(CC) $(CC_FLAGS) -o $@ $^

# DIRECTORY RULES
$(OBJ_DIR)/.:
	@mkdir -p $@

$(OBJ_DIR)%/.:
	@mkdir -p $@

dirs:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

# . RULES
.PRECIOUS: $(OBJ_DIR)/. $(OBJ_DIR)%/.
.PHONY: dirs