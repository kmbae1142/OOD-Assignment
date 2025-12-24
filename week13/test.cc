#include "gtest/gtest.h"
#include "int_node.h"
#include "string_node.h"
#include "visitor.h"
#include "preorder_traversal.h"
#include "postorder_traversal.h"

class PreorderTraversalTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

class PostorderTraversalTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

TEST_F(PreorderTraversalTest, PreorderTraversalTest1) {
    Node* node5 = new StringNode("bye", nullptr, nullptr);
    Node* node4 = new IntNode(0, nullptr, nullptr);
    Node* node3 = new IntNode(-42, node4, node5);
    Node* node2 = new StringNode("hi", nullptr, nullptr);
    Node* node1 = new IntNode(3, node2, node3);

    PreorderTraversal pre = PreorderTraversal();

    node1->Visit(&pre);

    EXPECT_EQ(pre.Result(), "(Int 3)::(String hi)::(Int -42)::(Int 0)::(String bye)");
}

TEST_F(PreorderTraversalTest, PreorderTraversalTest2) {
    Node* node3 = new StringNode("bye", nullptr, nullptr);
    Node* node2 = new IntNode(1, nullptr, nullptr);
    Node* node1 = new StringNode("start", node2, node3);

    PreorderTraversal pre = PreorderTraversal();

    node1->Visit(&pre);

    EXPECT_EQ(pre.Result(), "(String start)::(Int 1)::(String bye)");
}

TEST_F(PreorderTraversalTest, PreorderTraversalTest3) {
    Node* node1 = new StringNode("start", nullptr, nullptr);

    PreorderTraversal pre = PreorderTraversal();

    node1->Visit(&pre);

    EXPECT_EQ(pre.Result(), "(String start)");
}

TEST_F(PreorderTraversalTest, PreorderTraversalTest4) {
    Node* node7 = new StringNode("bye", nullptr, nullptr);
    Node* node6 = new IntNode(5, nullptr, nullptr);
    Node* node5 = new IntNode(4, nullptr, nullptr);
    Node* node4 = new IntNode(3, nullptr, nullptr);
    Node* node3 = new IntNode(2, node6, node7);
    Node* node2 = new IntNode(1, node4, node5);
    Node* node1 = new StringNode("hi", node2, node3);

    PreorderTraversal pre = PreorderTraversal();

    node1->Visit(&pre);

    EXPECT_EQ(pre.Result(), "(String hi)::(Int 1)::(Int 3)::(Int 4)::(Int 2)::(Int 5)::(String bye)");
}

TEST_F(PreorderTraversalTest, PreorderTraversalTest5) {
    Node* node3 = new IntNode(1, nullptr, nullptr);
    Node* node2 = new IntNode(2, node3, nullptr);
    Node* node1 = new IntNode(3, node2, nullptr);

    PreorderTraversal pre = PreorderTraversal();

    node1->Visit(&pre);

    EXPECT_EQ(pre.Result(), "(Int 3)::(Int 2)::(Int 1)");
}

TEST_F(PostorderTraversalTest, PostorderTraversalTest1) {
    Node* node5 = new StringNode("bye", nullptr, nullptr);
    Node* node4 = new IntNode(0, nullptr, nullptr);
    Node* node3 = new IntNode(-42, node4, node5);
    Node* node2 = new StringNode("hi", nullptr, nullptr);
    Node* node1 = new IntNode(3, node2, node3);

    PostorderTraversal post = PostorderTraversal();

    node1->Visit(&post);

    EXPECT_EQ(post.Result(), "(String hi)::(Int 0)::(String bye)::(Int -42)::(Int 3)");
}

TEST_F(PostorderTraversalTest, PostorderTraversalTest2) {
    Node* node3 = new StringNode("bye", nullptr, nullptr);
    Node* node2 = new IntNode(1, nullptr, nullptr);
    Node* node1 = new StringNode("start", node2, node3);

    PostorderTraversal post = PostorderTraversal();

    node1->Visit(&post);

    EXPECT_EQ(post.Result(), "(Int 1)::(String bye)::(String start)");
}

TEST_F(PostorderTraversalTest, PostorderTraversalTest3) {
    Node* node1 = new StringNode("start", nullptr, nullptr);

    PostorderTraversal post = PostorderTraversal();

    node1->Visit(&post);

    EXPECT_EQ(post.Result(), "(String start)");
}

TEST_F(PostorderTraversalTest, PostorderTraversalTest4) {
    Node* node7 = new StringNode("bye", nullptr, nullptr);
    Node* node6 = new IntNode(5, nullptr, nullptr);
    Node* node5 = new IntNode(4, nullptr, nullptr);
    Node* node4 = new IntNode(3, nullptr, nullptr);
    Node* node3 = new IntNode(2, node6, node7);
    Node* node2 = new IntNode(1, node4, node5);
    Node* node1 = new StringNode("hi", node2, node3);

    PostorderTraversal post = PostorderTraversal();

    node1->Visit(&post);

    EXPECT_EQ(post.Result(), "(Int 3)::(Int 4)::(Int 1)::(Int 5)::(String bye)::(Int 2)::(String hi)");
}

TEST_F(PostorderTraversalTest, PostorderTraversalTest5) {
    Node* node3 = new IntNode(1, nullptr, nullptr);
    Node* node2 = new IntNode(2, node3, nullptr);
    Node* node1 = new IntNode(3, node2, nullptr);

    PostorderTraversal post = PostorderTraversal();

    node1->Visit(&post);

    EXPECT_EQ(post.Result(), "(Int 1)::(Int 2)::(Int 3)");
}


