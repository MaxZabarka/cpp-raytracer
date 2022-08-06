#pragma once
#include "Window.h"
#include "Camera.h"
#include "Vec3.h"
#include "Ray.h"
#include "Hittable.h"
#include <vector>
class Renderer
{
private:
public:
    Renderer();
    ~Renderer();
    void render(Window &window, Camera &camera, std::vector<Hittable *> scene_hittables);

private:
    Color trace_ray(Ray& ray, Camera &camera, std::vector<Hittable *> scene_hittables);
};
