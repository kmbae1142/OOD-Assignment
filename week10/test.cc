#include "gtest/gtest.h"
#include <string>
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
    Vector<float> v1(3);
    v1.PushBack(1);
    v1.PushBack(3.2);
    v1.PushBack(2.8);
    v1.PushBack(4.9);
    EXPECT_FLOAT_EQ(v1[3], 4.9);
    EXPECT_FLOAT_EQ(v1[0], 1.0);
    EXPECT_FLOAT_EQ(v1[1], 3.2);
    EXPECT_FLOAT_EQ(v1[2], 2.8);
    EXPECT_EQ(v1.size(), 4);
    EXPECT_EQ(v1.capacity(), 7);
    ASSERT_DEATH(v1[4], "Out of Bound");
}

TEST_F(VectorTest, VectorTest3) {
    Vector<int> v1(3);
    EXPECT_EQ(v1.IsEmpty(), true);
}

TEST_F(VectorTest, VectorTest4) {
    Vector<char> v1(2);
    v1.PushBack('c');
    v1.PushBack('a');
    v1 = v1;
    EXPECT_EQ(v1[0], 'c');
    EXPECT_EQ(v1[1], 'a');
    Vector<char> v2 = v1;
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2.capacity(), 2);
    v1.PopBack();

    EXPECT_EQ(v2[0], 'c');
    // Verifying deep copy
    EXPECT_EQ(v2[1], 'a');
}

TEST_F(VectorTest, VectorTest5) {
    Vector<std::string> v1(3);
    v1.PushBack("What");
    v1.PushBack("is");
    v1.PushBack("this???");
    
    EXPECT_EQ(v1[0], "What");
    EXPECT_EQ(v1[1], "is");
    EXPECT_EQ(v1[2], "this???");

    v1.PopBack();
    EXPECT_EQ(v1.size(), 2);
    v1.PopBack();
    EXPECT_EQ(v1.size(), 1);
    v1.PopBack();
    ASSERT_DEATH(v1.PopBack(), "Out of Bound");
    EXPECT_EQ(v1.size(), 0);
}

TEST_F(ListTest, ListTest1) {
    List<int> l1 = List<int>();
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
    List<char> l1 = List<char>();

    l1.PushBack('a');
    l1.PushBack('c');
    l1.PushFront('b');
    l1.PushFront('d');

    l1.PopBack();
    EXPECT_EQ(l1.size(), 3);
    EXPECT_EQ(l1.At(2), 'a');

    l1.PopFront();
    EXPECT_EQ(l1.size(), 2);
    EXPECT_EQ(l1.At(0), 'b');

    l1.PopFront();
    EXPECT_EQ(l1.size(), 1);
    EXPECT_EQ(l1.At(0), 'a');

    l1.PopBack();
    EXPECT_EQ(l1.size(), 0);
    
    ASSERT_DEATH(l1.PopFront(), "Out of Bound");
    ASSERT_DEATH(l1.PopBack(), "Out of Bound");
    ASSERT_DEATH(l1.At(0), "Out of Bound");
}

TEST_F(ListTest, ListTest3) {
    List<float> l1 = List<float>();

    l1.PushBack(1);
    l1.PushBack(3.3);
    l1.PushFront(2.2);
    l1.PushFront(4.4);

    EXPECT_EQ(l1.IsEmpty(), false);
    EXPECT_FLOAT_EQ(l1.At(0), 4.4);
    EXPECT_FLOAT_EQ(l1.At(1), 2.2);
    EXPECT_FLOAT_EQ(l1.At(2), 1.0);
    EXPECT_FLOAT_EQ(l1.At(3), 3.3);

    l1 = l1;
    List<float> l2 = l1;
    EXPECT_FLOAT_EQ(l2.At(0), 4.4);
    EXPECT_FLOAT_EQ(l2.At(1), 2.2);
    EXPECT_FLOAT_EQ(l2.At(2), 1.0);
    EXPECT_FLOAT_EQ(l2.At(3), 3.3);

    EXPECT_EQ(l2.size(), 4);
    l1.PopBack();
    EXPECT_FLOAT_EQ(l2.At(3), 3.3);
    l1.PopFront();
    EXPECT_FLOAT_EQ(l2.At(0), 4.4);
}

TEST_F(ListTest, ListTest4) {
    List<int> l1 = List<int>();
    EXPECT_EQ(l1.size(), 0);
    EXPECT_EQ(l1.IsEmpty(), true);
}

