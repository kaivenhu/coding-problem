#include <string>

#include "symmetric-tree.h"

namespace symmetric_tree {

using std::string;

static string LeftPreorder(TreeNode *root)
{
    if (nullptr == root) {
        return "";
    }
    string s = std::to_string(root->val) + " ";
    s += LeftPreorder(root->left) + " ";
    s += LeftPreorder(root->right) + " ";
    return s;
}

static string RightPreorder(TreeNode *root)
{
    if (nullptr == root) {
        return "";
    }
    string s = std::to_string(root->val) + " ";
    s += RightPreorder(root->right) + " ";
    s += RightPreorder(root->left) + " ";
    return s;
}

bool Solution::isSymmetric(TreeNode *root)
{
    if (nullptr == root) {
        return true;
    }
    return LeftPreorder(root->left) == RightPreorder(root->right);
}


}
