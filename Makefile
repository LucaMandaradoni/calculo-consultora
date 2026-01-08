# ===== Configuracion =====
CC      = x86_64-w64-mingw32-gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude
LDFLAGS =
TARGET  = build/mi_programa.exe

SRC_DIR = src
OBJ_DIR = build/obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# ===== Reglas =====
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: all clean
