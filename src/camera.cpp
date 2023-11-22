#include "camera.h"
#include "rtweekend.h"
#include "vec3.h"

void camera::render(const hittable& world)
{
    camera::initialize();

    std::for_each(image_vertical_iter.begin(), image_vertical_iter.end(),
    [this, &world](int j)
    {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        std::for_each(std::execution::par, image_horizontal_iter.begin(), image_horizontal_iter.end(),
        [this, j, &world](int i)
            {
                color pixel_color(0, 0, 0);
                for (int sample{0}; sample<samples_per_pixel; ++sample)
                {
                    ray r{get_ray(i, j)};
                    pixel_color += ray_color(r, max_depth, world);
                }
                write_color_to_mat(matrix_image, j, i, pixel_color, samples_per_pixel);

            });
    });
    write_colors(matrix_image);
    std::clog << "\rDone. \n";
}

void camera::initialize()
{
    image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    center = lookfrom;

    auto theta{degrees_to_radians(vfov)};
    auto h{std::tan(theta / 2)};
    auto viewport_height{2 * h * focus_dist};
    auto viewport_width{viewport_height * (static_cast<double>(image_width)/image_height)};

    w = unit_vector(lookfrom - lookat);
    u = unit_vector(cross(vup, w));
    v = cross(w, u);

    vec3 viewport_u{viewport_width * u};
    vec3 viewport_v{viewport_height * -v};

    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;

    auto viewport_upper_left{center - (focus_dist * w) - viewport_u / 2 - viewport_v / 2};
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    auto defocus_radius{focus_dist * std::tan(degrees_to_radians(defocus_angle / 2))};
    defocus_disk_u = u * defocus_radius;
    defocus_disk_v = v * defocus_radius;

    image_horizontal_iter.resize(image_width);
    image_vertical_iter.resize(image_height);
    for (int i = 0; i < image_width; ++i){
        image_horizontal_iter[i] = i;
    }
    for (int i = 0; i < image_height; ++i){
        image_vertical_iter[i] = i;
    }
    matrix_image.resize(image_height);
    for (int i = 0; i < image_height; ++i){
        matrix_image[i].resize(image_width);
    }
}

ray camera::get_ray(int i, int j) const
{
    auto pixel_center{pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v)};
    auto pixel_sample{pixel_center + pixel_sample_square()};

    auto ray_origin{defocus_angle <= 0 ? center : defocus_disk_sample()};
    auto ray_direction{pixel_sample - ray_origin};

    return ray(ray_origin, ray_direction);
}

vec3 camera::pixel_sample_square() const
{
    auto px = -0.5 + random_double();
    auto py = -0.5 + random_double();

    return (px * pixel_delta_u) + (py * pixel_delta_v);
}

point3 camera::defocus_disk_sample() const
{
    auto p{random_in_unit_disk()};
    return center + (p[0] * defocus_disk_u) + (p[1] * defocus_disk_v);
}

color camera::ray_color(const ray& r, int depth, const hittable& world) const
{
    hit_record rec;

    if (depth <= 0)
        return color(0, 0, 0);

    if (world.hit(r, interval(0.001, infinity), rec))
    {
        ray scattered;
        color attenuation;
        if (rec.mat->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, depth - 1, world);
        return color(0, 0, 0);
    }

    vec3 unit_direction{unit_vector(r.direction())};
    double a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}
