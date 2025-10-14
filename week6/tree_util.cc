#include "tree_util.h"
#include "int_node.h"
#include "string_node.h"

TreeUtil* TreeUtil::instance_ = nullptr;

TreeUtil::TreeUtil() {}

TreeUtil* TreeUtil::GetInstance() {
    if (instance_ == NULL) {
        instance_ = new TreeUtil;
    }
    return instance_;
}

std::string TreeUtil::PreOrderTraversal(const Node* node) const {
    if (node == nullptr) { return ""; }

    std::string result;
    std::string left_result;
    std::string right_result;
    
    if (const IntNode* int_node = dynamic_cast<const IntNode*>(node)) {
        result += std::to_string(int_node->value());    
    }
    else if (const StringNode* string_node = dynamic_cast<const StringNode*>(node)) {
        result += string_node->value();
    }
    
    left_result = this->PreOrderTraversal(node->left());
    right_result = this->PreOrderTraversal(node->right());

    if (!left_result.empty()) { result += ','; }
    result += left_result;
    
    if (!right_result.empty()) { result += ','; }
    result += right_result;
    
    return result;
}

std::string TreeUtil::InOrderTraversal(const Node* node) const {
    if (node == nullptr) { return ""; }

    std::string result;
    std::string left_result;
    std::string right_result;

    result += this->InOrderTraversal(node->left());
    
    if (const IntNode* int_node = dynamic_cast<const IntNode*>(node)) {
        left_result = std::to_string(int_node->value());    
    }
    else if (const StringNode* string_node = dynamic_cast<const StringNode*>(node)) {
        left_result = string_node->value();
    }

    if (!result.empty()) { result += ','; }
    result += left_result;
    
    right_result = this->InOrderTraversal(node->right());
    
    if (!right_result.empty()) { result += ','; }
    result += right_result;
    
    return result;
}

std::string TreeUtil::PostOrderTraversal(const Node* node) const {
    if (node == nullptr) { return ""; }

    std::string result;
    std::string left_result;
    std::string right_result;

    left_result = this->PostOrderTraversal(node->left());
    right_result = this->PostOrderTraversal(node->right());
    
    result += left_result;
    if (!left_result.empty()) { result += ','; }
    
    result += right_result;
    if (!right_result.empty()) { result += ','; }
    
    if (const IntNode* int_node = dynamic_cast<const IntNode*>(node)) {
        result += std::to_string(int_node->value());    
    }
    else if (const StringNode* string_node = dynamic_cast<const StringNode*>(node)) {
        result += string_node->value();
    }

    return result;
}


