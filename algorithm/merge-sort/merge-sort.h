#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_
#include <vector>

namespace merge_sort {

class MergeSort {
public:
    static std::vector<int> sort(const std::vector<int> &src);

private:
    static void Merge(std::vector<int> &vec, int p, int q, int r);
    static void Sort(std::vector<int> &vec, int p, int q);
};

}

#endif /* MERGE_SORT_H_ */
