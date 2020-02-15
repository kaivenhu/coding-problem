#include <algorithm>

#include "longest-univalue-path.h"

namespace uni_path {

using namespace coding::tree;

static int GetLongestPath(const TreeNode *root,
            int *cur_path)
{
    *cur_path = 0;
    if (!root) {
        return 0;
    }
    int cur = 0;
    int left = 0;
    int right = 0;
    int left_longest = GetLongestPath(root->left, &left);
    if (root->left && root->val == root->left->val) {
        cur += left + 1;
        *cur_path = std::max((*cur_path), left + 1);
    }
    int right_longest = GetLongestPath(root->right, &right);
    if (root->right && root->val == root->right->val) {
        cur += right + 1;
        *cur_path = std::max((*cur_path), right + 1);
    }
    return std::max({cur, left_longest, right_longest});
}

int Solution::longestUnivaluePath(TreeNode *root)
{
    int tmp = 0;
    return GetLongestPath(root, &tmp);
}

}
