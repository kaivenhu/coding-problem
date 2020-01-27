#ifndef CODING_RED_BLACK_TREE_H_
#define CODING_RED_BLACK_TREE_H_

#include <coding/tree.h>

namespace coding {
namespace tree {

class RBTree {
    TreeNode *root_ = nullptr;
    void LeftRotation(TreeNode *z);
    void RightRotation(TreeNode *z);
    TreeNode* AdjustBase(TreeNode *z, bool is_left);
    void AdjustRBTree(TreeNode *z);
public:
    RBTree() = default;
    ~RBTree();
    TreeNode* root(void) const;

    void Insert(int val);
    bool IsExistVal(const int val) const;
};

}
}

#endif /* CODING_RED_BLACK_TREE_H_ */
