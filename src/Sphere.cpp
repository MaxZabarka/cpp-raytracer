#include "Sphere.h"
#include "Hit.h"
#include "Infinity.h"
#include <cmath>
#include <iostream>
Sphere::Sphere(Point position, double radius, Material material) : position{position}, radius{radius}, material{material}
{
}

Sphere::~Sphere()
{
}

// int Sphere::test() {
//     return 0;
// }

Hit Sphere::hit(const Ray &ray, double t_min, double t_max)
{
    Hit hit{INFINITY, INFINITY, this};

    // CO = O - C
    Vec3 sphere_direction = ray.origin - position;

    // < direction, direction >
    double a = ray.direction.dot(ray.direction);

    // 2 <CO, D>
    double b = 2 * ray.direction.dot(sphere_direction);

    // < CO, CO > - r^2
    double c = sphere_direction.dot(sphere_direction) - pow(radius, 2);

    // Solve the quadratic
    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0)
    {
        hit.t1 = (-b + sqrt(discriminant)) / (2 * a);
        hit.t2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    // hit.t1 = 5;
    // hit.t2 = 5;

    return hit;
}

Material Sphere::get_material()
{
    return material;
}