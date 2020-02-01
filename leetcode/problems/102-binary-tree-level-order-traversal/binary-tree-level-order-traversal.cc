#include <queue>

#include "binary-tree-level-order-traversal.h"

namespace traverse_tree {

using std::queue;

void Solution::levelOrderBase(TreeNode* root, unsigned int level)
{
    if (nullptr == root) {
        return;
    }
    if (ans.size() <= level) {
        vector<int> x;
        x.push_back(root->val);
        ans.push_back(x);
    } else {
        ans[level].push_back(root->val);
    }
    levelOrderBase(root->left, 1 + level);
    levelOrderBase(root->right, 1 + level);
}

vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
    levelOrderBase(root, 0);
    return ans;
}

}
