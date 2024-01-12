#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;
#include "../src/point.h"
#include "../src/element.h"
#include "../src/carte.h"
#include "../src/actions.h"
#include "../src/game.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
