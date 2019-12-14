#ifndef MIN_STACK_H_
#define MIN_STACK_H_
#include <vector>

using std::vector;

class Node {
    int num_;
    int index_;
    Node* next_;
public:
    Node(int n);
    ~Node() = default;

    int num(void) const;
    int index(void) const;
    void index(int i);
    void next(Node *n);
    Node* next(void) const;
};

class NodeRef {
    Node* node_;
public:
    NodeRef();
    NodeRef(Node* n);
    int GetNum(void) const;
    void AdjustIndex(int i);
};

class Heap {
    vector<NodeRef> arr_;
    void InsertAdjust(int index);
    void DeleteAdjust(int index);
public:
    Heap() = default;
    ~Heap() = default;
    void Insert(Node *n);
    void Delete(int index);
    int Min(void) const;
};

class MinStack {
    Node* head_ = nullptr;
    Heap heap_;
public:
    /** initialize your data structure here. */
    MinStack() = default;
    ~MinStack();

    void push(int x);

    void pop(void);

    int top(void) const;

    int getMin(void) const;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#endif /* MIN_STACK_H_ */
