#include <queue>

#include "binary-tree-level-order-traversal-II.h"

namespace traverse_tree {

using std::queue;
using std::vector;
using namespace coding::tree;

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

vector<vector<int>> Solution::levelOrderBottom(TreeNode* root)
{
    levelOrderBase(root, 0);
    vector<vector<int>> ret(ans.rbegin(), ans.rend());
    return ret;
}

}
