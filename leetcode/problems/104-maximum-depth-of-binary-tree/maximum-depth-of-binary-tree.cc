#include <algorithm>

#include "maximum-depth-of-binary-tree.h"

namespace tree_depth {

int Solution::maxDepth(TreeNode* root)
{
    if (nullptr == root) {
        return 0;
    } else {
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
}

}
