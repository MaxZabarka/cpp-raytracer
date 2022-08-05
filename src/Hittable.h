#pragma once
#include "Ray.h"

class Hit;

class Hittable
{
public:
    // virtual int test()  = 0;
    virtual Hit hit(const Ray &ray, double t_min, double t_max) = 0;
};
