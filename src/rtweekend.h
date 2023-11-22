#pragma once

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <algorithm>
#include <execution>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

double degrees_to_radians(double degrees);
double random_double();
double random_double(double min, double max);

#include "interval.h"
#include "ray.h"
#include "vec3.h"
