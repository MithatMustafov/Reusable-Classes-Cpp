# Define the directories
BIN_DIR = bin
SRC_DIR = src

# Define the target executables
TARGET_INTEGER = $(BIN_DIR)/mainINTEGER.exe
TARGET_STRING = $(BIN_DIR)/mainSTRING.exe

# Define the source files
SRC_INTEGER = $(SRC_DIR)/mainINTEGER.c
SRC_STRING = $(SRC_DIR)/mainSTRING.c
VECTOR_SRC = $(SRC_DIR)/vector.c  # Add vector source file

# Define the object files
OBJ_INTEGER = $(BIN_DIR)/mainINTEGER.o
OBJ_STRING = $(BIN_DIR)/mainSTRING.o
OBJ_VECTOR = $(BIN_DIR)/vector.o  # Add vector object file

# The default target to build
all: $(TARGET_INTEGER) $(TARGET_STRING)

# Rule to build the target executables
$(TARGET_INTEGER): $(OBJ_INTEGER) $(OBJ_VECTOR)
	@echo "Linking $(TARGET_INTEGER)"
	$(CC) $(CFLAGS) -o $(TARGET_INTEGER) $(OBJ_INTEGER) $(OBJ_VECTOR)

$(TARGET_STRING): $(OBJ_STRING) $(OBJ_VECTOR)
	@echo "Linking $(TARGET_STRING)"
	$(CC) $(CFLAGS) -o $(TARGET_STRING) $(OBJ_STRING) $(OBJ_VECTOR)

# Rule to build the object files
$(BIN_DIR)/mainINTEGER.o: $(SRC_INTEGER)
	@echo "Compiling $(SRC_INTEGER)"
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_INTEGER) -o $(BIN_DIR)/mainINTEGER.o

$(BIN_DIR)/mainSTRING.o: $(SRC_STRING)
	@echo "Compiling $(SRC_STRING)"
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_STRING) -o $(BIN_DIR)/mainSTRING.o

$(BIN_DIR)/vector.o: $(VECTOR_SRC)
	@echo "Compiling $(VECTOR_SRC)"
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(VECTOR_SRC) -o $(BIN_DIR)/vector.o

# Rule to clean up build files
clean:
	@echo "Cleaning up..."
	del /Q $(BIN_DIR)\*.exe $(BIN_DIR)\*.o

# Rule to create a new clean build
rebuild: clean all

.PHONY: all clean rebuild
