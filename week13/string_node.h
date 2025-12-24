#ifndef _STRINGNODE_H_
#define _STRINGNODE_H_

#include <iostream>
#include "node.h"

class StringNode : public Node {
    public:
        explicit StringNode(std::string value, Node* left, Node* right);
        void Visit(Visitor* visitor) override;
        std::string value() override;
    private:
        std::string value_;
};

#endif // _STRINGNODE_H_
