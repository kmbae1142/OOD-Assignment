#include "gtest/gtest.h"
#include "int_accumulator.h"
#include "float_accumulator.h"

class IntAccTest : public ::testing::Test {
    public:
        IntAccTest() : acc_(3) {}
    protected:
        void SetUp() override {}
        void TearDown() override {}
        int_accumulator::Accumulator acc_;
};

class FloatAccTest : public ::testing::Test {
    public:
        FloatAccTest() : acc_(3.0) {}
    protected:
        void SetUp() override {}
        void TearDown() override {}
        float_accumulator::Accumulator acc_;
};


TEST_F(IntAccTest, IntAddTest1) {
    acc_.Add(5);
    EXPECT_EQ(acc_.acc(), 8);
}

TEST_F(IntAccTest, IntAddTest2) {
    acc_.Add(10);
    EXPECT_EQ(acc_.acc(), 13);
}

TEST_F(IntAccTest, IntAddTest3) {
    acc_.Add(7);
    EXPECT_EQ(acc_.acc(), 10);
}

TEST_F(IntAccTest, IntSubTest1) {
    acc_.Sub(5);
    EXPECT_EQ(acc_.acc(), -2);
}

TEST_F(IntAccTest, IntSubTest2) {
    acc_.Sub(3);
    EXPECT_EQ(acc_.acc(), 0);
}

TEST_F(IntAccTest, IntSubTest3) {
    acc_.Sub(2);
    EXPECT_EQ(acc_.acc(), 1);
}

TEST_F(IntAccTest, IntMulTest1) {
    acc_.Mul(5);
    EXPECT_EQ(acc_.acc(), 15);
}

TEST_F(IntAccTest, IntMulTest2) {
    acc_.Mul(3);
    EXPECT_EQ(acc_.acc(), 9);
}

TEST_F(IntAccTest, IntMulTest3) {
    acc_.Mul(10);
    EXPECT_EQ(acc_.acc(), 30);
}

TEST_F(IntAccTest, IntDivTest1) {
    ASSERT_DEATH(acc_.Div(0), "Divide by Zero");
}

TEST_F(IntAccTest, IntDivTest2) {
    acc_.Div(3);
    EXPECT_EQ(acc_.acc(), 1);
}

TEST_F(IntAccTest, IntDivTest3) {
    acc_.Div(1);
    EXPECT_EQ(acc_.acc(), 3);
}

TEST_F(FloatAccTest, floatAddTest1) {
    acc_.Add(1.2);
    EXPECT_FLOAT_EQ(acc_.acc(), 4.2);
}

TEST_F(FloatAccTest, floatAddTest2) {
    acc_.Add(3.2);
    EXPECT_FLOAT_EQ(acc_.acc(), 6.2);
}

TEST_F(FloatAccTest, floatAddTest3) {
    acc_.Add(2.2);
    EXPECT_FLOAT_EQ(acc_.acc(), 5.2);
}

TEST_F(FloatAccTest, floatMulTest1) {
    acc_.Mul(1.2);
    EXPECT_FLOAT_EQ(acc_.acc(), 3.6);
}

TEST_F(FloatAccTest, floatMulTest2) {
    acc_.Mul(2.2);
    EXPECT_FLOAT_EQ(acc_.acc(), 6.6);
}

TEST_F(FloatAccTest, floatMulTest3) {
    acc_.Mul(3.2);
    EXPECT_FLOAT_EQ(acc_.acc(), 9.6);
}

TEST_F(FloatAccTest, floatDivTest1) {
    ASSERT_DEATH(acc_.Div(0.0), "Divide by Zero");
}

TEST_F(FloatAccTest, floatDivTest2) {
    acc_.Div(1.0);
    EXPECT_FLOAT_EQ(acc_.acc(), 3.0);
}

TEST_F(FloatAccTest, floatDivTest3) {
    acc_.Div(3.0);
    EXPECT_FLOAT_EQ(acc_.acc(), 1.0);
}

TEST_F(FloatAccTest, floatSubTest1) {
    acc_.Sub(3.0);
    EXPECT_FLOAT_EQ(acc_.acc(), 0.0);
}

TEST_F(FloatAccTest, floatSubTest2) {
    acc_.Sub(1.0);
    EXPECT_FLOAT_EQ(acc_.acc(), 2.0);
}

TEST_F(FloatAccTest, floatSubTest3) {
    acc_.Sub(2.1);
    EXPECT_FLOAT_EQ(acc_.acc(), 0.9);
}
