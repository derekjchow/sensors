#include "sensors/feature.h"

#include <cmath>

namespace me597 {
namespace sensors {

bool InViewLocal(const Eigen::Vector2d& feature, double max_range, double fov) {
  // TODO(reader): Implement this function
  return false;
}

bool InView(const Eigen::Vector2d& feature, const Eigen::Vector3d& pose,
            double max_range, double fov) {
  // TODO(reader): Implement this function
  // Hint: Transform feature into sensor coordinates and use InViewLocal
  return false;
}

}  // namespace sensors
}  // namespace me597
