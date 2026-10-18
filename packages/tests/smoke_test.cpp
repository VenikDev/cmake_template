#include <gtest/gtest.h>

TEST(SmokeTest, BasicAssertion) {
  EXPECT_EQ(2 + 2, 4);
  EXPECT_EQ(2 + 2, 5);
}
