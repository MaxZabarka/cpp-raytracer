#include "Camera.h"
#include <cmath>
#include <iostream>

Camera::Camera(
    int image_width,
    int image_height,
    Point position,
    Color background,
    double fov,
    double far)
    :

      image_width{image_width},
      image_height{image_height},
      background{background},
      position{position},
      far{far}

{
    viewport_height = 1;
    viewport_width = 1 * image_width / image_height;
    // viewport_distance = 1;
    viewport_distance = 1 / tan(((fov / 2) * M_PI) / 180.0) / 2;
}
Point Camera::to_viewport(int x, int y)
{

    double viewportX = x * (viewport_width / image_width) + position.x;
    double viewportY = y * (viewport_height / image_height) + position.y;
    double viewportZ = viewport_distance + position.z;
    
    return Point(viewportX, viewportY, viewportZ);
}

Camera::~Camera()
{
}
