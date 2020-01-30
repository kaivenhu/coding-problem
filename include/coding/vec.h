#ifndef CODING_VEC_H_
#define CODING_VEC_H_
#include <vector>
#include <gtest/gtest.h>


namespace coding {
namespace vec {

template<class T>
::testing::AssertionResult
IsVectorEqual(const std::vector<T> a, const std::vector<T> b)
{
    ::testing::AssertionResult result = ::testing::AssertionFailure();
    if (a.size() != b.size()) {
        result << "Difference found: size "
            << a.size() << " != " << b.size() << ".";
        return result;
    }
    for (decltype(a.size()) i = 0 ; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            result << "Difference found: index " << i;
            return result;
        }
    }
    return ::testing::AssertionSuccess();
}


}
}

#endif /* CODING_VEC_H_ */
