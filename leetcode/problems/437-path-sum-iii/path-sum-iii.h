#ifndef PATH_SUM_III_H_
#define PATH_SUM_III_H_
#include <unordered_map>

#include <coding/tree.h>

namespace path_sum {

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int ans_;
    std::unordered_map<int, int> pre_sum_;
    void DfsPathSum(
            const coding::tree::TreeNode *root,
            const int &target, const int &path_sum);
public:
    int pathSum(const coding::tree::TreeNode *root, int sum);
    int pathSumBrute(const coding::tree::TreeNode *root, const int &sum);
};

}

#endif /* PATH_SUM_III_H_ */
