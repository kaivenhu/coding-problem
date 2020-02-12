#include "path-sum.h"

namespace path_sum {

using namespace coding::tree;

bool Solution::hasPathSum(TreeNode* root, const int &sum)
{
    if (nullptr == root) {
        return false;
    } else if (nullptr == root->left && nullptr == root->right) {
        return (0 == sum - root->val);
    } else {
        return hasPathSum(root->left, sum - root->val)
            || hasPathSum(root->right, sum - root->val);
    }
}

}
