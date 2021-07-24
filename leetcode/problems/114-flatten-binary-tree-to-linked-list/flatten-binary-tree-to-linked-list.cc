#include "flatten-binary-tree-to-linked-list.h"

namespace flatten
{

static TreeNode *helper(TreeNode *node)
{
    if (!node)
        return nullptr;
    if (!node->right && !node->left)
        return node;
    auto x = helper(node->left);
    auto y = helper(node->right);
    if (x) {
        x->right = node->right;
        node->right = node->left;
        node->left = nullptr;
    }
    if (!y)
        y = x;
    return y;
}

void Solution::flatten(TreeNode* root)
{
    helper(root);
}

}  // namespace flatten
