SRC_DIR = src
TEST_DIR = test

BUILD_DIR = build
BIN_DIR = bin

UNITY_DIR = unity
UNITY_SRC = $(UNITY_DIR)/unity.c

CC = gcc-15

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

all: $(BIN_DIR)/sorted_array_tests

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(SRC_DIR)

$(BUILD_DIR)/unity.o: $(UNITY_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(SRC_DIR) -I$(UNITY_DIR)

$(BIN_DIR)/sorted_array_tests: $(BUILD_DIR)/sorted_array.o $(BUILD_DIR)/sorted_array_tests.o $(BUILD_DIR)/unity.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)