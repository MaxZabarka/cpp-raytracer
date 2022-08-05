#include "Window.h"
#include <iostream>
#include "ProgressPrinter.h"
#include <SDL2/SDL.h>
#include <tuple>

Window::Window(int image_width, int image_height, int window_width, int window_height) : image_width{image_width}, image_height{image_height}
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer);
    SDL_RenderSetLogicalSize(renderer, image_width, image_height);
}

Window::~Window()
{
}

void Window::draw_test()
{

    ProgressPrinter progress_printer{image_height * image_width};
    for (int y = -image_height / 2; y < image_height / 2; y++)
    {
        for (int x = -image_width / 2; x < image_width / 2; x++)
        {
            progress_printer.progress();
            double r = double(x + image_width / 2) / (image_width);
            double g = double(y + image_height / 2) / (image_height);
            double b = 0.25;

            put_pixel(x, y, Vec3(r * 255, g * 255, b * 255));
        }
    }
    show();
}

void Window::put_pixel(int x, int y, Color color)
{
    std::tuple<int, int> realCoordinates = quadrant_to_real(x, y);
    x = std::get<0>(realCoordinates);
    y = std::get<1>(realCoordinates);

    SDL_SetRenderDrawColor(renderer, color.x, color.y, color.z, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Window::show()
{
    SDL_RenderPresent(renderer);
    event_loop();
}

std::tuple<int, int> Window::quadrant_to_real(int x, int y)
{

    x = round(image_width / 2) + x;
    y = round(image_height / 2) - y;
    return std::make_tuple(x, y);
}

void Window::event_loop()
{
    SDL_Event event;

    bool quit = false;
    while (!quit)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
        }
    }
}