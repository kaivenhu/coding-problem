#ifndef QUEUE_STACK_H_
#define QUEUE_STACK_H_

namespace queuestack {

class Node;

class Node {
    int num_;
    Node* next_;
public:
    Node(int n);
    ~Node() = default;

    int num(void) const;
    void next(Node *n);
    Node* next(void) const;
};

class Queue {
    Node* head_ = nullptr;
    Node* rear_ = nullptr;
    int size_ = 0;
public:
    Queue() = default;
    ~Queue();
    void PushBack(int n);
    int PopFront(void);
    int Peak(void) const;
    bool IsEmpty(void) const;
    int size(void) const;
};

class MyStack {
    Queue q_;
public:
    /** Initialize your data structure here. */
    MyStack() = default;
    ~MyStack() = default;
    /** Push element x onto stack. */
    void push(int x);
    /** Removes the element on top of the stack and returns that element. */
    int pop(void);
    /** Get the top element. */
    int top(void);
    /** Returns whether the stack is empty. */
    bool empty(void) const;
};

}

#endif /* QUEUE_STACK_H_ */
