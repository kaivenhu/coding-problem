#ifndef BINARY_TREE_LEVEL_ORDER_TRAVERSAL
#define BINARY_TREE_LEVEL_ORDER_TRAVERSAL
#include <vector>

#include <coding/tree.h>

namespace traverse_tree {

using std::vector;
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
    vector<vector<int>> ans;
    void levelOrderBase(TreeNode* root, unsigned int level);
public:
    vector<vector<int>> levelOrder(TreeNode* root);
};

}

#endif /* BINARY_TREE_LEVEL_ORDER_TRAVERSAL */
