#include "Vec3.h"
#include <iostream>

Vec3::Vec3(double x, double y, double z) : x{x}, y{y}, z{z} {}

Vec3::~Vec3()
{
}
Vec3 Vec3::operator-(const Vec3 &other) const
{
    return Vec3(x - other.x, y - other.y, z - other.z);
}
Vec3 Vec3::operator+(const Vec3 &other) const
{
    return Vec3(x + other.x, y + other.y, z + other.z);
}
double Vec3::dot(const Vec3 &other) const
{
    return (x * other.x) + (y * other.y) + (z * other.z);
};
