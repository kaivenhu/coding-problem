#include <vector>

#include "next-greater-element.h"

using std::vector;

namespace solution {

void Solution::CalculateGreaterElemnt(const vector<int>& nums2)
{
    int last_num = -1;
    for (auto &num : nums2) {
        while (!num_stack_.empty()
            && num > (last_num = num_stack_.top())) {
            greater_map_[last_num] = num;
            num_stack_.pop();
        }
        num_stack_.push(num);
    }
}

vector<int> Solution::nextGreaterElement(const vector<int>& nums1,
        const vector<int>& nums2)
{
    vector<int> ans;
    CalculateGreaterElemnt(nums2);
    for (auto &num : nums1) {
        auto iter = greater_map_.find(num);
        if (greater_map_.end() == iter) {
            ans.push_back(-1);
        } else {
            ans.push_back(iter->second);
        }
    }
    return ans;
}

}
