#include "tree_util.h"


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

    result += node->value();
    
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
   
    left_result = node->value();

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
    
    result += node->value();

    return result;
}


