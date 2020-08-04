#include "quick-sort.h"

namespace sort {

using std::vector;

vector<int> QuickSort::sort(const vector<int> &src)
{
    vector<int> vec = src;
    sort(vec, 0, vec.size() - 1);
    return vec;
}

int QuickSort::partition(vector<int> &vec, int p, int q)
{
    const int pivot = vec[q];
    int i = p - 1;
    for (; p < q; ++p) {
        if (vec[p] <= pivot) {
            std::swap(vec[++i], vec[p]);
        }
    }
    std::swap(vec[++i], vec[q]);
    return i;
}

void QuickSort::sort(std::vector<int> &vec, int p, int q)
{
    if (p >= q) {
        return;
    }
    int r = partition(vec, p, q);
    sort(vec, p, r - 1);
    sort(vec, r + 1, q);
}

}
