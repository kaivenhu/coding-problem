#ifndef FIND_MODE_IN_BINARY_SEARCH_TREE_H_
#define FIND_MODE_IN_BINARY_SEARCH_TREE_H_
#include <vector>

#include <coding/tree.h>

namespace bst_mode {

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
    int nums = 0;
    int cur_nums = 0;
    coding::tree::TreeNode *last_node = nullptr;
    std::vector<int> ans;

    void Inorder(coding::tree::TreeNode *root);
public:
    std::vector<int> findMode(coding::tree::TreeNode *root);
};

}

#endif /* FIND_MODE_IN_BINARY_SEARCH_TREE_H_ */
