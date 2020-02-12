#ifndef MINIMUM_DEPTH_OF_BINARY_TREE_H_
#define MINIMUM_DEPTH_OF_BINARY_TREE_H_
#include <coding/tree.h>

namespace min_tree_depth {

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
    int minDepth(coding::tree::TreeNode *root);
};

}

#endif /* MINIMUM_DEPTH_OF_BINARY_TREE_H_ */
