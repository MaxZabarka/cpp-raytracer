#pragma once
#include "Ray.h"
#include "Hit.h"
#include "Hittable.h"
#include "Vec3.h"

class Sphere : public Hittable
{
private:
    Material material;

public:
    Sphere(Point position = Point{}, double radius = 0.75, Material material = Material{Color{128, 128, 128}});
    ~Sphere();
    Hit hit(const Ray &ray, double t_min, double t_max);
    Material get_material();
    Point position;
    double radius;
};
