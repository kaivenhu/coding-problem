#ifndef SYMMETRIC_TREE
#define SYMMETRIC_TREE
#include <coding/tree.h>

namespace symmetric_tree {

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
    bool isSymmetric(TreeNode* root);
};


}

#endif /* SYMMETRIC_TREE */
