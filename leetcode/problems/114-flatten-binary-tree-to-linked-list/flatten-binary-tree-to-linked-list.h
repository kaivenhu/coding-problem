#ifndef FLATTEN_BINARY_TREE_TO_LINKED_LIST_H_
#define FLATTEN_BINARY_TREE_TO_LINKED_LIST_H_
#include <coding/tree.h>

using namespace coding::tree;

namespace flatten
{

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root);
};

}  // namespace flatten

#endif /* FLATTEN_BINARY_TREE_TO_LINKED_LIST_H_ */
