#include "color.h"

double linear_to_gamma(double linear_component)
{
    return std::sqrt(linear_component);
}

void write_color_to_mat(std::vector<std::vector<std::tuple<int, int, int>>>& matrix, int j, int i, color pixel_color, int samples_per_pixel){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    static const interval intensity (0.000, 0.999);
    matrix[j][i] = {static_cast<int>(255.999 * intensity.clamp(r)),
                    static_cast<int>(255.999 * intensity.clamp(g)),
                    static_cast<int>(255.999 * intensity.clamp(b))};
}

void write_colors(std::vector<std::vector<std::tuple<int, int, int>>>& matrix){
    int image_height = matrix.size();
    int image_width = matrix[0].size();

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j){
        for (int i = 0; i < image_width; ++i){
            auto vals = matrix[j][i];
            std::cout << std::get<0>(vals) << ' '
                      << std::get<1>(vals) << ' '
                      << std::get<2>(vals) << '\n';
        }
    }
}
