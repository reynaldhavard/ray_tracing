#pragma once

#include "rtweekend.h"

#include "hit_record.h"
#include "material.h"
#include "sphere.h"

#include <memory>
#include <variant>
#include <vector>

using material = std::variant<lambertian, metal, dielectric>;

class hittable_list {
public:
  std::vector<std::pair<sphere, int>> objects;
  std::vector<material> materials;

  hittable_list() {}
  hittable_list(sphere object, material mat) { add(object, mat); }

  void clear() { objects.clear(); }
  void add(sphere object, material mat);

  bool hit(const ray &r, interval ray_t, hit_record &rec) const;
};
