#include "hittable_list.h"

bool hittable_list::hit(const ray& r, interval ray_t, hit_record& rec) const
{
    hit_record temp_rec;
    bool hit_anything{false};
    double closest_so_far{ray_t.max};

    for (const auto& object : objects)
    {
        if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec))
        {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}
