#include "insertion-sort.h"

namespace insertion {

using std::vector;

vector<int> InsertSort::sort(const vector<int> &src)
{
    vector<int> vec = src;
    for (decltype(vec.size()) i = 1;
            i < vec.size(); ++i) {
        auto key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
    return vec;
}

}
