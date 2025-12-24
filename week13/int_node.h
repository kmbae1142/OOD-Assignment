#ifndef _INTNODE_H_
#define _INTNODE_H_

#include <iostream>
#include "node.h"

class IntNode : public Node {
    public:
        explicit IntNode(int value, Node* left, Node* right);
        void Visit(Visitor* visitor) override;
        std::string value() override;
    private:
        int value_;
};

#endif // _INTNODE_H_
