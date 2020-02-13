#include <utility>

#include "invert-binary-tree.h"

namespace invert_tree {

using namespace coding::tree;

TreeNode* Solution::invertTree(TreeNode *root)
{
    if (nullptr != root) {
        using std::swap;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}

}
