#include "gtest/gtest.h"
#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

class VectorTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

class ListTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

class StackTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

class QueueTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

TEST_F(VectorTest, VectorTest1) {
    Vector<int> v1(3);
    v1.PushBack(1);
    v1.PushBack(3);
    v1.PushBack(2);
    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 3);
    EXPECT_EQ(v1[2], 2);
    EXPECT_EQ(v1.size(), 3);
    EXPECT_EQ(v1.capacity(), 3);
}

TEST_F(VectorTest, VectorTest2) {
    Vector v1(3);
    v1.PushBack(1);
    v1.PushBack(3);
    v1.PushBack(2);
    v1.PushBack(4);
    EXPECT_EQ(v1[3], 4);
    EXPECT_EQ(v1[0], 1);
    EXPECT_EQ(v1[1], 3);
    EXPECT_EQ(v1[2], 2);
    EXPECT_EQ(v1.size(), 4);
    EXPECT_EQ(v1.capacity(), 7);
    ASSERT_DEATH(v1[4], "Out of Bound");
}

TEST_F(VectorTest, VectorTest3) {
    Vector v1(3);
    EXPECT_EQ(v1.IsEmpty(), true);
}

TEST_F(VectorTest, VectorTest4) {
    Vector v1(2);
    v1.PushBack(1);
    v1.PushBack(3);
    Vector v2 = v1;
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2.capacity(), 2);
    v1.PopBack();
    // Verifying deep copy
    EXPECT_EQ(v2[1], 3);
}

TEST_F(VectorTest, VectorTest5) {
    Vector v1(3);
    v1.PushBack(1);
    v1.PushBack(3);
    v1.PushBack(2);
    v1.PopBack();
    EXPECT_EQ(v1.size(), 2);
    v1.PopBack();
    EXPECT_EQ(v1.size(), 1);
    v1.PopBack();
    ASSERT_DEATH(v1.PopBack(), "Out of Bound");
    EXPECT_EQ(v1.size(), 0);
}

TEST_F(ListTest, ListTest1) {
    List l1 = List();
    ASSERT_DEATH(l1.At(0), "Out of Bound");
    l1.PushBack(1);
    l1.PushBack(3);
    l1.PushFront(2);
    l1.PushFront(4);
    EXPECT_EQ(l1.At(0), 4);
    EXPECT_EQ(l1.At(1), 2);
    EXPECT_EQ(l1.At(2), 1);
    EXPECT_EQ(l1.At(3), 3);
    ASSERT_DEATH(l1.At(4), "Out of Bound");
    EXPECT_EQ(l1.size(), 4);
}
TEST_F(ListTest, ListTest2) {
    List l1 = List();

    l1.PushBack(1);
    l1.PushBack(3);
    l1.PushFront(2);
    l1.PushFront(4);

    l1.PopBack();
    EXPECT_EQ(l1.size(), 3);
    EXPECT_EQ(l1.At(2), 1);

    l1.PopFront();
    EXPECT_EQ(l1.size(), 2);
    EXPECT_EQ(l1.At(0), 2);

    l1.PopFront();
    EXPECT_EQ(l1.size(), 1);
    EXPECT_EQ(l1.At(0), 1);

    l1.PopBack();
    EXPECT_EQ(l1.size(), 0);
    
    ASSERT_DEATH(l1.PopFront(), "Out of Bound");
    ASSERT_DEATH(l1.PopBack(), "Out of Bound");
    ASSERT_DEATH(l1.At(0), "Out of Bound");
}

TEST_F(ListTest, ListTest3) {
    List l1 = List();

    l1.PushBack(1);
    l1.PushBack(3);
    l1.PushFront(2);
    l1.PushFront(4);
    EXPECT_EQ(l1.IsEmpty(), false);

    List l2 = l1;
    EXPECT_EQ(l2.At(0), 4);
    EXPECT_EQ(l2.At(1), 2);
    EXPECT_EQ(l2.At(2), 1);
    EXPECT_EQ(l2.At(3), 3);

    EXPECT_EQ(l2.size(), 4);
    l1.PopBack();
    EXPECT_EQ(l2.At(3), 3);
    l1.PopFront();
    EXPECT_EQ(l2.At(0), 4);
}

TEST_F(ListTest, ListTest4) {
    List l1 = List();
    EXPECT_EQ(l1.size(), 0);
    EXPECT_EQ(l1.IsEmpty(), true);
}

TEST_F(ListTest, ListTest5) {
    List l1 = List();
    l1.PushFront(2);
    l1.PushFront(3);
    EXPECT_EQ(l1.At(0), 3);
}

TEST_F(StackTest, StackTest1) {
    Stack s1 = Stack(4);

    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);

    EXPECT_EQ(s1.size(), 4);

    EXPECT_EQ(s1.Pop(), 4);
    EXPECT_EQ(s1.Pop(), 3);
    EXPECT_EQ(s1.Pop(), 2);
    EXPECT_EQ(s1.Pop(), 1);
}

TEST_F(StackTest, StackTest2) {
    Stack s1 = Stack(3);

    EXPECT_EQ(s1.size(), 0);
    EXPECT_EQ(s1.capacity(), 3);

    s1.Push(3);
    s1.Push(2);
    s1.Push(1);
    s1.Push(0);
    
    EXPECT_EQ(s1.size(), 4);
    EXPECT_EQ(s1.capacity(), 7);
}

TEST_F(StackTest, StackTest3) {
    Stack s1 = Stack(2);
    
    s1.Push(1);
    s1.Push(2);
    s1.Pop();
    s1.Pop();

    ASSERT_DEATH(s1.Pop(), "Out of Bound");
}

TEST_F(StackTest, StackTest4) {
    Stack s1 = Stack(3);

    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    Stack s2 = s1;
    s1.Pop();
    EXPECT_EQ(s2.size(), 3);
}

TEST_F(StackTest, StackTest5) {
    Stack s1 = Stack(3);
    EXPECT_EQ(s1.IsEmpty(), true);
}

TEST_F(QueueTest, QueueTest1) {
    Queue q1 = Queue();

    q1.Add(1);
    q1.Add(3);
    q1.Add(2);
    q1.Add(4);

    EXPECT_EQ(q1.size(), 4);
}

TEST_F(QueueTest, QueueTest2) {
    Queue q1 = Queue();

    q1.Add(1);
    q1.Add(3);
    q1.Add(2);
    q1.Add(4);

    EXPECT_EQ(q1.Poll(), 1);
    EXPECT_EQ(q1.size(), 3);

    EXPECT_EQ(q1.Poll(), 3);
    EXPECT_EQ(q1.size(), 2);

    EXPECT_EQ(q1.Poll(), 2);
    EXPECT_EQ(q1.size(), 1);

    EXPECT_EQ(q1.Poll(), 4);
    EXPECT_EQ(q1.size(), 0);

    EXPECT_EQ(q1.IsEmpty(), true);
    ASSERT_DEATH(q1.Poll(), "Out of Bound");
}

TEST_F(QueueTest, QueueTest3) {
    Queue q1 = Queue();
    
    q1.Add(9);
    q1.Add(5);
    q1.Add(0);

    Queue q2 = q1;
    q1.Add(2);
    EXPECT_EQ(q2.size(), 3);
}

TEST_F(QueueTest, QueueTest4) {
    Queue q1 = Queue();
    ASSERT_DEATH(q1.Poll(), "Out of Bound");
}

TEST_F(QueueTest, QueueTest5) {
    Queue q1 = Queue();
    EXPECT_EQ(q1.IsEmpty(), true);
    EXPECT_EQ(q1.size(), 0);
}
