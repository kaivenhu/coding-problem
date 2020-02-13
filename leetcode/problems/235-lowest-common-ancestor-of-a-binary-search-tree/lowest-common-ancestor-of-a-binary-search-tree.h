#ifndef LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H_
#define LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H_
#include <coding/tree.h>

namespace common_ancestor {

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
    lowestCommonAncestorBase(coding::tree::TreeNode *root,
            const int &min_val, const int &max_val);

    coding::tree::TreeNode*
    lowestCommonAncestor(coding::tree::TreeNode *root,
            coding::tree::TreeNode *p,
            coding::tree::TreeNode *q);

};

}

#endif /* LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H_ */
