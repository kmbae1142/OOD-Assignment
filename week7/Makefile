#TODO: Set your googletest directory path
GTEST_DIR = /home/kmbae/googletest/googletest

CC = clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include
TIDYFLAGS = --checks=-*,cppcoreguidelines-*,-cppcoreguidelines-owning-memory,readability-*,-cppcoreguidelines-special-member-functions,-cppcoreguidelines-avoid-const-or-ref-data-members,-cppcoreguidelines-avoid-non-const-global-variables,-readability-const-return-type

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
SOURCES := $(shell find . -name "*.cc" ! -name "test.cc" ! -name "hw7.cc")
HEADERS := $(shell find . -name "*.h")

#TODO: Set your executable target
all : hw7

#TODO: Change 'hw3.cc' and '*.o' to your main source file and util target respectively
hw7: hw7.cc node.o int_node.o string_node.o tree_util.o 
	$(CC) --std=c++17 $^ -o $@

#TODO: Change '*.h' and '*.cc' to your source files
node.o : node.cc
	$(CC) --std=c++17 -c $^ -o $@

int_node.o : int_node.cc
	$(CC) --std=c++17 -c $^ -o $@

string_node.o : string_node.cc
	$(CC) --std=c++17 -c $^ -o $@

tree_util.o : tree_util.cc
	$(CC) --std=c++17 -c $^ -o $@

#TODO: Change '*.cc' to your test file
test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO: Change '*.o'and '*.o' to your object targets
test: test.o node.o int_node.o string_node.o tree_util.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

#TODO: Change 'main' and 'main_test' to your executable and test respectively
clean:
	 rm -f gtest.a gtest_main.a *.o hw6 test

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



