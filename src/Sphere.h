#pragma once
#include "Ray.h"
#include "Hit.h"
#include "Hittable.h"

// class Hittable
// {
//     virtual int test() = 0;
// };

class Sphere : Hittable
{
private:
public:
    Sphere();
    ~Sphere();
    Hit hit(const Ray &ray, double t_min, double t_max) override;
    // int test() override;
    // Hit hit(const Ray &ray, double t_min, double t_max) ;
    // Hit hit(const Ray &ray, double t_min, double t_max);
};
