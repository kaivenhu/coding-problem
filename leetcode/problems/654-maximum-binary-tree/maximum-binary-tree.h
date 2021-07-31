#ifndef MAXIMUM_BINARY_TREE_H_
#define MAXIMUM_BINARY_TREE_H_
#include <vector>
#include <coding/tree.h>

using std::vector;
using namespace coding::tree;

namespace binary
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums);
};

}  // namespace binary

#endif /* MAXIMUM_BINARY_TREE_H_ */
