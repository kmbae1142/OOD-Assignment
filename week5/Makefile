#TODO: Set your googletest directory path
GTEST_DIR = /home/kmbae/googletest/googletest

CC = clang++
CPPFLAGS += -O1 -g -fsanitize=address -isystem $(GTEST_DIR)/include
TIDYFLAGS = --checks=-*,cppcoreguidelines-*,-cppcoreguidelines-owning-memory,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-special-member-functions

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
SOURCES := $(shell find . -name "*.cc" ! -name "test.cc")
HEADERS := $(shell find . -name "*.h")

#TODO: Set your executable target
all : hw5

#TODO: Change 'hw3.cc' and '*.o' to your main source file and util target respectively
hw5: hw5.cc int_set.o 
	$(CC) -O1 -g -fsanitize=address --std=c++17 $^ -o $@

#TODO: Change '*.h' and '*.cc' to your source files
int_set.o : int_set.cc
	$(CC) -O1 -g -fsanitize=address --std=c++17 -c $^ -o $@

#TODO: Change '*.cc' to your test file
test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO: Change '*.o'and '*.o' to your object targets
test: test.o int_set.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

#TODO: Change 'main' and 'main_test' to your executable and test respectively
clean:
	 rm -f gtest.a gtest_main.a *.o hw5 test

tidy:
	clang-tidy $(SOURCES) $(HEADERS) $(TIDYFLAGS) --fix -- -x c++ -std=c++17

gtest-all.o: $(GTEST_SRCS_) 
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean



