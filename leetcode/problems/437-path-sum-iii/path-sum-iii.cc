#include <stack>

#include "path-sum-iii.h"

namespace path_sum {

using coding::tree::TreeNode;

void Solution::DfsPathSum(const TreeNode *root,
        const int &target, const int &path_sum)
{
    if (!root) {
        return;
    }
    int cur_sum = path_sum + root->val;
    ans_ += pre_sum_[cur_sum - target];
    ++pre_sum_[cur_sum];
    DfsPathSum(root->left, target, cur_sum);
    DfsPathSum(root->right, target, cur_sum);
    --pre_sum_[cur_sum];
}

int Solution::pathSum(const TreeNode *root, int sum)
{
    ans_ = 0;
    pre_sum_ = {{0, 1}};
    DfsPathSum(root, sum, 0);
    return ans_;
}

namespace {

int getPathSum(const TreeNode *root, const int &target, const int &path_sum)
{
    if (!root) {
        return 0;
    }
    int val = path_sum + root->val;
    return getPathSum(root->left, target, val) +
        getPathSum(root->right, target, val) +
        ((val == target) ? 1 : 0);
}

}

int Solution::pathSumBrute(const TreeNode *root, const int &sum)
{
    int num = 0;
    std::stack<const TreeNode *> bfs;
    bfs.push(root);

    while (!bfs.empty()) {
        auto cur = bfs.top();
        bfs.pop();
        if (cur) {
            bfs.push(cur->left);
            bfs.push(cur->right);
            num += getPathSum(cur, sum, 0);
        }
    }
    return num;
}

}
