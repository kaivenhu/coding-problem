#include <coding/red-black-tree.h>


namespace coding {
namespace tree {

RBTree::~RBTree()
{
    FreeBinaryTree(this->root_);
}

TreeNode* RBTree::root(void) const
{
    return this->root_;
}


/*
 *    X            Y
 *   / \          / \
 *  a   Y   =>   X   r
 *     / \      / \
 *    b   r    a   b
 */
void RBTree::LeftRotation(TreeNode *x)
{
    TreeNode* y = x->right;
    if (nullptr == y) {
        return;
    }
    x->right = y->left;
    if (nullptr != y->left) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (nullptr == x->parent) {
        this->root_ = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

/*
 *      X          Y
 *     / \        / \
 *    Y   r  =>  a   X
 *   / \            / \
 *  a   b          b   r
 */
void RBTree::RightRotation(TreeNode *x)
{
    TreeNode* y = x->left;
    if (nullptr == y) {
        return;
    }
    x->left = y->right;
    if (nullptr != y->right) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (nullptr == x->parent) {
        this->root_ = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

TreeNode* RBTree::AdjustBase(TreeNode *z, bool is_left)
{
    auto rotation_fn =
        ((is_left) ? &RBTree::LeftRotation : &RBTree::RightRotation);
    auto reverse_rotation_fn =
        ((is_left) ? &RBTree::RightRotation : &RBTree::LeftRotation);
    TreeNode *uncle = (is_left) ? z->parent->parent->right
        : z->parent->parent->left;

    if (nullptr != uncle && uncle->is_red) {
        uncle->is_red = false;
        z->parent->is_red = false;
        z->parent->parent->is_red = true;
        z = z->parent->parent;
    // Case 2, 3:
    } else {
        bool is_need_rotate =
            (is_left) ? (z == z->parent->right)
            : (z == z->parent->left);
        if (is_need_rotate) {
            z = z->parent;
            (this->*rotation_fn)(z);
        }
        z->parent->is_red = false;
        z->parent->parent->is_red = true;
        (this->*reverse_rotation_fn)(z->parent->parent);
    }
    return z;
}

void RBTree::AdjustRBTree(TreeNode *z)
{
    while (nullptr != z->parent && z->parent->is_red) {
        if (z->parent == z->parent->parent->left) {
            z = AdjustBase(z, true);
        } else {
            z = AdjustBase(z, false);
        }
    }
    this->root_->is_red = false;
}

void RBTree::Insert(int v)
{
    TreeNode *z = new TreeNode(v);
    if (nullptr == z) {
        return;
    }
    TreeNode *cur = this->root_;
    TreeNode *parent = nullptr;
    while (nullptr != cur) {
        parent = cur;
        if (z->val <= cur->val) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    z->parent = parent;
    if (nullptr == parent) {
        this->root_ = z;
        z->is_red = false;
        return;
    } else if (z->val <= parent->val) {
        parent->left = z;
    } else {
        parent->right = z;
    }
    AdjustRBTree(z);
}


}
}

