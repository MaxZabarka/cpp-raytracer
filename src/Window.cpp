#include "Window.h"
#include <iostream>
#include "ProgressPrinter.h"

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

    ProgressPrinter progress_printer{image_height*image_width};
    for (int y = image_height - 1; y >= 0; --y)
    {
        for (int x = 0; x < image_width; ++x)
        {
            progress_printer.progress();
            double r = double(x) / (image_width - 1);
            double g = double(y) / (image_height - 1);
            double b = 0.25;

            int ir = (int)(255 * r);
            int ig = (int)(255 * g);
            int ib = (int)(255 * b);

            SDL_SetRenderDrawColor(renderer, ir, ig, ib, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
    show();
}

void Window::put_pixel(int x, int y, Color color) {

}

void Window::show() {
    SDL_RenderPresent(renderer);
    event_loop();
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