#include "find-mode-in-binary-search-tree.h"

namespace bst_mode {

using namespace coding::tree;
using std::vector;

void Solution::Inorder(TreeNode *root)
{
    if (nullptr == root) {
        return;
    }
    Inorder(root->left);
    if (last_node && root->val == last_node->val) {
        ++cur_nums;
    } else {
        cur_nums = 1;
    }
    if (cur_nums == nums) {
        ans.push_back(root->val);
    } else if (cur_nums > nums) {
        ans.clear();
        ans.push_back(root->val);
        nums = cur_nums;
    }
    last_node = root;
    Inorder(root->right);
}

vector<int> Solution::findMode(TreeNode *root)
{
    Inorder(root);
    return ans;
}

}
