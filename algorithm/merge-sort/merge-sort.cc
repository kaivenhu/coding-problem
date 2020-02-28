#include "merge-sort.h"

namespace merge_sort {

using std::vector;

vector<int> MergeSort::sort(const vector<int> &src)
{
    vector<int> vec = src;
    Sort(vec, 0, vec.size() - 1);
    return vec;
}

void MergeSort::Merge(vector<int> &vec, int p, int q, int r)
{
    vector<int> left(vec.begin() + p, vec.begin() + q);
    vector<int> right(vec.begin() + q, vec.begin() + r);
    auto l_iter = left.begin();
    auto r_iter = right.begin();
    int k = p;
    while (k < r && left.end() != l_iter && right.end() != r_iter) {
        if (*l_iter <= *r_iter) {
            vec[k++] = *l_iter++;
        } else {
            vec[k++] = *r_iter++;
        }
    }
    while (k < r && left.end() != l_iter) {
        vec[k++] = *l_iter++;
    }
    while (k < r && right.end() != r_iter) {
        vec[k++] = *r_iter++;
    }
}

void MergeSort::Sort(vector<int> &vec, int p, int q)
{
    if (p >= q) {
        return;
    }
    int mid = (p + q) / 2;
    Sort(vec, p, mid);
    Sort(vec, mid + 1, q);
    Merge(vec, p, mid + 1, q + 1);
}

}
