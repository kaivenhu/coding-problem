#ifndef SAME_TREE
#define SAME_TREE
#include <coding/tree.h>

namespace same_tree {

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
    bool isSameTree(TreeNode* p, TreeNode* q);
};

}

#endif /* SAME_TREE */
