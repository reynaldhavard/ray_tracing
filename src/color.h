#pragma once

#include "rtweekend.h"
#include "sdl.h"

#include <iostream>

using color = vec3;

double linear_to_gamma(double linear_component);
void write_color_to_frame_buffer(SDL &sdl, int pos, color pixel_color,
                                 int samples_per_pixel);
void output_colors(const SDL &sdl, int image_width, int image_height);
