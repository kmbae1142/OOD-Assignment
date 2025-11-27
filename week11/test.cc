#include "gtest/gtest.h"
#include "sort.h"
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <string>

class ArraySortTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

class VectorSortTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

class ListSortTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

class DequeSortTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

class IntIncreasingOrder {
    public:
        int operator()(const int& x, const int& y) {
            if (x > y) {
                return 1;
            }
            else {
                return 0;
            }
        }
};

class IntDecreasingOrder {
    public:
        int operator()(const int& x, const int& y) {
            if (x < y) {
                return 1;
            }
            else {
                return 0;
            }
        }
};

class FloatIncreasingOrder {
    public:
        int operator()(const float& x, const float& y) {
            if (x > y) {
                return 1;
            }
            else {
                return 0;
            }
        }
};

class FloatDecreasingOrder {
    public:
        int operator()(const float& x, const float& y) {
            if (x < y) {
                return 1;
            }
            else {
                return 0;
            }
        }
};

class StringIncreasingOrder {
    public:
        int operator()(const std::string& x, const std::string& y) {
            if (x > y) {
                return 1;
            }
            else {
                return 0;
            }
        }
};

class StringDecreasingOrder {
    public:
        int operator()(const std::string& x, const std::string& y) {
            if (x < y) {
                return 1;
            }
            else {
                return 0;
            }
        }
};

// int, float, ...
template <typename T, typename N>
std::string SortResultToStr(T* container) {
    Sort<T, N>(container->begin(), container->end());
    std::string result = "";
    for (auto n : *container) {
        result += (std::to_string(n) + ' ');
    }
    result.pop_back();
    return result;
}

// string
template <typename T, typename N>
std::string SortResult(T* container) {
    Sort<T, N>(container->begin(), container->end());
    std::string result = "";
    for (auto n : *container) {
        result += (n + ' ');
    }
    result.pop_back();
    return result;
}


TEST_F(ArraySortTest, ArraySortTest1) {
    std::array<int, 9> arr = {1, 4, 6, 3, 2, 8, 5, 9, 7};
    std::string result1 = SortResultToStr<std::array<int, 9>, IntIncreasingOrder>(&arr);
    arr = {1, 4, 6, 3, 2, 8, 5, 9, 7};
    std::string result2 = SortResultToStr<std::array<int, 9>, IntDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "1 2 3 4 5 6 7 8 9");
    EXPECT_EQ(result2, "9 8 7 6 5 4 3 2 1");
}

TEST_F(ArraySortTest, ArraySortTest2) {
    std::array<float, 9> arr = {8.1, 6.5, 7.9, 8.0, 5.4, 1.1, 3.4, 2.6, 4.4};
    std::string result1 = SortResultToStr<std::array<float, 9>, FloatIncreasingOrder>(&arr);
    arr = {8.1, 6.5, 7.9, 8.0, 5.4, 1.1, 3.4, 2.6, 4.4};
    std::string result2 = SortResultToStr<std::array<float, 9>, FloatDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "1.100000 2.600000 3.400000 4.400000 5.400000 6.500000 7.900000 8.000000 8.100000");
    EXPECT_EQ(result2, "8.100000 8.000000 7.900000 6.500000 5.400000 4.400000 3.400000 2.600000 1.100000");
}

TEST_F(ArraySortTest, ArraySortTest3) {
    std::array<std::string, 5> arr = {"ab", "ababa", "caa", "bcb", "baa"};
    std::string result1 = SortResult<std::array<std::string, 5>, StringIncreasingOrder>(&arr);
    arr = {"ab", "ababa", "caa", "bcb", "baa"};
    std::string result2 = SortResult<std::array<std::string, 5>, StringDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "ab ababa baa bcb caa");
    EXPECT_EQ(result2, "caa bcb baa ababa ab");
}

TEST_F(ArraySortTest, ArraySortTest4) {
    std::array<int, 1> arr = {1};
    std::string result = SortResultToStr<std::array<int, 1>, IntIncreasingOrder>(&arr);
    
    EXPECT_EQ(result, "1");
}

TEST_F(VectorSortTest, VectorSortTest1) {
    std::vector<int> arr = {1, 4, 6, 3, 2, 8, 5, 9, 7};
    std::string result1 = SortResultToStr<std::vector<int>, IntIncreasingOrder>(&arr);
    arr = {1, 4, 6, 3, 2, 8, 5, 9, 7};
    std::string result2 = SortResultToStr<std::vector<int>, IntDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "1 2 3 4 5 6 7 8 9");
    EXPECT_EQ(result2, "9 8 7 6 5 4 3 2 1");
}

TEST_F(VectorSortTest, VectorSortTest2) {
    std::vector<float> arr = {8.1, 6.5, 7.9, 8.0, 5.4, 1.1, 3.4, 2.6, 4.4};
    std::string result1 = SortResultToStr<std::vector<float>, FloatIncreasingOrder>(&arr);
    arr = {8.1, 6.5, 7.9, 8.0, 5.4, 1.1, 3.4, 2.6, 4.4};
    std::string result2 = SortResultToStr<std::vector<float>, FloatDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "1.100000 2.600000 3.400000 4.400000 5.400000 6.500000 7.900000 8.000000 8.100000");
    EXPECT_EQ(result2, "8.100000 8.000000 7.900000 6.500000 5.400000 4.400000 3.400000 2.600000 1.100000");
}

