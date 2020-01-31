#include <string>
#include <queue>
#include <sstream>

#include <coding/tree.h>

namespace coding {
namespace tree {

using std::queue;
using std::string;
using std::istringstream;


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

TreeNode* DeserializedBinaryTree(const string &data)
{
    istringstream input(data);
    queue<TreeNode **> bfs_queue;
    string t;
    TreeNode *root = nullptr;
    bfs_queue.push(&root);
    while (input >> t) {
        TreeNode **cur = bfs_queue.front();
        if ("#" != t) {
            int val = std::stoi(t);
            *cur = new TreeNode(val);
            bfs_queue.push(&((*cur)->left));
            bfs_queue.push(&((*cur)->right));
        }
        bfs_queue.pop();
    }
    return root;
}

void FreeBinaryTree(TreeNode *root)
{
    queue<TreeNode *> bfs_queue;
    bfs_queue.push(root);
    while (!bfs_queue.empty()) {
        auto cur = bfs_queue.front();
        if (nullptr != cur) {
            if (nullptr != cur->left) {
                bfs_queue.push(cur->left);
            }
            if (nullptr != cur->right) {
                bfs_queue.push(cur->right);
            }
        }
        bfs_queue.pop();
        delete cur;
    }
}

static bool ValidateBst(TreeNode *root, TreeNode *lower, TreeNode *upper)
{
    if (nullptr == root) {
        return true;
    }
    if ((lower && (root->val <= lower->val))
        || (upper && (root->val >= upper->val))) {
        return false;
    }
    return (ValidateBst(root->left, lower, root))
        && (ValidateBst(root->right, root, upper));
}

bool IsValidBst(TreeNode *root)
{
    if (nullptr == root) {
        return true;
    } else {
        return ValidateBst(root, nullptr, nullptr);
    }
}


}
}

