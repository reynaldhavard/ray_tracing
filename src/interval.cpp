#include "interval.h"

bool interval::contains(double x) const { return min <= x && x <= max; }

bool interval::surrounds(double x) const { return min < x && x < max; }

double interval::clamp(double x) const {
  if (x < min)
    return min;
  if (x > max)
    return max;
  return x;
}
