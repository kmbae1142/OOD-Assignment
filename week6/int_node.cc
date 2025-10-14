#include "int_node.h"


IntNode::IntNode(int value, const Node* left, const Node* right) : Node(left, right), value_(value) {}

int IntNode::value() const {
    return this->value_;
}
