#include "int_node.h"

IntNode::IntNode(int value, Node* left, Node* right) : value_(value), Node(left, right) {}

void IntNode::Visit(Visitor* visitor) {
    visitor->EnterIntNode(this);
    visitor->ExitIntNode(this);
}

std::string IntNode::value() {
    return std::to_string(this->value_);
}
