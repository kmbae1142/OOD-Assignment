#include "gtest/gtest.h"
#include "tree_util.h"
#include "int_node.h"
#include "string_node.h"


class TreeUtilTest : public :: testing::Test {
    protected:
        void SetUp() override {}
        void TearDown() override {}
};

TEST_F(TreeUtilTest, PreOrderTraversalTest1) {
    TreeUtil* tree_util = TreeUtil::GetInstance();
    Node* node_3 = new IntNode(3, nullptr, nullptr);
    Node* node_2 = new IntNode(2, nullptr, nullptr);
    Node* node_1 = new IntNode(1, node_2, node_3);

    std::string result = tree_util->PreOrderTraversal(node_1);
    EXPECT_EQ(result, "1,2,3");
}

TEST_F(TreeUtilTest, PreOrderTraversalTest2) {
    TreeUtil* tree_util = TreeUtil::GetInstance();
    Node* node_7 = new IntNode(7, nullptr, nullptr);
    Node* node_6 = new IntNode(6, nullptr, nullptr);
    Node* node_5 = new IntNode(5, node_6, node_7);
    Node* node_4 = new IntNode(4, nullptr, nullptr);
    Node* node_3 = new IntNode(3, nullptr, nullptr);
    Node* node_2 = new IntNode(2, node_4, node_5);
    Node* node_1 = new IntNode(1, node_2, node_3);

    std::string result = tree_util->PreOrderTraversal(node_1);
    EXPECT_EQ(result, "1,2,4,5,6,7,3");
}

TEST_F(TreeUtilTest, PreOrderTraversalTest3) {
    TreeUtil* tree_util = TreeUtil::GetInstance();
    Node* nodeG = new StringNode("G", nullptr, nullptr);
    Node* nodeF = new StringNode("F", nullptr, nullptr);
    Node* nodeE = new StringNode("E", nodeF, nodeG);
    Node* nodeD = new StringNode("D", nullptr, nullptr);
    Node* nodeC = new StringNode("C", nullptr, nullptr);
    Node* nodeB = new StringNode("B", nodeD, nodeE);
    Node* nodeA = new StringNode("A", nodeB, nodeC);
    
    std::string result = tree_util->PreOrderTraversal(nodeA);
    EXPECT_EQ(result, "A,B,D,E,F,G,C");
}

TEST_F(TreeUtilTest, InOrderTraversalTest1) {
    TreeUtil* tree_util = TreeUtil::GetInstance();
    Node* node_3 = new IntNode(3, nullptr, nullptr);
    Node* node_2 = new IntNode(2, nullptr, nullptr);
    Node* node_1 = new IntNode(1, node_2, node_3);

    std::string result = tree_util->InOrderTraversal(node_1);
    EXPECT_EQ(result, "2,1,3");
}

TEST_F(TreeUtilTest, InOrderTraversalTest2) {
    TreeUtil* tree_util = TreeUtil::GetInstance();
    Node* node_7 = new IntNode(7, nullptr, nullptr);
    Node* node_6 = new IntNode(6, nullptr, nullptr);
    Node* node_5 = new IntNode(5, node_6, node_7);
    Node* node_4 = new IntNode(4, nullptr, nullptr);
    Node* node_3 = new IntNode(3, nullptr, nullptr);
    Node* node_2 = new IntNode(2, node_4, node_5);
    Node* node_1 = new IntNode(1, node_2, node_3);

    std::string result = tree_util->InOrderTraversal(node_1);
    EXPECT_EQ(result, "4,2,6,5,7,1,3");
}

TEST_F(TreeUtilTest, InOrderTraversalTest3) {
    TreeUtil* tree_util = TreeUtil::GetInstance();
    Node* nodeG = new StringNode("G", nullptr, nullptr);
    Node* nodeF = new StringNode("F", nullptr, nullptr);
    Node* nodeE = new StringNode("E", nodeF, nodeG);
    Node* nodeD = new StringNode("D", nullptr, nullptr);
    Node* nodeC = new StringNode("C", nullptr, nullptr);
    Node* nodeB = new StringNode("B", nodeD, nodeE);
    Node* nodeA = new StringNode("A", nodeB, nodeC);
    
    std::string result = tree_util->InOrderTraversal(nodeA);
    EXPECT_EQ(result, "D,B,F,E,G,A,C");
}

TEST_F(TreeUtilTest, PostOrderTraversalTest1) {
    TreeUtil* tree_util = TreeUtil::GetInstance();
    Node* node_3 = new IntNode(3, nullptr, nullptr);
    Node* node_2 = new IntNode(2, nullptr, nullptr);
    Node* node_1 = new IntNode(1, node_2, node_3);

    std::string result = tree_util->PostOrderTraversal(node_1);
    EXPECT_EQ(result, "2,3,1");
}

TEST_F(TreeUtilTest, PostOrderTraversalTest2) {
    TreeUtil* tree_util = TreeUtil::GetInstance();
    Node* node_7 = new IntNode(7, nullptr, nullptr);
    Node* node_6 = new IntNode(6, nullptr, nullptr);
    Node* node_5 = new IntNode(5, node_6, node_7);
    Node* node_4 = new IntNode(4, nullptr, nullptr);
    Node* node_3 = new IntNode(3, nullptr, nullptr);
    Node* node_2 = new IntNode(2, node_4, node_5);
    Node* node_1 = new IntNode(1, node_2, node_3);

    std::string result = tree_util->PostOrderTraversal(node_1);
    EXPECT_EQ(result, "4,6,7,5,2,3,1");
}

TEST_F(TreeUtilTest, PostOrderTraversalTest3) {
    TreeUtil* tree_util = TreeUtil::GetInstance();
    Node* nodeG = new StringNode("G", nullptr, nullptr);
    Node* nodeF = new StringNode("F", nullptr, nullptr);
    Node* nodeE = new StringNode("E", nodeF, nodeG);
    Node* nodeD = new StringNode("D", nullptr, nullptr);
    Node* nodeC = new StringNode("C", nullptr, nullptr);
    Node* nodeB = new StringNode("B", nodeD, nodeE);
    Node* nodeA = new StringNode("A", nodeB, nodeC);
    
    std::string result = tree_util->PostOrderTraversal(nodeA);
    EXPECT_EQ(result, "D,F,G,E,B,C,A");
}
