#ifndef _TREE_UTIL_H_
#define _TREE_UTIL_H_

#include "node.h"

class TreeUtil {
    public:
        static TreeUtil* GetInstance();
        std::string PreOrderTraversal(const Node* node) const;
        std::string InOrderTraversal(const Node* node) const;
        std::string PostOrderTraversal(const Node* node) const;
    private:
        TreeUtil();
        static TreeUtil* instance_;
};

#endif
