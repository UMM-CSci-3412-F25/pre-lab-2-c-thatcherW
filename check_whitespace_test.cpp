#include <gtest/gtest.h>

#include "check_whitespace.h"

TEST(strip, EmptyString) {
    ASSERT_STREQ("", strip(""));
}

TEST(strip, NoWhitespace) {
    char const* result = strip("frog");
    ASSERT_STREQ("frog", result);
    free((void*)result); // Clean 'result' up (what gets returned by strip)
    result=NULL; // Set to null just in case
}

TEST(strip, WhitespaceOnFront) {
    char const* result = strip("   frog");
    ASSERT_STREQ("frog", result);
    free((void*)result); // Clean 'result' up (what gets returned by strip)
    result=NULL; // Set to null just in case
}

TEST(strip, WhitespaceOnBack) {
    char const* result = strip("frog  ");
    ASSERT_STREQ("frog", result);
    free((void*)result); // Clean 'result' up (what gets returned by strip)
    result=NULL; // Set to null just in case
}

TEST(strip, WhitespaceOnBothEnds) {
    char const* result = strip("  frog     ");
    ASSERT_STREQ("frog", result);
    free((void*)result); // Clean 'result' up (what gets returned by strip)
    result=NULL; // Set to null just in case
}

TEST(is_clean, EmptyString) {
    ASSERT_TRUE(is_clean(""));
}

TEST(is_clean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("University of Minnesota Morris  "));
}

TEST(is_clean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean(" University of Minnesota Morris"    ));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}