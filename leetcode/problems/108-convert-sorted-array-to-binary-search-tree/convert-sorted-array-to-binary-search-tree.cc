#include "convert-sorted-array-to-binary-search-tree.h"

namespace convert_tree {

using namespace coding::tree;
using std::vector;

void Solution::CreateSubRoot(const vector<int> &nums,
        TreeNode **root, int min_idx, int max_idx)
{
    if (min_idx < max_idx) {
        int middle_idx = (min_idx + max_idx) / 2;
        (*root) = new TreeNode(nums[middle_idx]);
        CreateSubRoot(nums, &((*root)->left), min_idx, middle_idx);
        CreateSubRoot(nums, &((*root)->right), middle_idx + 1, max_idx);
    }
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &nums)
{
    TreeNode *root = nullptr;
    CreateSubRoot(nums, &root, 0, nums.size());
    return root;
}

}
