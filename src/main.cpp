#include <iostream>
#include "ProgressPrinter.h"
#include "Window.h"
#include "Sphere.h"
#include "Camera.h"
#include "Renderer.h"
#include "Hittable.h"
#include <vector>

int main()
{
    Sphere sphere1{ Point{-1, 0, 0}, 0.45, Material{ Color{255, 0, 0} } };
    Sphere sphere2{ Point{0, 0, 0}, 0.45, Material{ Color{0, 255, 0} } };
    Sphere sphere3{ Point{1, 0, 0}, 0.45, Material{ Color{0, 0, 255} } };


    // Hittable *scene_hittables[] = {&sphere};
    std::vector<Hittable *>
        scene_hittables = {&sphere1, &sphere2, &sphere3};
    Window window;
    Camera camera{window.image_width, window.image_height, Point(1, 0, -2)};
    Renderer renderer;
    renderer.render(window, camera, scene_hittables);
    // window.draw_test();
}