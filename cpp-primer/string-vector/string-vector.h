#ifndef STRING_VECTOR_H_
#define STRING_VECTOR_H_
#include <memory>
#include <string>
#include <utility>

namespace strvec {

class StrVec;

void swap(StrVec &x, StrVec &y) noexcept;

class StrVec {
    std::allocator<std::string> alloc_;
    std::string *begin_;
    std::string *end_;
    std::string *cap_;

    size_t capacity(void) const { return cap_ - begin_; }
    std::pair<std::string *, std::string *>
    AllocAndCopy(const std::string *b,
                const std::string *e);
    void CheckAndAlloc(void);
    void free(void);
    void Reallocate(void);

public:
    StrVec();
    ~StrVec();
    StrVec(const StrVec &src);
    StrVec& operator=(StrVec vec) noexcept;

    void PushBack(const std::string &val);

    std::string *begin(void) const { return begin_; }
    std::string *end(void) const { return end_; }
    size_t size(void) const { return end_ - begin_; }

    friend void swap(StrVec &x, StrVec &y) noexcept;
};

}

#endif /* STRING_VECTOR_H_ */
