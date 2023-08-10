CC = g++ -std=c++17 -Wall -Werror -Wextra -Wuninitialized
GTK_FLAGS = `pkg-config gtkmm-3.0 --cflags --libs`
GTEST_LIBS = -lgtest
DELETE = rm -rf
TEST_FLAGS =  -lgtest

FIND_VALGRIND_ERRORS = grep --color=always -n "ERROR SUMMARY" $(VALGRIND_OUTPUT) | grep -v "0 errors from 0 contexts" || true
FIND_VALGRIND_LEAKS = grep --color=always -n "definitely lost:" $(VALGRIND_OUTPUT) | grep -v "0 bytes in 0 blocks" || true
VALGRIND = valgrind --log-file="$(VALGRIND_OUTPUT)" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med

VALGRIND_OUTPUT = valgrind.txt

TARGET_PATH = build
TEST_TARGET  = SmartCalcTests
BUILD_TARGET = SmartCalc

SRC_FILES = controller/*.cc \
			model/*.cc \
			view/*.cc \
			main.cc
BUILD_PATH = build

CLANG_FORMAT = clang-format

.PHONY: all test clean style $(CLANG_FORMAT) $(VALGRIND)

all: test build run

build_path:
	mkdir -p $(TARGET_PATH)

build: style build_path
	$(CC) $(SRC_FILES) -o $(TARGET_PATH)/$(BUILD_TARGET) $(GTK_FLAGS)

run: build
	./$(TARGET_PATH)/$(BUILD_TARGET)

test: style build_path
	$(CC) $(SRC_FILES) -o $(TARGET_PATH)/$(TEST_TARGET) $(GTEST_LIBS)
	./$(TARGET_PATH)/$(TEST_TARGET)

clean:
	$(DELETE) $(TARGET_PATH)/$(TEST_TARGET) $(TARGET_PATH)/$(BUILD_TARGET) $(VALGRIND_OUTPUT)

style: $(CLANG_FORMAT)

$(CLANG_FORMAT):
	$(CLANG_FORMAT) --style=Google -i $(wildcard */*.cc *.cc */*.h *.h) || true

valgrind: test
	$(VALGRIND) ./$(TARGET_PATH)/$(TEST_TARGET) || true
	$(FIND_VALGRIND_ERRORS)
	$(FIND_VALGRIND_LEAKS)
