#include "gtest/gtest.h"
#include <limits>
#include <stdexcept>
#include "safe_int.h"
#include "divide_by_zero_exception.h"
#include "empty_container_exception.h"
#include "vector.h"
#include "list.h"

class ExceptionTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

const int kMax = std::numeric_limits<int>::max();
const int kMin = std::numeric_limits<int>::min();

TEST_F(ExceptionTest, SafeIntExceptionTest1) {
    SafeInt safe_int1(kMax);
    SafeInt safe_int2(5);

    EXPECT_THROW(safe_int1 + safe_int2, std::overflow_error);
    try {
        safe_int1 + safe_int2;
    } catch (std::overflow_error& e) {
        std::string err = e.what();
        EXPECT_EQ("Integer overflow occurs in 2147483647 + 5", err);
    }
}

TEST_F(ExceptionTest, SafeIntExceptionTest2) {
    SafeInt safe_int1(kMin);
    SafeInt safe_int2(-1);

    EXPECT_THROW(safe_int1 + safe_int2, std::overflow_error);
    try {
        safe_int1 + safe_int2;
    } catch (std::overflow_error& e) {
        std::string err = e.what();
        EXPECT_EQ("Integer overflow occurs in -2147483648 + -1", err);
    }
}

TEST_F(ExceptionTest, SafeIntExceptionTest3) {
    SafeInt safe_int1(kMax);
    SafeInt safe_int2(-1);

    EXPECT_THROW(safe_int1 - safe_int2, std::overflow_error);
    try {
        safe_int1 - safe_int2;
    } catch (std::overflow_error& e) {
        std::string err = e.what();
        EXPECT_EQ("Integer overflow occurs in 2147483647 - -1", err);
    }
}

TEST_F(ExceptionTest, SafeIntExceptionTest4) {
    SafeInt safe_int1(kMin);
    SafeInt safe_int2(1);

    EXPECT_THROW(safe_int1 - safe_int2, std::overflow_error);
    try {
        safe_int1 - safe_int2;
    } catch (std::overflow_error& e) {
        std::string err = e.what();
        EXPECT_EQ("Integer overflow occurs in -2147483648 - 1", err);
    }
}

TEST_F(ExceptionTest, SafeIntExceptionTest5) {
    SafeInt safe_int1(65536);
    SafeInt safe_int2(65536);

    EXPECT_THROW(safe_int1 * safe_int2, std::overflow_error);
    try {
        safe_int1 * safe_int2;
    } catch (std::overflow_error& e) {
        std::string err = e.what();
        EXPECT_EQ("Integer overflow occurs in 65536 * 65536", err);
    }
}

TEST_F(ExceptionTest, SafeIntExceptionTest6) {
    SafeInt safe_int1(-100000);
    SafeInt safe_int2(100000);

    EXPECT_THROW(safe_int1 * safe_int2, std::overflow_error);
    try {
        safe_int1 * safe_int2;
    } catch (std::overflow_error& e) {
        std::string err = e.what();
        EXPECT_EQ("Integer overflow occurs in -100000 * 100000", err);
    }
}

TEST_F(ExceptionTest, SafeIntExceptionTest7) {
    SafeInt safe_int1(5);
    SafeInt safe_int2(0);

    EXPECT_THROW(safe_int1 / safe_int2, DivideByZeroException);
    try {
        safe_int1 / safe_int2;
    } catch (DivideByZeroException& e) {
        std::string err = e.what();
        EXPECT_EQ("Divide-by-zero exception occurs in 5 / 0", err);
    }
}

TEST_F(ExceptionTest, SafeIntExceptionTest8) {
    SafeInt safe_int1(kMax);
    SafeInt safe_int2(0);

    EXPECT_THROW(safe_int1 / safe_int2, DivideByZeroException);
    try {
        safe_int1 / safe_int2;
    } catch (DivideByZeroException& e) {
        std::string err = e.what();
        EXPECT_EQ("Divide-by-zero exception occurs in 2147483647 / 0", err);
    }
}

