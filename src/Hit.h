#pragma once
class Hittable;

struct Hit
{
    double t1; // first intersection
    double t2; // second intersection
    // no intersection = infinity

    // //Disable error squiggle
    #ifndef __INTELLISENSE__
        Hittable& hittable;
    #endif
};