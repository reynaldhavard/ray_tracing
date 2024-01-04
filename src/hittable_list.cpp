#include "hittable_list.h"

void hittable_list::add(sphere object, material mat) {
  std::pair<sphere, int> pair_object{object, materials.size()};
  objects.push_back(pair_object);
  materials.push_back(mat);
}

bool hittable_list::hit(const ray &r, interval ray_t, hit_record &rec) const {
  hit_record temp_rec;
  bool hit_anything{false};
  double closest_so_far{ray_t.max};

  for (const auto &[object, material_index] : objects) {
    if (object.hit(r, interval(ray_t.min, closest_so_far), temp_rec,
                   material_index)) {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
  }

  return hit_anything;
}
