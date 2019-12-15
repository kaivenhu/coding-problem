#include "min-stack-2.h"

namespace minstack_2 {

Node::Node(int n):
    num_(n),
    next_(nullptr)
{

}

int Node::num(void) const
{
    return num_;
}

void Node::next(Node *n)
{
    next_ = n;
}

Node* Node::next(void) const
{
    return next_;
}


MinStack::~MinStack()
{
    while (nullptr != head_) {
        Node* item = head_;
        head_ = item->next();
        delete item;
        item = NULL;
    }
    while (nullptr != min_) {
        Node* item = min_;
        min_ = item->next();
        delete item;
        item = NULL;
    }
}

void MinStack::push(int num)
{
    Node* item = new Node(num);
    item->next(head_);
    head_ = item;
    if (!min_ || num <= min_->num()) {
        Node* new_min = new Node(num);
        new_min->next(min_);
        min_ = new_min;
    }
}

void MinStack::pop(void)
{
    int num;
    Node* item = head_;
    num = item->num();
    head_ = item->next();
    delete item;
    item = NULL;

    if (min_->num() == num) {
        Node* item = min_;
        min_ = item->next();
        delete item;
        item = NULL;
    }
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
    if (min_) {
        return min_->num();
    }
    return 0;
}

}
