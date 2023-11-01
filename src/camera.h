#pragma once

#include "rtweekend.h"

#include "color.h"
#include "hittable.h"

class camera
{
public:
    double aspect_ratio;
    int image_width;

    void render(const hittable& world);

private:
    int image_height;
    point3 center;
    point3 pixel00_loc;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;

    void initialize();
    color ray_color(const ray& r, const hittable& world) const;
};
