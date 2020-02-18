#include <string>

#include "subtree-of-another-tree.h"

namespace sub_tree {

using namespace coding::tree;
using std::string;

void Preorder(const TreeNode *root, string *tree_path)
{
    if (!root) {
        (*tree_path) += " #,";
        return;
    }
    (*tree_path) += " " + std::to_string(root->val) + ",";
    Preorder(root->left, tree_path);
    Preorder(root->right, tree_path);
}

bool Solution::isSubtree(TreeNode *s, TreeNode *t)
{
    string s_preorder;
    string t_preorder;
    if (!s ^ !t) {
        return false;
    } else if (!s && !t) {
        return true;
    }
    Preorder(s, &s_preorder);
    Preorder(t, &t_preorder);
    if (s_preorder.find(t_preorder) == std::string::npos) {
        return false;
    }
    return true;
}

}
