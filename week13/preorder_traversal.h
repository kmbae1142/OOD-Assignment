#ifndef _PREORDER_TRAVERSAL_H_
#define _PREORDER_TRAVERSAL_H_

#include <iostream>
#include "visitor.h"
#include "int_node.h"
#include "string_node.h"

class PreorderTraversal : public Visitor {
    public:
        void EnterIntNode(IntNode* node) override;
        void ExitIntNode(IntNode* node) override;
        void EnterStringNode(StringNode* node) override;
        void ExitStringNode(StringNode* node) override;
        std::string Result() override;
    private:
        std::string result_;
};

#endif // _PREORDER_TRAVERSAL_H_
