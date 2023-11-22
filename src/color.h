#pragma once

#include "rtweekend.h"

#include <iostream>

using color = vec3;

double linear_to_gamma(double linear_component);
void write_color_to_mat(std::vector<std::vector<std::tuple<int, int, int>>>& matrix, int j, int i, color pixel_color, int samples_per_pixel);
void write_colors(std::vector<std::vector<std::tuple<int, int, int>>>& matrix);
