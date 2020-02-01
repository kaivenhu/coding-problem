#ifndef BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II
#define BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II
#include <vector>

#include <coding/tree.h>

namespace traverse_tree {

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
    std::vector<std::vector<int>> ans;
    void levelOrderBase(coding::tree::TreeNode* root, unsigned int level);
public:
    std::vector<std::vector<int>>
    levelOrderBottom(coding::tree::TreeNode* root);
};

}

#endif /* BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II */
