#include "string_node.h"
#include "node.h"
#include "visitor.h"

StringNode::StringNode(std::string value, Node* left, Node* right) : value_(value), Node(left, right) {}

void StringNode::Visit(Visitor* visitor) {
    visitor->EnterStringNode(this);
    visitor->ExitStringNode(this);
}

std::string StringNode::value() {
    return this->value_;
}
