#include "tree_util.h"
#include "int_node.h"
#include "string_node.h"

int main() {
    
    TreeUtil* tree_util = TreeUtil::GetInstance();

    Node* node7 = new IntNode(7, nullptr, nullptr);
    Node* node6 = new StringNode("FF", nullptr, nullptr);
    Node* node5 = new IntNode(5, node6, node7);
    Node* node4 = new IntNode(4, nullptr, nullptr);
    Node* node3 = new StringNode("CC", nullptr, nullptr);
    Node* node2 = new IntNode(2, node4, node5);
    Node* node1 = new IntNode(1, node2, node3);
    
    std::cout << tree_util->PreOrderTraversal(node1) << '\n';
    std::cout << tree_util->InOrderTraversal(node1) << '\n';
    std::cout << tree_util->PostOrderTraversal(node1) << '\n';
    
    Node* nodeG = new StringNode("GG", nullptr, nullptr);
    Node* nodeF = new StringNode("FF", nullptr, nullptr);
    Node* nodeE = new StringNode("EE", nodeF, nodeG);
    Node* nodeD = new StringNode("DD", nullptr, nullptr);
    Node* nodeC = new StringNode("CC", nullptr, nullptr);
    Node* nodeB = new StringNode("BB", nodeD, nodeE);
    Node* nodeA = new StringNode("AA", nodeB, nodeC);
    
    std::cout << tree_util->PreOrderTraversal(nodeA) << '\n';
    std::cout << tree_util->InOrderTraversal(nodeA) << '\n';
    std::cout << tree_util->PostOrderTraversal(nodeA) << '\n';

    Node* node_1 = new IntNode(1, nullptr, nullptr);
    std::cout << tree_util->PreOrderTraversal(node_1) << '\n';
    std::cout << tree_util->InOrderTraversal(node_1) << '\n';
    std::cout << tree_util->PostOrderTraversal(node_1) << '\n';
}
