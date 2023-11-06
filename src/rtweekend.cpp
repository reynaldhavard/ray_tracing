#include "rtweekend.h"

double degrees_to_radians(double degrees)
{
    return degrees * pi / 180.0;
}

double random_double()
{
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max)
{
    return min + (max - min) * random_double();
}
