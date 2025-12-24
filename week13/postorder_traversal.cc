#include "postorder_traversal.h"
#include "int_node.h"
#include "string_node.h"

void PostorderTraversal::EnterIntNode(IntNode* node) {
    if (node == nullptr) {
        return;
    }

    if (node->left() != nullptr) {
        node->left()->Visit(this); 
    }
    if (node->right() != nullptr) {
        node->right()->Visit(this);
    }

    this->result_ += "(Int " + node->value() + ")::";   
}

void PostorderTraversal::ExitIntNode(IntNode* node) {

}

void PostorderTraversal::EnterStringNode(StringNode* node) {
    if (node == nullptr) {
        return;
    }

    if (node->left() != nullptr) {
        node->left()->Visit(this); 
    }
    if (node->right() != nullptr) {
        node->right()->Visit(this);
    }

    this->result_ += "(String " + node->value() + ")::";
}

void PostorderTraversal::ExitStringNode(StringNode* node) {

}

std::string PostorderTraversal::Result() {
    std::string result = this->result_;
    result.pop_back();
    result.pop_back();
    return result;
}

