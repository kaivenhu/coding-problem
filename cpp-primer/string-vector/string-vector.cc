#include "string-vector.h"

namespace strvec {

using std::string;

void swap(StrVec &x, StrVec &y) noexcept
{
    using std::swap;
    swap(x.begin_, y.begin_);
    swap(x.end_, y.end_);
    swap(x.cap_, y.cap_);
}

StrVec::StrVec() :
    begin_(nullptr), end_(nullptr), cap_(nullptr)
{

}

StrVec::~StrVec()
{
    free();
}

StrVec::StrVec(const StrVec &src) :
    begin_(nullptr), end_(nullptr), cap_(nullptr)
{
    auto data = AllocAndCopy(src.begin(), src.end());
    begin_ = data.first;
    cap_ = end_ = data.second;
}

StrVec::StrVec(StrVec &&src) noexcept :
    begin_(src.begin_), end_(src.end_), cap_(src.cap_)
{
    src.begin_ = src.end_ = src.cap_ = nullptr;
}

StrVec& StrVec::operator=(StrVec vec) noexcept
{
    swap(*this, vec);
    return *this;
}

void StrVec::PushBack(const string &val)
{
    CheckAndAlloc();
    alloc_.construct(end_++, val);
}

std::pair<string *, string *>
StrVec::AllocAndCopy(const string *b, const string *e)
{
    auto data = alloc_.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::CheckAndAlloc(void)
{
    if (capacity() == size()) {
        Reallocate();
    }
}

void StrVec::free(void)
{
    if (begin_) {
        for (auto cur = begin_; cur != end_; ++cur) {
            alloc_.destroy(cur);
        }
        alloc_.deallocate(begin_, capacity());
    }
    begin_ = end_ = cap_ = nullptr;
}

void StrVec::Reallocate(void)
{
    size_t alloc_size = capacity() ? 2 * capacity() : 1;

    auto new_begin = alloc_.allocate(alloc_size);
    auto dest = new_begin;
    auto src = begin_;
    for (size_t i = 0; size() != i; ++i) {
        alloc_.construct(dest++, std::move(*(src++)));
    }
    free();
    begin_ = new_begin;
    end_ = dest;
    cap_ = begin_ + alloc_size;
}

}
