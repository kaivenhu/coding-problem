#include <algorithm>
#include <cmath>

#include "radix-sort.h"

namespace sort {

using std::vector;

vector<int> RadixSort::sort(const vector<int> &src)
{
    if (!src.size()) {
        return vector<int>();
    }
    vector<int> vec = src;
    int k = *(std::max_element(src.begin(), src.end()));
    int i = 0;
    while (k) {
        vec = counting_sort(vec, i);
        ++i;
        k /= 10;
    }
    return vec;
}

vector<int> RadixSort::counting_sort(const vector<int> &src, int digit)
{
    vector<int> vec(src.size(), 0);
    vector<int> counter(10, 0);
    int divid = pow(10, digit);

    for (const auto v : src) {
        int x = (v / divid) % 10;
        ++counter[x];
    }
    for (decltype(counter.size()) i = 1; i < counter.size(); ++i) {
        counter[i] += counter[i - 1];
    }
    for (auto v = src.rbegin(); v != src.rend(); ++v) {
        int x = (*v / divid) % 10;
        vec[--counter[x]] = *v;
    }
    return vec;
}


}