TEST_F(ListTest, ListTest5) {
    List<std::string> l1 = List<std::string>();
    ASSERT_DEATH(l1.PopFront(), "Out of Bound");
    ASSERT_DEATH(l1.PopBack(), "Out of Bound");

    l1.PushFront("is");
    l1.PushBack("hard");
    l1.PushFront("C++");
    EXPECT_EQ(l1.At(0), "C++");
    EXPECT_EQ(l1.At(1), "is");
    EXPECT_EQ(l1.At(2), "hard");

    List<std::string> l2 = l1;
    EXPECT_EQ(l2.At(0), "C++");
    EXPECT_EQ(l2.At(1), "is");
    EXPECT_EQ(l2.At(2), "hard");
}

TEST_F(StackTest, StackTest1) {
    Stack<int> s1 = Stack<int>(4);

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
    Stack<float> s1 = Stack<float>(3);

    EXPECT_EQ(s1.size(), 0);
    EXPECT_EQ(s1.capacity(), 3);

    s1.Push(3.9);
    s1.Push(2.8);
    s1.Push(1.7);
    s1.Push(0.6);
    
    EXPECT_EQ(s1.size(), 4);
    EXPECT_EQ(s1.capacity(), 7);
    
    EXPECT_FLOAT_EQ(s1.Pop(), 0.6);
    EXPECT_FLOAT_EQ(s1.Pop(), 1.7);
    EXPECT_FLOAT_EQ(s1.Pop(), 2.8);
    EXPECT_FLOAT_EQ(s1.Pop(), 3.9);
}

TEST_F(StackTest, StackTest3) {
    Stack<char> s1 = Stack<char>(2);
    
    s1.Push('a');
    s1.Push('b');
    EXPECT_EQ(s1.Pop(), 'b');
    EXPECT_EQ(s1.Pop(), 'a');

    ASSERT_DEATH(s1.Pop(), "Out of Bound");
}

TEST_F(StackTest, StackTest4) {
    Stack<std::string> s1 = Stack<std::string>(3);

    s1.Push("vector");
    s1.Push("list");
    s1.Push("array");

    EXPECT_EQ(s1.Pop(), "array");
    EXPECT_EQ(s1.Pop(), "list");
    
    s1 = s1;
    Stack<std::string> s2 = s1;
    EXPECT_EQ(s1.Pop(), "vector");
    EXPECT_EQ(s1.size(), 0);
    EXPECT_EQ(s2.size(), 1);
}

TEST_F(StackTest, StackTest5) {
    Stack<int> s1 = Stack<int>(3);
    EXPECT_EQ(s1.IsEmpty(), true);
}

TEST_F(QueueTest, QueueTest1) {
    Queue<int> q1 = Queue<int>();

    q1.Add(1);
    q1.Add(3);
    q1.Add(2);
    q1.Add(4);

    EXPECT_EQ(q1.size(), 4);
}

TEST_F(QueueTest, QueueTest2) {
    Queue<float> q1 = Queue<float>();

    q1.Add(1.1);
    q1.Add(3.3);
    q1.Add(2.2);
    q1.Add(4.4);

    EXPECT_FLOAT_EQ(q1.Poll(), 1.1);
    EXPECT_EQ(q1.size(), 3);

    EXPECT_FLOAT_EQ(q1.Poll(), 3.3);
    EXPECT_EQ(q1.size(), 2);

    EXPECT_FLOAT_EQ(q1.Poll(), 2.2);
    EXPECT_EQ(q1.size(), 1);

    EXPECT_FLOAT_EQ(q1.Poll(), 4.4);
    EXPECT_EQ(q1.size(), 0);

    EXPECT_EQ(q1.IsEmpty(), true);
    ASSERT_DEATH(q1.Poll(), "Out of Bound");
}

TEST_F(QueueTest, QueueTest3) {
    Queue<std::string> q1 = Queue<std::string>();
    
    q1.Add("first");
    q1.Add("second");
    q1.Add("third");

    q1 = q1;
    Queue<std::string> q2 = q1;
    q1.Add("test?");
    EXPECT_EQ(q2.size(), 3);

    EXPECT_EQ(q1.Poll(), "first");
    EXPECT_EQ(q1.Poll(), "second");
    EXPECT_EQ(q1.Poll(), "third"); 
}

TEST_F(QueueTest, QueueTest4) {
    Queue<int> q1 = Queue<int>();
    ASSERT_DEATH(q1.Poll(), "Out of Bound");
}

TEST_F(QueueTest, QueueTest5) {
    Queue<int> q1 = Queue<int>();
    EXPECT_EQ(q1.IsEmpty(), true);
    EXPECT_EQ(q1.size(), 0);
}
