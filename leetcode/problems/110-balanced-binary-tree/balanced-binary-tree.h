#ifndef BALANCED_BINARY_TREE_H_
#define BALANCED_BINARY_TREE_H_
#include <coding/tree.h>

namespace balanced_tree {

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
    bool BalancedBase(coding::tree::TreeNode *root, int *height);
public:
    bool isBalanced(coding::tree::TreeNode *root);
};

}

#endif /* BALANCED_BINARY_TREE_H_ */
