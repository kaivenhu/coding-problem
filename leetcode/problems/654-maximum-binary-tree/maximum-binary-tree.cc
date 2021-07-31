#include "maximum-binary-tree.h"

#include <stack>
using std::stack;

namespace binary
{

TreeNode* Solution::constructMaximumBinaryTree(vector<int>& nums)
{
    vector<TreeNode*> stk;
    for (unsigned i = 0; i < nums.size(); ++i)
    {
        TreeNode* cur = new TreeNode(nums[i]);
        while (!stk.empty() && stk.back()->val < nums[i])
        {
            cur->left = stk.back();
            stk.pop_back();
        }
        if (!stk.empty())
            stk.back()->right = cur;
        stk.push_back(cur);
    }
    return stk.front();

    /*
    stack<TreeNode *> st;
    TreeNode *prev = nullptr;

    for (const auto x : nums) {
        TreeNode *node = new TreeNode(x);
        prev = nullptr;
        while (!st.empty() && x > st.top()->val) {
            TreeNode *left = st.top();
            st.pop();
            left->right = prev;
            prev = left;
        }
        node->left = prev;
        st.push(node);
    }

    prev = nullptr;
    while (!st.empty()) {
        TreeNode *left = st.top();
        st.pop();
        left->right = prev;
        prev = left;
    }
    return prev;
    */
}

}  // namespace binary