TEST_F(ExceptionTest, SafeIntExceptionTest9) {
    SafeInt safe_int1(kMax);
    SafeInt safe_int2(0);

    EXPECT_THROW(safe_int1 % safe_int2, DivideByZeroException);
    try {
        safe_int1 % safe_int2;
    } catch (DivideByZeroException& e) {
        std::string err = e.what();
        EXPECT_EQ("Divide-by-zero exception occurs in 2147483647 % 0", err);
    }
}

TEST_F(ExceptionTest, SafeIntExceptionTest10) {
    SafeInt safe_int1(10);
    SafeInt safe_int2(5);

    SafeInt r1 = safe_int1 + safe_int2;
    SafeInt r2 = safe_int1 - safe_int2;
    SafeInt r3 = safe_int1 * safe_int2;
    SafeInt r4 = safe_int1 / safe_int2;
    SafeInt r5 = safe_int1 % safe_int2;

    EXPECT_EQ(r1.value(), 15);
    EXPECT_EQ(r2.value(), 5);
    EXPECT_EQ(r3.value(), 50);
    EXPECT_EQ(r4.value(), 2);
    EXPECT_EQ(r5.value(), 0);
}

TEST_F(ExceptionTest, VectorTest1) {
    Vector<int> v(3);

    v.PushBack(2);
    v.PushBack(3);
    v.PushBack(4);

    EXPECT_THROW(v[4], std::out_of_range);
    try {
        v[4];
    } catch (std::out_of_range& e) {
        std::string err = e.what();
        EXPECT_EQ("The index is 4, but the size is 3", err);
    }
}

TEST_F(ExceptionTest, VectorTest2) {
    Vector<int> v(3);
    EXPECT_THROW(v.PopBack(), EmptyContainerException);
    try {
        v.PopBack();
    } catch (EmptyContainerException& e) {
        std::string err = e.what();
        EXPECT_EQ("This vector is empty", err);
    }
}

TEST_F(ExceptionTest, VectorTest3) {
    Vector<int> v(3);

    EXPECT_THROW(v[0], std::out_of_range);
    try {
        v[0];
    } catch (std::out_of_range& e) {
        std::string err = e.what();
        EXPECT_EQ("The index is 0, but the size is 0", err);
    }
}

TEST_F(ExceptionTest, VectorTest4) {
    Vector<int> v(2);

    v.PushBack(1);
    v.PushBack(2);
    v.PopBack();
    v.PopBack();

    EXPECT_THROW(v.PopBack(), EmptyContainerException);
    try {
        v.PopBack();
    } catch (EmptyContainerException& e) {
        std::string err = e.what();
        EXPECT_EQ("This vector is empty", err);
    }
}

TEST_F(ExceptionTest, ListTest1) {
    List<int> l;

    l.PushBack(2);
    l.PushBack(3);
    l.PushBack(4);

    EXPECT_THROW(l.At(4), std::out_of_range);
    try {
        l.At(4);
    } catch (std::out_of_range& e) {
        std::string err = e.what();
        EXPECT_EQ("The index is 4, but the size is 3", err);
    }
}

TEST_F(ExceptionTest, ListTest2) {
    List<int> l;
    EXPECT_THROW(l.PopBack(), EmptyContainerException);
    try {
        l.PopBack();
    } catch (EmptyContainerException& e) {
        std::string err = e.what();
        EXPECT_EQ("This list is empty", err);
    }
}

TEST_F(ExceptionTest, ListTest3) {
    List<int> l;

    l.PushBack(2);
    l.PushBack(3);
    l.PopFront();
    l.PopFront();

    EXPECT_THROW(l.PopFront(), EmptyContainerException);
    try {
        l.PopFront();
    } catch (EmptyContainerException& e) {
        std::string err = e.what();
        EXPECT_EQ("This list is empty", err);
    }
}

TEST_F(ExceptionTest, ListTest4) {
    List<int> l;
    EXPECT_THROW(l.At(0), std::out_of_range);
    try {
        l.At(0);
    } catch (std::out_of_range& e) {
        std::string err = e.what();
        EXPECT_EQ("The index is 0, but the size is 0", err);
    }
}
