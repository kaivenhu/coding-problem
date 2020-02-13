#include <algorithm>

#include "lowest-common-ancestor-of-a-binary-search-tree.h"

namespace common_ancestor {

using namespace coding::tree;

TreeNode* Solution::lowestCommonAncestorBase(TreeNode *root,
        const int &min_val, const int &max_val)
{
    if (root->val >= min_val && root->val <= max_val) {
        return root;
    } else if (root->val >= max_val) {
        return lowestCommonAncestorBase(root->left, min_val, max_val);
    } else {
        return lowestCommonAncestorBase(root->right, min_val, max_val);
    }
}

TreeNode* Solution::lowestCommonAncestor(TreeNode *root,
        TreeNode *p, TreeNode *q)
{
    return lowestCommonAncestorBase(root,
            std::min(p->val, q->val), std::max(p->val, q->val));
}

}
