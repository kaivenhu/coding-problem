#include "single-number-ii.h"

namespace bitwise
{
using std::vector;

int Solution::singleNumber(const vector<int> &nums)
{
    int one = 0;
    int two = 0;
    for (const auto n : nums) {
        one ^= n;
        one &= ~two;
        two ^= n;
        two &= ~one;
    }
    return one;
}

}  // namespace bitwise
