#include "gtest/gtest.h"
#include "int_set.h"

class IntSetTest : public ::testing::Test {
    public:
        IntSetTest() {}
    protected:
        void SetUp() override { }
        void TearDown() override { }
};


TEST_F(IntSetTest, IntSetCopyTest1) {
    IntSet int_set(2);
    IntSet int_set_copy = IntSet(int_set);
    EXPECT_EQ(int_set_copy.capacity(), 2);
}

TEST_F(IntSetTest, IntSetCopyTest2) {
    IntSet int_set(3);
    int_set.Add(1);
    int_set.Add(2);
    int_set.Add(3);
    IntSet int_set_copy = IntSet(int_set);
    EXPECT_EQ(int_set_copy.capacity(), 3);
    EXPECT_EQ(int_set_copy.elements()[0], 1);
    EXPECT_EQ(int_set_copy.elements()[1], 2);
    EXPECT_EQ(int_set_copy.elements()[2], 3);
}

TEST_F(IntSetTest, IntSetCopyTest3) {
    IntSet int_set(4);
    int_set.Add(1);
    IntSet int_set_copy = IntSet(int_set);
    EXPECT_EQ(int_set_copy.size(), 1);
}

TEST_F(IntSetTest, CapacityTest1) {
    IntSet int_set(3);
    EXPECT_EQ(int_set.capacity(), 3);
}

TEST_F(IntSetTest, CapacityTest2) {
    IntSet int_set(4);
    EXPECT_EQ(int_set.capacity(), 4);
}

TEST_F(IntSetTest, CapacityTest3) {
    IntSet int_set(5);
    EXPECT_EQ(int_set.capacity(), 5);
}

TEST_F(IntSetTest, SizeTest1) {
    IntSet int_set(5);
    int_set.Add(3);
    int_set.Add(3);
    int_set.Add(5);
    EXPECT_EQ(int_set.size(), 2);
}

TEST_F(IntSetTest, SizeTest2) {
    IntSet int_set(3);
    int_set.Add(1);
    int_set.Add(2);
    int_set.Add(3);
    EXPECT_EQ(int_set.size(), 3);
}

TEST_F(IntSetTest, SizeTest3) {
    IntSet int_set(4);
    int_set.Add(4);
    int_set.Add(4);
    int_set.Add(4);
    int_set.Add(4);
    EXPECT_EQ(int_set.size(), 1);
}

TEST_F(IntSetTest, OpTest1) {
    IntSet int_set(3);
    int_set.Add(1);
    int_set.Add(2);
    int_set.Add(3);
    EXPECT_EQ(int_set[0], 1);
    EXPECT_EQ(int_set[1], 2);
    EXPECT_EQ(int_set[2], 3);
}

TEST_F(IntSetTest, OpTest2) {
    IntSet int_set(3);
    int_set.Add(1);
    EXPECT_EQ(int_set[0], 1);
    ASSERT_DEATH(int_set[1], "Out of bound");
}

TEST_F(IntSetTest, OpTest3) {
    IntSet int_set(3);
    int_set.Add(1);
    int_set.Add(2);
    int_set.Add(3);
    EXPECT_EQ(int_set[0], 1);
    EXPECT_EQ(int_set[1], 2);
    ASSERT_DEATH(int_set[-2], "Out of bound");
}

TEST_F(IntSetTest, AddTest1) {
    IntSet int_set(2);
    int_set.Add(4);
    int_set.Add(3);
    int_set.Add(5);
    EXPECT_EQ(int_set.capacity(), 6);
    EXPECT_EQ(int_set.size(), 3);
}

TEST_F(IntSetTest, AddTest2) {
    IntSet int_set(2);
    int_set.Add(4);
    int_set.Add(3);
    EXPECT_EQ(int_set.elements()[0], 4);
    EXPECT_EQ(int_set.elements()[1], 3);
}

TEST_F(IntSetTest, AddTest3) {
    IntSet int_set(2);
    int_set.Add(1);
    int_set.Add(1);
    int_set.Add(2);
    int_set.Add(2);
    int_set.Add(2);
    int_set.Add(0);
    EXPECT_EQ(int_set.capacity(), 6);
    EXPECT_EQ(int_set.elements()[0], 1);
    EXPECT_EQ(int_set.elements()[1], 2);
    EXPECT_EQ(int_set.elements()[2], 0);
}

