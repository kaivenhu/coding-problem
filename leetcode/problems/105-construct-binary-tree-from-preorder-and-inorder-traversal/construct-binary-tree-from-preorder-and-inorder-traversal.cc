#include <unordered_map>

#include "construct-binary-tree-from-preorder-and-inorder-traversal.h"

using std::unordered_map;

namespace order
{

static TreeNode *build(const vector<int>& preorder,
                       const unordered_map<int, int> &m,
                       int *root_idx, int left, int right)
{
    int pivot;
    TreeNode *node = nullptr;

    if (left > right)
        return nullptr;

    pivot = m.at(preorder[*root_idx]);
    node = new TreeNode(preorder[*root_idx]);

    (*root_idx)++;
    node->left = build(preorder, m, root_idx, left, pivot - 1);
    node->right = build(preorder, m, root_idx, pivot + 1, right);
    return node;
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder)
{
    int root_idx = 0;
    unordered_map<int, int> m;

    for (unsigned int i = 0; i < inorder.size(); i++)
        m[inorder[i]] = i;
    return build(preorder, m, &root_idx, 0, inorder.size() - 1);
}

/*
static TreeNode *build(vector<int>& preorder, vector<int>& inorder,
                       int *root_idx, int left, int right)
{
    int pivot = left;
    TreeNode *node = nullptr;

    if (left > right)
        return nullptr;

    while (inorder[pivot] != preorder[*root_idx])
        pivot++;

    (*root_idx)++;

    node = new TreeNode(inorder[pivot]);
    node->left = build(preorder, inorder, root_idx, left, pivot - 1);
    node->right = build(preorder, inorder, root_idx, pivot + 1, right);
    return node;
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder)
{
    int root_idx = 0;
    return build(preorder, inorder, &root_idx, 0, inorder.size() - 1);
}
*/

}  // namespace order
