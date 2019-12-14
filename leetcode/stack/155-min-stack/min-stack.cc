#include "min-stack.h"

Node::Node(int n):
    num_(n), index_(-1),
    next_(nullptr)
{

}

int Node::num(void) const
{
    return num_;
}

int Node::index(void) const
{
    return index_;
}

void Node::index(int i)
{
    index_ = i;
}

void Node::next(Node *n)
{
    next_ = n;
}

Node* Node::next(void) const
{
    return next_;
}

NodeRef::NodeRef(): node_(nullptr)
{

}

NodeRef::NodeRef(Node *n): node_(n)
{

}

int NodeRef::GetNum(void) const
{
    if (!node_) {
        return 0;
    }
    return node_->num();
}

void NodeRef::AdjustIndex(int i)
{
    if (node_) {
        node_->index(i);
    }
}

void Heap::InsertAdjust(int index)
{
    int parent_index = 0;
    if (0 == index) {
        arr_[index].AdjustIndex(index);
        return;
    }
    parent_index = (index - 1) / 2;
    if (arr_[index].GetNum() < arr_[parent_index].GetNum()) {
        auto tmp = arr_[index];
        arr_[index] = arr_[parent_index];
        arr_[parent_index] = tmp;
        arr_[index].AdjustIndex(index);
        InsertAdjust(parent_index);
    } else {
        arr_[index].AdjustIndex(index);
        return;
    }
}

void Heap::Insert(Node *n)
{
    int index = 0;
    arr_.push_back(NodeRef(n));
    index = arr_.size() - 1;
    InsertAdjust(index);
    return;
}

void Heap::DeleteAdjust(int index)
{
    int left_idx = (index + 1) * 2 - 1;
    int right_idx = (index + 1) * 2;
    int compare_idx = 0;
    int size = arr_.size();
    if (left_idx >= size) {
        arr_[index].AdjustIndex(index);
        return;
    } else if (right_idx >= size) {
        compare_idx = left_idx;
    } else if (arr_[left_idx].GetNum() < arr_[right_idx].GetNum()) {
        compare_idx = left_idx;
    } else {
        compare_idx = right_idx;
    }

    if (arr_[index].GetNum() > arr_[compare_idx].GetNum()) {
        auto tmp = arr_[index];
        arr_[index] = arr_[compare_idx];
        arr_[compare_idx] = tmp;
        arr_[index].AdjustIndex(index);
        DeleteAdjust(compare_idx);
    } else {
        arr_[index].AdjustIndex(index);
    }
}

void Heap::Delete(int index)
{
    if (arr_.empty()) {
        return;
    }
    NodeRef lastNode = arr_.back();
    arr_.pop_back();
    arr_[index] = lastNode;
    DeleteAdjust(index);
}

int Heap::Min(void) const
{
    if (!arr_.empty()) {
        return arr_.front().GetNum();
    }
    return 0;
}

MinStack::~MinStack()
{
    while (nullptr != head_) {
        Node* item = head_;
        head_ = item->next();
        delete item;
        item = NULL;
    }
}

void MinStack::push(int num)
{
    Node* item = new Node(num);
    item->next(head_);
    head_ = item;
    heap_.Insert(item);
}

void MinStack::pop(void)
{
    Node* item = head_;
    heap_.Delete(item->index());
    head_ = item->next();
    delete item;
    item = NULL;
}

int MinStack::top() const
{
    if (head_) {
        return head_->num();
    }

    return 0;
}

int MinStack::getMin() const
{
    return heap_.Min();
}
