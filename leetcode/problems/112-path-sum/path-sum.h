#ifndef PATH_SUM_H_
#define PATH_SUM_H_
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
public:
    bool hasPathSum(coding::tree::TreeNode* root, const int &sum);
};

}

#endif /* PATH_SUM_H_ */
