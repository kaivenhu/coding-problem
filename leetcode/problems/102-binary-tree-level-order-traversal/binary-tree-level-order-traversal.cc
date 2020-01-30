#include <queue>

#include "binary-tree-level-order-traversal.h"

namespace traverse_tree {

using std::queue;

vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
    vector<int> level_list;
    vector<vector<int>> ans_list;
    queue<TreeNode *> bfs_queue;
    bool is_next_level = true;

    if (nullptr == root) {
        return ans_list;
    }
    bfs_queue.push(root);
    while (!bfs_queue.empty()) {
        TreeNode *cur = bfs_queue.front();
        if (nullptr == cur) {
            ans_list.push_back(level_list);
            level_list.clear();
            is_next_level = true;
        } else {
            level_list.push_back(cur->val);
            if (nullptr != cur->left) {
                if (is_next_level) {
                    is_next_level = false;
                    bfs_queue.push(nullptr);
                }
                bfs_queue.push(cur->left);
            }
            if (nullptr != cur->right) {
                if (is_next_level) {
                    is_next_level = false;
                    bfs_queue.push(nullptr);
                }
                bfs_queue.push(cur->right);
            }
        }
        bfs_queue.pop();
    }
    ans_list.push_back(level_list);
    return ans_list;
}

}
