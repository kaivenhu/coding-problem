#include "max-min.h"
#include <climits>

namespace max_min
{
using std::pair;
using std::vector;

pair<int, int> MaxMin::get(const vector<int> &src)
{
    int size = src.size();
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 1; i <= size / 2; ++i) {
        int idx = (i - 1) * 2;
        int sub_max;
        int sub_min;
        if (src[idx] > src[idx + 1]) {
            sub_max = src[idx];
            sub_min = src[idx + 1];
        } else {
            sub_max = src[idx + 1];
            sub_min = src[idx];
        }
        if (sub_max > max) {
            max = sub_max;
        }
        if (sub_min < min) {
            min = sub_min;
        }
    }
    if (src[size - 1] > max) {
        max = src[size - 1];
    }
    if (src[size - 1] < min) {
        min = src[src.size() - 1];
    }
    return pair<int, int>(max, min);
}

}  // namespace max_min
