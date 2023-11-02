#pragma once

#include "hittable.h"
#include <memory>

class sphere : public hittable
{
public:
    sphere(point3 _center, double _radius, std::shared_ptr<material> _material)
        : center{_center}, radius{_radius}, mat{_material} {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override;

private:
    point3 center;
    double radius;
    std::shared_ptr<material> mat;
};
