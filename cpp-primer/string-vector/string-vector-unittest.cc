#include <vector>
#include <string>

#include <gtest/gtest.h>
#include <coding/vec.h>

#include "string-vector.h"

using std::vector;
using std::string;
using namespace coding::vec;
using namespace strvec;

static vector<string> StrVec2Vec(const StrVec &vec)
{
    vector<string> ret;
    for (auto cur = vec.begin();
            vec.end() != cur; ++cur) {
        ret.push_back(*cur);
    }
    return ret;
}

TEST(string_vector, empty)
{
    StrVec vec;
    EXPECT_TRUE(IsVectorEqual<string>({}, StrVec2Vec(vec)));
}

TEST(string_vector, push_val)
{
    StrVec vec;
    vector<string> ans;
    for (int i = 0; i < 100; ++i) {
        vec.PushBack(std::to_string(i));
        ans.push_back(std::to_string(i));
    }
    EXPECT_TRUE(IsVectorEqual<string>(ans, StrVec2Vec(vec)));
}

TEST(string_vector, copy)
{
    StrVec vec;
    vector<string> ans;
    for (int i = 0; i < 100; ++i) {
        vec.PushBack(std::to_string(i));
        ans.push_back(std::to_string(i));
    }
    vector<string> ans_c = ans;
    StrVec vec_c = vec;
    for (int i = 101; i < 200; ++i) {
        vec_c.PushBack(std::to_string(i));
        ans_c.push_back(std::to_string(i));
    }
    EXPECT_TRUE(IsVectorEqual<string>(ans, StrVec2Vec(vec)));
    EXPECT_TRUE(IsVectorEqual<string>(ans_c, StrVec2Vec(vec_c)));
    vec = vec_c;
    EXPECT_TRUE(IsVectorEqual<string>(ans_c, StrVec2Vec(vec)));
    vec = vec;
    EXPECT_TRUE(IsVectorEqual<string>(ans_c, StrVec2Vec(vec)));
}

TEST(string_vector, move)
{
    StrVec vec;
    vector<string> ans;
    for (int i = 0; i < 100; ++i) {
        vec.PushBack(std::to_string(i));
        ans.push_back(std::to_string(i));
    }
    StrVec vec_c = std::move(vec);
    for (int i = 101; i < 200; ++i) {
        vec_c.PushBack(std::to_string(i));
        ans.push_back(std::to_string(i));
    }
    EXPECT_TRUE(IsVectorEqual<string>(ans, StrVec2Vec(vec_c)));
    vec = std::move(vec_c);
    vec = std::move(vec);
    EXPECT_TRUE(IsVectorEqual<string>(ans, StrVec2Vec(vec)));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
