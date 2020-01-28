#ifndef MAXIMUM_DEPTH_OF_BINARY_TREE
#define MAXIMUM_DEPTH_OF_BINARY_TREE
#include <coding/tree.h>

namespace tree_depth {

using namespace coding::tree;
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
    int maxDepth(TreeNode* root);
};

}

#endif /* MAXIMUM_DEPTH_OF_BINARY_TREE */
