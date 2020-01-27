#include <coding/tree.h>

#include "same-tree.h"

namespace same_tree {

bool Solution::isSameTree(TreeNode* p, TreeNode* q)
{
    if (SerializedBinaryTree(p) == SerializedBinaryTree(q)) {
        return true;
    } else {
        return false;
    }
}

}
