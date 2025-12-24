#include <iostream>
#include "node.h"
#include "preorder_traversal.h"
#include "postorder_traversal.h"
#include "visitor.h"
#include "int_node.h"
#include "string_node.h"

using namespace std;

int main() {
    Node* node5 = new StringNode("bye", nullptr, nullptr);
    Node* node4 = new IntNode(0, nullptr, nullptr);
    Node* node3 = new IntNode(-42, node4, node5);
    Node* node2 = new StringNode("hi", nullptr, nullptr);
    Node* node1 = new IntNode(3, node2, node3);

    PreorderTraversal pre = PreorderTraversal();
    PostorderTraversal post = PostorderTraversal();

    node1->Visit(&pre);
    node1->Visit(&post);
    
    cout << pre.Result() << endl;
    cout << post.Result() << endl;
    
}
