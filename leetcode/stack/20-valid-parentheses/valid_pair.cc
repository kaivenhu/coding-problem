#include <string>

#include "valid_pair.h"

using std::string;

Node::Node(const char t): type_(t), next_(nullptr)
{

}

char Node::GetType(void) const
{
    return type_;
}

void Node::SetNext(Node *n)
{
    next_ = n;
}

Node* Node::GetNext(void) const
{
    return next_;
}

PairStack::~PairStack()
{
    while (nullptr != head_) {
        Pop();
    }
}

void PairStack::Push(const char type)
{
    Node* item = new Node(type);
    item->SetNext(head_);
    head_ = item;
}

void PairStack::Pop(void)
{
    Node* item = head_;
    head_ = item->GetNext();
    delete item;
    item = NULL;
}

bool PairStack::IsPair(const char src, const char dest) const
{
    if (('{' == src && '}' == dest)
        || ('[' == src && ']' == dest)
        || ('(' == src && ')' == dest)) {
        return true;
    } else {
        return false;
    }
}

void PairStack::PushItem(const char type)
{
    if (nullptr == head_
        || !IsPair(head_->GetType(), type)) {
        Push(type);
    } else {
        Pop();
    }
}

bool PairStack::IsEmpty(void) const
{
    return nullptr == head_;
}

bool Solution::isValid(string s)
{
    PairStack pair_stack;
    string::iterator it;

    for (it = s.begin(); it < s.end(); it++) {
        pair_stack.PushItem(*it);
    }
    return pair_stack.IsEmpty();
}
