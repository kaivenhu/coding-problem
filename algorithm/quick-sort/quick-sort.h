#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_
#include <vector>

namespace sort {

class QuickSort {
public:
    static std::vector<int> sort(const std::vector<int> &src);
private:
    static int partition(std::vector<int> &vec, int p, int q);
    static void sort(std::vector<int> &vec, int p, int q);
};

}

#endif /* QUICK_SORT_H_ */
