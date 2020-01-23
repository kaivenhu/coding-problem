#ifndef NEXT_GREATER_ELEMENT_H_
#define NEXT_GREATER_ELEMENT_H_
#include <map>
#include <vector>
#include <stack>

using std::vector;

namespace solution {

class Solution {
    std::map<int, int> greater_map_;
    std::stack<int> num_stack_;
    void CalculateGreaterElemnt(const vector<int>& nums2);
public:
    Solution() = default;
    ~Solution() = default;
    vector<int> nextGreaterElement(const vector<int>& nums1,
            const vector<int>& nums2);
};

}

#endif /* NEXT_GREATER_ELEMENT_H_ */
