#include <string>
#include <queue>

#include <coding/tree.h>

namespace coding {
namespace tree {

using std::queue;
using std::string;


string SerializedBinaryTree(TreeNode *root)
{
    queue<TreeNode *> bfs_queue;
    string ans;
    bfs_queue.push(root);
    while (!bfs_queue.empty()) {
        auto cur = bfs_queue.front();
        if (nullptr == cur) {
            ans += "# ";
        } else {
            bfs_queue.push(cur->left);
            bfs_queue.push(cur->right);
            ans += std::to_string(cur->val) + " ";
        }
        bfs_queue.pop();
    }
    return ans;
}

void FreeBinaryTree(TreeNode *root)
{
    queue<TreeNode *> bfs_queue;
    bfs_queue.push(root);
    while (!bfs_queue.empty()) {
        auto cur = bfs_queue.front();
        if (nullptr != cur->left) {
            bfs_queue.push(cur->left);
        }
        if (nullptr != cur->right) {
            bfs_queue.push(cur->right);
        }
        bfs_queue.pop();
        delete cur;
    }
}


}
}

