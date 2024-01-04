#include "sphere.h"

bool sphere::hit(const ray &r, interval ray_t, hit_record &rec,
                 int material_index) const {
  vec3 oc{r.origin() - center};
  double a{r.direction().length_squared()};
  double b{2.0 * dot(oc, r.direction())};
  double c{oc.length_squared() - radius * radius};
  double discriminant{b * b - 4 * a * c};

  if (discriminant < 0)
    return false;

  double sqrtd{std::sqrt(discriminant)};

  double root{(-b - sqrtd) / (2.0 * a)};
  if (!ray_t.surrounds(root)) {
    root = (-b + sqrtd) / (2.0 * a);
    if (!ray_t.surrounds(root))
      return false;
  }

  rec.t = root;
  rec.p = r.at(rec.t);
  rec.material_index = material_index;
  vec3 outward_normal = (rec.p - center) / radius;
  rec.set_face_normal(r, outward_normal);

  return true;
}
