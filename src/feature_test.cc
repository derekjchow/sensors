#include "gtest/gtest.h"
#include "sensors/feature.h"

using me597::sensors::InViewLocal;

// Tests features in front of a sensor.
TEST(FeatureTest, LocalFeatures) {
  EXPECT_TRUE(InViewLocal(Eigen::Vector2d(5, 0), 10, M_PI/2));
  EXPECT_TRUE(InViewLocal(Eigen::Vector2d(9, 0), 10, M_PI/2));
  EXPECT_TRUE(InViewLocal(Eigen::Vector2d(5, 4), 10, M_PI/2));
  EXPECT_TRUE(InViewLocal(Eigen::Vector2d(5, -3), 10, M_PI/2));

  // Consider a feature at the origin in the field of view
  EXPECT_TRUE(InViewLocal(Eigen::Vector2d(0, 0), 10, M_PI/2));

  // Out of range (too far away)
  EXPECT_FALSE(InViewLocal(Eigen::Vector2d(9001, 0), 10, M_PI/2));

  // Outside field of view
  EXPECT_FALSE(InViewLocal(Eigen::Vector2d(5, 6), 10, M_PI/2));
  EXPECT_FALSE(InViewLocal(Eigen::Vector2d(4, -8), 10, M_PI/2));
  EXPECT_FALSE(InViewLocal(Eigen::Vector2d(0, 1), 10, M_PI/2));

  // Behind sensor
  EXPECT_FALSE(InViewLocal(Eigen::Vector2d(-8, 0), 10, M_PI/2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
