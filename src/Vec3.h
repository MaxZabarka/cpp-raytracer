#pragma once

class Vec3
{

public:
    Vec3(double x = 0, double y = 0, double z = 0);
    ~Vec3();

    Vec3 operator-(const Vec3 &other) const;
    Vec3 operator+(const Vec3 &other) const;
    double dot(const Vec3 &other) const;

    double x;
    double y;
    double z;
};

using Color = Vec3;
using Point = Vec3;
using Direction = Vec3;
