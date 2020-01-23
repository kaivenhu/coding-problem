#include "queue-stack.h"

namespace queuestack {

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

Queue::~Queue()
{
    while (head_) {
        PopFront();
    }
    rear_ = nullptr;
}

void Queue::PushBack(int n)
{
    Node *item = new Node(n);
    size_++;
    if (!rear_) {
        head_ = item;
        rear_ = item;
        return;
    }
    rear_->next(item);
    rear_ = item;
}

int Queue::PopFront(void)
{
    int num = 0;
    Node *item = head_;
    if (!head_) {
        return num;
    }
    head_ = head_->next();
    if (!head_) {
        rear_ = nullptr;
    }

    num = item->num();
    delete item;
    size_--;
    return num;
}

int Queue::Peak(void) const
{
    if (head_) {
        return head_->num();
    }
    return 0;
}

bool Queue::IsEmpty(void) const
{
    return nullptr == head_;
}

int Queue::size(void) const
{
    return size_;
}

void MyStack::push(int x)
{
    q_.PushBack(x);
}

int MyStack::pop(void)
{
    int size = q_.size();
    int num = 0;
    for (int i = 0 ; i < (size - 1); i++) {
        num = q_.PopFront();
        q_.PushBack(num);
    }
    return q_.PopFront();
}

int MyStack::top(void)
{
    int size = q_.size();
    int num = 0;
    for (int i = 0 ; i < size; i++) {
        num = q_.PopFront();
        q_.PushBack(num);
    }
    return num;
}

bool MyStack::empty(void) const
{
    return q_.IsEmpty();
}

}
