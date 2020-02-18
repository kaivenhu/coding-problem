#ifndef SUBTREE_OF_ANOTHER_TREE_H_
#define SUBTREE_OF_ANOTHER_TREE_H_
#include <coding/tree.h>

namespace sub_tree {

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
    bool isSubtree(coding::tree::TreeNode *s,
            coding::tree::TreeNode *t);
};

}

#endif /* SUBTREE_OF_ANOTHER_TREE_H_ */
