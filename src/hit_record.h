#pragma once

#include "rtweekend.h"

class hit_record
{
public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;
    int material_index;

    void set_face_normal(const ray& r, const vec3& outward_normal);
};
