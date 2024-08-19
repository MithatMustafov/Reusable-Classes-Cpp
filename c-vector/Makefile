# Define the directories
BIN_DIR = bin
V1_DIR = src/v1
V2_DIR = src/v2

# Define the target executables
TARGET_V1 = $(BIN_DIR)/mainV1.exe
TARGET_V2 = $(BIN_DIR)/mainV2.exe

# Define the source files
SRC_MAIN_V1 = $(V1_DIR)/main.c
SRC_MAIN_V2 = $(V2_DIR)/main.c
VECTOR_SRC_V1 = $(V1_DIR)/vector.c
VECTOR_SRC_V2 = $(V2_DIR)/vector.c

# Define the object files
OBJ_MAIN_V1 = $(BIN_DIR)/mainV1.o
OBJ_VECTOR_V1 = $(BIN_DIR)/vector_v1.o

OBJ_MAIN_V2 = $(BIN_DIR)/mainV2.o
OBJ_VECTOR_V2 = $(BIN_DIR)/vector_v2.o

# The default target to build both versions
all: $(TARGET_V1) $(TARGET_V2)

# Rule to build the V1 target executable
$(TARGET_V1): $(OBJ_MAIN_V1) $(OBJ_VECTOR_V1)
	@echo "Linking $(TARGET_V1)"
	$(CC) $(CFLAGS) -o $(TARGET_V1) $(OBJ_MAIN_V1) $(OBJ_VECTOR_V1)

# Rule to build the V2 target executable
$(TARGET_V2): $(OBJ_MAIN_V2) $(OBJ_VECTOR_V2)
	@echo "Linking $(TARGET_V2)"
	$(CC) $(CFLAGS) -o $(TARGET_V2) $(OBJ_MAIN_V2) $(OBJ_VECTOR_V2)

# Rule to build the object files for V1
$(BIN_DIR)/mainV1.o: $(SRC_MAIN_V1)
	@echo "Compiling $(SRC_MAIN_V1) for V1"
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_MAIN_V1) -o $(BIN_DIR)/mainV1.o

$(BIN_DIR)/vector_v1.o: $(VECTOR_SRC_V1)
	@echo "Compiling $(VECTOR_SRC_V1)"
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(VECTOR_SRC_V1) -o $(BIN_DIR)/vector_v1.o

# Rule to build the object files for V2
$(BIN_DIR)/mainV2.o: $(SRC_MAIN_V2)
	@echo "Compiling $(SRC_MAIN_V2) for V2"
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_MAIN_V2) -o $(BIN_DIR)/mainV2.o

$(BIN_DIR)/vector_v2.o: $(VECTOR_SRC_V2)
	@echo "Compiling $(VECTOR_SRC_V2)"
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(VECTOR_SRC_V2) -o $(BIN_DIR)/vector_v2.o

# Rule to clean up build files
clean:
	@echo "Cleaning up..."
	-del /Q $(BIN_DIR)\*.exe $(BIN_DIR)\*.o

# Rule to create a new clean build
rebuild: clean all

.PHONY: all clean rebuild