TEST_F(IntSetTest, AddSetTest1) {
    IntSet int_set(3);
    int_set.Add(1);
    int_set.Add(4);

    IntSet int_set_1(3);
    int_set_1.Add(1);
    int_set_1.Add(4);
    int_set_1.Add(7);
    
    int_set.Add(int_set_1);
    
    EXPECT_EQ(int_set.size(), 3);
    EXPECT_EQ(int_set.elements()[0], 1);
    EXPECT_EQ(int_set.elements()[1], 4);
    EXPECT_EQ(int_set.elements()[2], 7);
}

TEST_F(IntSetTest, AddSetTest2) {
    IntSet int_set(4);
    int_set.Add(1);
    int_set.Add(2);

    IntSet int_set_1(3);
    int_set_1.Add(3);
    int_set_1.Add(4);
    int_set_1.Add(5);
    
    int_set.Add(int_set_1);
    EXPECT_EQ(int_set.capacity(), 8);
    EXPECT_EQ(int_set.size(), 5);
    
    EXPECT_EQ(int_set.elements()[0], 1);
    EXPECT_EQ(int_set.elements()[1], 2);
    EXPECT_EQ(int_set.elements()[2], 3);
    EXPECT_EQ(int_set.elements()[3], 4);
    EXPECT_EQ(int_set.elements()[4], 5);
}

TEST_F(IntSetTest, AddSetTest3) {
    IntSet int_set(2);
    int_set.Add(1);
    int_set.Add(2);

    IntSet int_set_1(5);
    int_set_1.Add(3);
    int_set_1.Add(4);
    int_set_1.Add(5);
    int_set_1.Add(9);
    int_set_1.Add(10);
    
    int_set.Add(int_set_1);

    EXPECT_EQ(int_set.capacity(), 10);
    EXPECT_EQ(int_set.size(), 7);
}

TEST_F(IntSetTest, MapTest1) {
    IntSet int_set = IntSet(3);
    int_set.Add(3);
    int_set.Add(4);
    int_set.Add(5);

    int_set.Map([](int i) {return i * 2;});

    EXPECT_EQ(int_set.elements()[0], 6);
    EXPECT_EQ(int_set.elements()[1], 8);
    EXPECT_EQ(int_set.elements()[2], 10);
}

TEST_F(IntSetTest, MapTest2) {
    IntSet int_set = IntSet(3);
    int_set.Add(10);
    int_set.Add(20);
    int_set.Add(30);

    int_set.Map([](int i) {return i - 10;});

    EXPECT_EQ(int_set.elements()[0], 0);
    EXPECT_EQ(int_set.elements()[1], 10);
    EXPECT_EQ(int_set.elements()[2], 20);
}

TEST_F(IntSetTest, MapTest3) {
    IntSet int_set = IntSet(3);
    int_set.Add(3);
    int_set.Add(4);
    int_set.Add(5);

    int_set.Map([](int i) {return i % 2;});

    EXPECT_EQ(int_set.size(), 2);
    EXPECT_EQ(int_set.elements()[0], 1);
    EXPECT_EQ(int_set.elements()[1], 0);
}

TEST_F(IntSetTest, ForAllTest1) {
    IntSet int_set(3);
    int_set.Add(3);
    int_set.Add(4);
    int_set.Add(5);

    EXPECT_EQ(int_set.ForAll([](int i) { if (i < 10) {return true;} else {return false;} }), true);
}

TEST_F(IntSetTest, ForAllTest2) {
    IntSet int_set(3);
    int_set.Add(2);
    int_set.Add(4);
    int_set.Add(6);

    EXPECT_EQ(int_set.ForAll([](int i) { if (i % 2 == 0) {return true;} else {return false;} }), true);
}

TEST_F(IntSetTest, ForAllTest3) {
    IntSet int_set(3);
    int_set.Add(3);
    int_set.Add(4);
    int_set.Add(5);

    EXPECT_EQ(int_set.ForAll([](int i) { if (i % 2) {return true;} else {return false;} }), false);
}


