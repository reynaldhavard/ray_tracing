#pragma once

#include "rtweekend.h"

#include "color.h"
#include "hittable.h"
#include "material.h"

class camera
{
public:
    double aspect_ratio{1.0};
    int image_width{100};
    int samples_per_pixel{10};
    int max_depth{10};

    double vfov{90};
    point3 lookfrom{point3(0, 0, -1)};
    point3 lookat{point3(0, 0, 0)};
    vec3 vup{vec3(0, 1, 0)};

    double defocus_angle{0};
    double focus_dist{10};

    void render(const hittable& world);

private:
    int image_height;
    point3 center;
    point3 pixel00_loc;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;
    vec3 u;
    vec3 v;
    vec3 w;
    vec3 defocus_disk_u;
    vec3 defocus_disk_v;

    std::vector<int> image_horizontal_iter;
    std::vector<int> image_vertical_iter;
    std::vector<std::vector<std::tuple<int, int, int>>> matrix_image;

    void initialize();
    ray get_ray(int i, int j) const;
    vec3 pixel_sample_square() const;
    point3 defocus_disk_sample() const;
    color ray_color(const ray& r, int depth, const hittable& world) const;
};
