CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

SRC_DIR = src
BUILD_DIR = build

TARGET_NAME = Quest_1
TARGET = $(BUILD_DIR)/$(TARGET_NAME)

SOURCES = $(SRC_DIR)/dmanager_module.c

all: $(TARGET)

$(TARGET): $(SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

