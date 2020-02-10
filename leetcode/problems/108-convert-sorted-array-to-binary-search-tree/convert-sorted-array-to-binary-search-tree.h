#ifndef CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H_
#define CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H_
#include <vector>

#include <coding/tree.h>

namespace convert_tree {

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
    void CreateSubRoot(const std::vector<int> &nums,
        coding::tree::TreeNode **root, int min_idx, int max_idx);
public:
    coding::tree::TreeNode* sortedArrayToBST(const std::vector<int> &nums);
};

}

#endif /* CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H_ */
