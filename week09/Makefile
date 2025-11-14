#TODO: Set your googletest directory path
GTEST_DIR = /home/kmbae/googletest/googletest

CC = clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include
TIDYFLAGS = --checks=-*,cppcoreguidelines-*,-cppcoreguidelines-owning-memory,readability-*,-cppcoreguidelines-special-member-functions,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-c-copy-assignment-signature,-non-const-global-variables,-readability-const-return-type,-readability-avoid-const-params-in-decls

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
SOURCES := $(shell find . -name "*.cc" ! -name "test.cc" ! -name "hw9.cc")
HEADERS := $(shell find . -name "*.h")

#TODO: Set your executable target
all : hw9

#TODO: Change 'hw3.cc' and '*.o' to your main source file and util target respectively
hw9: hw9.cc vector.o list.o stack.o queue.o 
	$(CC) --std=c++17 $^ -o $@

#TODO: Change '*.h' and '*.cc' to your source files
vector.o : vector.cc
	$(CC) --std=c++17 -c $^ -o $@

list.o : list.cc
	$(CC) --std=c++17 -c $^ -o $@

stack.o : stack.cc
	$(CC) --std=c++17 -c $^ -o $@

queue.o : queue.cc
	$(CC) --std=c++17 -c $^ -o $@

#TODO: Change '*.cc' to your test file
test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO: Change '*.o'and '*.o' to your object targets
test: test.o vector.o list.o stack.o queue.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

#TODO: Change 'main' and 'main_test' to your executable and test respectively
clean:
	 rm -f gtest.a gtest_main.a *.o hw9 test

tidy:
	clang-tidy $(SOURCES) $(HEADERS) $(TIDYFLAGS) -- -x c++ -std=c++17

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



