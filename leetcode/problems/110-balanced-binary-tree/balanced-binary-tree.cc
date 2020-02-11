#include <cstdlib>
#include <algorithm>

#include "balanced-binary-tree.h"

namespace balanced_tree {

using namespace coding::tree;

bool Solution::BalancedBase(TreeNode *root, int *height)
{
    int left = 0;
    int right = 0;
    if (nullptr == root) {
        *height = 0;
        return true;
    }
    if (!BalancedBase(root->left, &left)) {
        return false;
    }
    if (!BalancedBase(root->right, &right)) {
        return false;
    }
    if (abs(left - right) > 1) {
        return false;
    }
    *height = std::max(left, right) + 1;
    return true;
}

bool Solution::isBalanced(TreeNode *root)
{
    int height = 0;
    return BalancedBase(root, &height);
}

}
