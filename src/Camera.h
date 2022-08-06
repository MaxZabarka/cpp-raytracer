#pragma once
#include "Vec3.h"
#include "Infinity.h"

class Camera
{
public:
    Camera(
        int image_width,
        int image_height,
        Point position = Point(),
        Color background = Color(110, 209, 255),
        double fov = 75,
        double far = INFINITY);
    ~Camera();

    Point to_viewport(int x, int y);

public:
    int image_width;
    int image_height;
    Color background;
    Point position;
    double far;

private:
    double fov;
    double viewport_distance;
    double viewport_width;
    double viewport_height;
};
