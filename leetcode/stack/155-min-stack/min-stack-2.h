#ifndef MIN_STACK_2_H_
#define MIN_STACK_2_H_
#include <vector>

namespace minstack_2 {

using std::vector;

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

class MinStack {
    Node* head_ = nullptr;
    Node* min_ = nullptr;
public:
    /** initialize your data structure here. */
    MinStack() = default;
    ~MinStack();

    void push(int x);

    void pop(void);

    int top(void) const;

    int getMin(void) const;
};

}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#endif /* MIN_STACK_2_H_ */
