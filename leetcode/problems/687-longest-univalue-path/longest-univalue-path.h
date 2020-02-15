#ifndef LONGEST_UNIVALUE_PATH_H_
#define LONGEST_UNIVALUE_PATH_H_
#include <coding/tree.h>

namespace uni_path {

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
    int longestUnivaluePath(coding::tree::TreeNode *root);
};

}

#endif /* LONGEST_UNIVALUE_PATH_H_ */
