#pragma once

#include "rtweekend.h"

#include <iostream>

using color = vec3;

double linear_to_gamma(double linear_component);
void write_color(std::ostream &out, color pixel_color, int samples_per_pixel);
