#include <algorithm>

#include "counting-sort.h"

namespace sort {

using std::vector;

vector<int> CountingSort::sort(const vector<int> &src)
{
    if (!src.size()) {
        return vector<int>();
    }
    vector<int> vec(src.size(), 0);
    auto k = std::max_element(src.begin(), src.end());
    vector<int> counter(*k + 1, 0);

    for (const auto v : src) {
        ++counter[v];
    }
    for (decltype(counter.size()) i = 1; i < counter.size(); ++i) {
        counter[i] += counter[i - 1];
    }
    for (auto v = src.rbegin(); v != src.rend(); ++v) {
        vec[--counter[*v]] = *v;
    }
    return vec;
}


}
