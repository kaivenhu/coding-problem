#ifndef MAJORITY_ELEMENT_H_
#define MAJORITY_ELEMENT_H_
#include <vector>

namespace major_elem {

class Solution {
    size_t MergeSubArrayMajor(const std::vector<int> &nums,
        size_t low, size_t high, int *major);
    int BoyerMooreAlgorithm(const std::vector<int> &nums);
public:
    int majorityElement(const std::vector<int> &nums);
};

}

#endif /* MAJORITY_ELEMENT_H_ */