TEST_F(VectorSortTest, VectorSortTest3) {
    std::vector<std::string> arr = {"ab", "ababa", "caa", "bcb", "baa"};
    std::string result1 = SortResult<std::vector<std::string>, StringIncreasingOrder>(&arr);
    arr = {"ab", "ababa", "caa", "bcb", "baa"};
    std::string result2 = SortResult<std::vector<std::string>, StringDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "ab ababa baa bcb caa");
    EXPECT_EQ(result2, "caa bcb baa ababa ab");
}

TEST_F(VectorSortTest, VectorSortTest4) {
    std::vector<int> arr = {1};
    std::string result1 = SortResultToStr<std::vector<int>, IntIncreasingOrder>(&arr);
    
    EXPECT_EQ(result1, "1");
}

TEST_F(ListSortTest, ListSortTest1) {
    std::list<int> arr = {1, 4, 6, 3, 2, 8, 5, 9, 7};
    std::string result1 = SortResultToStr<std::list<int>, IntIncreasingOrder>(&arr);
    arr = {1, 4, 6, 3, 2, 8, 5, 9, 7};
    std::string result2 = SortResultToStr<std::list<int>, IntDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "1 2 3 4 5 6 7 8 9");
    EXPECT_EQ(result2, "9 8 7 6 5 4 3 2 1");
}

TEST_F(ListSortTest, ListSortTest2) {
    std::list<float> arr = {8.1, 6.5, 7.9, 8.0, 5.4, 1.1, 3.4, 2.6, 4.4};
    std::string result1 = SortResultToStr<std::list<float>, FloatIncreasingOrder>(&arr);
    arr = {8.1, 6.5, 7.9, 8.0, 5.4, 1.1, 3.4, 2.6, 4.4};
    std::string result2 = SortResultToStr<std::list<float>, FloatDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "1.100000 2.600000 3.400000 4.400000 5.400000 6.500000 7.900000 8.000000 8.100000");
    EXPECT_EQ(result2, "8.100000 8.000000 7.900000 6.500000 5.400000 4.400000 3.400000 2.600000 1.100000");
}

TEST_F(ListSortTest, ListSortTest3) {
    std::list<std::string> arr = {"ab", "ababa", "caa", "bcb", "baa"};
    std::string result1 = SortResult<std::list<std::string>, StringIncreasingOrder>(&arr);
    arr = {"ab", "ababa", "caa", "bcb", "baa"};
    std::string result2 = SortResult<std::list<std::string>, StringDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "ab ababa baa bcb caa");
    EXPECT_EQ(result2, "caa bcb baa ababa ab");
}

TEST_F(ListSortTest, ListSortTest4) {
    std::list<int> arr = {1};
    std::string result1 = SortResultToStr<std::list<int>, IntIncreasingOrder>(&arr);
    
    EXPECT_EQ(result1, "1");
}

TEST_F(DequeSortTest, DequeSortTest1) {
    std::deque<int> arr = {1, 4, 6, 3, 2, 8, 5, 9, 7};
    std::string result1 = SortResultToStr<std::deque<int>, IntIncreasingOrder>(&arr);
    arr = {1, 4, 6, 3, 2, 8, 5, 9, 7};
    std::string result2 = SortResultToStr<std::deque<int>, IntDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "1 2 3 4 5 6 7 8 9");
    EXPECT_EQ(result2, "9 8 7 6 5 4 3 2 1");
}

TEST_F(DequeSortTest, DequeSortTest2) {
    std::deque<float> arr = {8.1, 6.5, 7.9, 8.0, 5.4, 1.1, 3.4, 2.6, 4.4};
    std::string result1 = SortResultToStr<std::deque<float>, FloatIncreasingOrder>(&arr);
    arr = {8.1, 6.5, 7.9, 8.0, 5.4, 1.1, 3.4, 2.6, 4.4};
    std::string result2 = SortResultToStr<std::deque<float>, FloatDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "1.100000 2.600000 3.400000 4.400000 5.400000 6.500000 7.900000 8.000000 8.100000");
    EXPECT_EQ(result2, "8.100000 8.000000 7.900000 6.500000 5.400000 4.400000 3.400000 2.600000 1.100000");
}

TEST_F(DequeSortTest, DequeSortTest3) {
    std::deque<std::string> arr = {"ab", "ababa", "caa", "bcb", "baa"};
    std::string result1 = SortResult<std::deque<std::string>, StringIncreasingOrder>(&arr);
    arr = {"ab", "ababa", "caa", "bcb", "baa"};
    std::string result2 = SortResult<std::deque<std::string>, StringDecreasingOrder>(&arr); 
    
    EXPECT_EQ(result1, "ab ababa baa bcb caa");
    EXPECT_EQ(result2, "caa bcb baa ababa ab");
}

TEST_F(DequeSortTest, DequeSortTest4) {
    std::deque<int> arr = {1};
    std::string result1 = SortResultToStr<std::deque<int>, IntIncreasingOrder>(&arr);
    
    EXPECT_EQ(result1, "1");
}
