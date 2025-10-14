#ifndef _STRING_NODE_H_
#define _STRING_NODE_H_
#include <iostream>
#include <string>
#include "node.h"

class StringNode : public Node {
    public:
        explicit StringNode(std::string value, const Node* left, const Node* right);
        std::string value() const;
    private:
        const std::string value_;
};

#endif
