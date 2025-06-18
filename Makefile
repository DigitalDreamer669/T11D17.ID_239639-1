CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

SRC_DIR = src
BUILD_DIR = build

TARGET_1_NAME = Quest_1
TARGET_1 = $(BUILD_DIR)/$(TARGET_1_NAME)

TARGET_2_NAME = Quest_2
TARGET_2 = $(BUILD_DIR)/$(TARGET_2_NAME)

TARGET_3_NAME = Quest_3
TARGET_3 = $(BUILD_DIR)/$(TARGET_3_NAME)

SOURCES_1 = $(SRC_DIR)/dmanager_module.c
SOURCES_2 = $(SRC_DIR)/list.c $(SRC_DIR)/list_test.c
SOURCES_3 = $(SRC_DIR)/stack.c $(SRC_DIR)/stack_test.c


all: $(TARGET_1) $(TARGET_2) $(TARGET_3)

list_test: $(TARGET_2)

stack_test: $(TARGET_3)

$(TARGET_1): $(SOURCES_1) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SOURCES_1) -o $(TARGET_1)

$(TARGET_2): $(SOURCES_2) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SOURCES_2) -o $(TARGET_2)

$(TARGET_3): $(SOURCES_3) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SOURCES_3) -o $(TARGET_3)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


clean:
	rm -rf $(BUILD_DIR)

check:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRC_DIR)/*.c

.PHONY: all clean check list_test stack_test
