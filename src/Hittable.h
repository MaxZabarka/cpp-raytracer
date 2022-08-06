#pragma once
#include "Ray.h"
#include "Material.h"

class Hit;

class Hittable
{
protected:
    Hittable() {} ;


public:
    virtual Hit hit(const Ray &ray, double t_min, double t_max) = 0;
    virtual Material get_material() = 0;
};
