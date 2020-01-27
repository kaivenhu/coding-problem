#ifndef CODING_TREE_H_
#define CODING_TREE_H_
#include <string>

namespace coding {
namespace tree {

class TreeNode {
public:
    int val;
    bool is_red = true;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode *parent = nullptr;

    TreeNode(int x) : val(x) {};
    ~TreeNode() = default;
};

std::string SerializedBinaryTree(TreeNode *root);
TreeNode* DeserializedBinaryTree(const std::string &data);
void FreeBinaryTree(TreeNode *root);

}
}

#endif /* CODING_TREE_H_ */
