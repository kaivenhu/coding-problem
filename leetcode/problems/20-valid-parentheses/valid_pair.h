#ifndef VALID_PAIR_H_
#define VALID_PAIR_H_
#include <string>

using std::string;

class Node;
class PairStack;
class Solution;

class Node {
    char type_;
    Node* next_;
public:
    Node(const char t);
    ~Node() = default;

    char GetType(void) const;
    void SetNext(Node *n);
    Node* GetNext(void) const;
};

class PairStack {
    Node* head_ = nullptr;
    void Push(const char type);
    void Pop(void);
    bool IsPair(const char src, const char dest) const;
public:
    ~PairStack();
    void PushItem(const char type);
    bool IsEmpty(void) const;
};

class Solution {
public:
    bool isValid(string s);
};

#endif /* VALID_PAIR_H_ */
