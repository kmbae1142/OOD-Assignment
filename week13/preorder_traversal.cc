#include "preorder_traversal.h"

void PreorderTraversal::EnterIntNode(IntNode* node) {
    if (node == nullptr) {
        return;
    }

    this->result_ += "(Int " + node->value() + ")::";

    if (node->left() != nullptr) {
        node->left()->Visit(this); 
    }
    if (node->right() != nullptr) {
        node->right()->Visit(this);
    }
}

void PreorderTraversal::ExitIntNode(IntNode* node) {

}

void PreorderTraversal::EnterStringNode(StringNode* node) {
    if (node == nullptr) {
        return;
    }

    this->result_ += "(String " + node->value() + ")::";

    if (node->left() != nullptr) {
        node->left()->Visit(this); 
    }
    if (node->right() != nullptr) {
        node->right()->Visit(this);
    }
}

void PreorderTraversal::ExitStringNode(StringNode* node) {

}

std::string PreorderTraversal::Result() {
    std::string result = this->result_;
    result.pop_back();
    result.pop_back();
    return result;
}
