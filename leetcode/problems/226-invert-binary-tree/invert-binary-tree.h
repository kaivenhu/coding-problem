#ifndef INVERT_BINARY_TREE_H_
#define INVERT_BINARY_TREE_H_
#include <coding/tree.h>

namespace invert_tree {

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
    coding::tree::TreeNode*
    invertTree(coding::tree::TreeNode *root);
};

}

#endif /* INVERT_BINARY_TREE_H_ */
