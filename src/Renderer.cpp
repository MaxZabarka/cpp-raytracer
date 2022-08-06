#include "Renderer.h"
#include "ProgressPrinter.h"
#include "Ray.h"
#include <iostream>
#include "Hit.h"
#include "Infinity.h"
#include "Sphere.h"
Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::render(Window &window, Camera &camera, std::vector<Hittable *> scene_hittables)
{
    ProgressPrinter progress_printer{camera.image_height * camera.image_width};
    for (int y = -camera.image_height / 2; y < camera.image_height / 2; y++)
    {
        for (int x = -camera.image_width / 2; x < camera.image_width / 2; x++)
        {

            progress_printer.progress();

            // D = (V - 0)
            Direction ray_direction = camera.to_viewport(x, y) - camera.position;
            // std::cout << (Point(2, 4, 6) - Point(1, 2, 3)).y << "\n";
            // std::cout << ray_direction.y << "\n";

            Ray ray = {.direction = ray_direction, .origin = camera.position};

            window.put_pixel(x, y, trace_ray(ray, camera, scene_hittables));
        }
    }
    window.show();
}
Color Renderer::trace_ray(Ray& ray, Camera &camera, std::vector<Hittable *> scene_hittables)
{
    // std::cout << "trace ray";
    for (auto scene_hittable : scene_hittables)
    {
        Hit hit = scene_hittable->hit(ray, 0.001, camera.far);

        // std::cout << hit.t1 << "\n";

        if (hit.t1 < INFINITY)
        {
            return scene_hittable->get_material().color;
        }
    }
    return camera.background;
}