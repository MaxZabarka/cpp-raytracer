#pragma once
#include <SDL2/SDL.h>
#include "Vec3.h"

class Window
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int image_width;
    int image_height;

public:
    Window(int image_width = 256, int image_height = 256, int window_width = 512, int window_height = 512);
    ~Window();
    void draw_test();
    void event_loop();
    void show();
    void put_pixel(int x, int y, Color color);
};
