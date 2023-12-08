#pragma once

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <algorithm>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

double degrees_to_radians(double degrees);
double random_double();
double random_double(double min, double max);

template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

#include "interval.h"
#include "ray.h"
#include "vec3.h"
