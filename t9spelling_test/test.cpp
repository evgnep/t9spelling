#include "gtest/gtest.h"
#include "../t9spelling/t9spelling.h"
#include "../t9spelling/task.h"

struct T9Spelling : testing::Test {
  std::string res;

  const std::string& convert(std::string_view src) {
    t9spelling::encode(src, res);
    return res;
  }
};

TEST_F(T9Spelling, simple) {
  ASSERT_EQ(convert(""), "");
  ASSERT_EQ(convert(" "), "0");
  ASSERT_EQ(convert("a"), "2");
  ASSERT_EQ(convert("j"), "5");
  ASSERT_EQ(convert("k"), "55");
  ASSERT_EQ(convert("mne"), "6 6633");
}

TEST_F(T9Spelling, invalid_char) {
  ASSERT_THROW(convert("A"), std::runtime_error);
  ASSERT_THROW(convert("1"), std::runtime_error);
  ASSERT_THROW(convert(","), std::runtime_error);
}

TEST_F(T9Spelling, codejam) {
  ASSERT_EQ(convert("hi"), "44 444");
  ASSERT_EQ(convert("yes"), "999337777");
  ASSERT_EQ(convert("foo  bar"), "333666 6660 022 2777");
  ASSERT_EQ(convert("hello world"), "4433555 555666096667775553");  
}

struct Task : testing::Test {  
  std::string convert(const std::string& src) {    
    std::istringstream is(src);
    std::ostringstream os;

    run(is, os);

    return os.str();
  }
};

TEST_F(Task, simple) {
 ASSERT_EQ(convert("1\nhi"), "Case #1: 44 444");
}

TEST_F(Task, invalid) {
  ASSERT_THROW(convert("0"), std::runtime_error);
  ASSERT_THROW(convert("a"), std::runtime_error);
  ASSERT_THROW(convert("1\n22"), std::runtime_error);
}

TEST_F(Task, codejam) {
  ASSERT_EQ(convert(
    R"(4
hi
yes
foo  bar
hello world)"),
R"(Case #1: 44 444
Case #2: 999337777
Case #3: 333666 6660 022 2777
Case #4: 4433555 555666096667775553)");
}

