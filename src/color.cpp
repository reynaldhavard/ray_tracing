#include "color.h"
#include "sdl.h"

double linear_to_gamma(double linear_component) {
  return std::sqrt(linear_component);
}

void write_color_to_frame_buffer(SDL &sdl, int pos, color pixel_color,
                                 int samples_per_pixel) {
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

  static const interval intensity(0.000, 0.999);
  int R = static_cast<int>(255.999 * intensity.clamp(r));
  int G = static_cast<int>(255.999 * intensity.clamp(g));
  int B = static_cast<int>(255.999 * intensity.clamp(b));

  sdl.frame_buffer[pos] = (255 << 24 | R << 16 | G << 8 | B);
}

void output_colors(const SDL &sdl, int image_width, int image_height) {
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (const auto &col : sdl.frame_buffer) {
    int r = static_cast<int>((col >> 16) & 0xFF);
    int g = static_cast<int>((col >> 8) & 0xFF);
    int b = static_cast<int>(col & 0xFF);
    std::cout << r << ' ' << g << ' ' << b << '\n';
  }
}
