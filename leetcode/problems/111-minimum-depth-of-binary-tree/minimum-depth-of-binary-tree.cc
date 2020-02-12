#include <algorithm>

#include "minimum-depth-of-binary-tree.h"

namespace min_tree_depth {

using namespace coding::tree;

int Solution::minDepth(TreeNode *root)
{
    int left = 0;
    int right = 0;
    if (nullptr == root) {
        return 0;
    }
    left = minDepth(root->left);
    right = minDepth(root->right);
    if (0 == left) {
        left = right;
    } else if (0 == right) {
        right = left;
    }
    return std::min(left, right) + 1;
}

}
