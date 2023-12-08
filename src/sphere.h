#pragma once

#include "hit_record.h"
#include "rtweekend.h"
#include <memory>

class hit_record;

class sphere
{
public:
    sphere(point3 _center, double _radius)
        : center{_center}, radius{_radius} {}

    bool hit(const ray& r, interval ray_t, hit_record& rec, int material_index) const;

private:
    point3 center;
    double radius;
};
