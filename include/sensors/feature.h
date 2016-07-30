#ifndef SENSORS_FEATURE_H_
#define SENSORS_FEATURE_H_

#include <Eigen/Core>

namespace me597 {
namespace sensors {

/**
 * Checks if a feature is in a given field of view of a sensor.
 *
 * @param feature Location of the feature in the local coordinates (x, y).
 * @param max_range The maximum distance of a feature that the sensor can read.
                    Should be greater than zero.
 * @param fov The field of view of the sensor. A feature is in view if the angle
 *            of the feature is within +/- fov/2 of the x-axis.
 *            Measured in radians and should be between 0 and 2*M_PI
 * @return True if the feature is view of the sensor.
 */
bool InViewLocal(const Eigen::Vector2d& feature, double max_range, double fov);

/**
 * Checks if a feature is in a given field of view of a sensor.
 *
 * @param feature Location of the feature in the world coordinates (x, y).
 * @param pose The location and orientation of the sensor in world coordinates
 *             (x, y, theta).
 * @param max_range The maximum distance of a feature that the sensor can read.
                    Should be greater than zero.
 * @param fov The field of view of the sensor. A feature is in view if the angle
 *            of the feature is within +/- fov/2 of the x-axis.
 *            Measured in radians and should be between 0 and 2*M_PI
 * @return True if the feature is view of the sensor.
 */
bool InView(const Eigen::Vector2d& feature, const Eigen::Vector3d& pose,
            double max_range, double fov);

}  // namespace sensors
}  // namespace me597

#endif  // SENSORS_FEATURE_H_
