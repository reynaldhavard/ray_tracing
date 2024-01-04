#pragma once

#include "rtweekend.h"

class interval {
public:
  double min, max;

  interval() : min{+infinity}, max{-infinity} {}
  interval(double _min, double _max) : min{_min}, max{_max} {}

  bool contains(double x) const;
  bool surrounds(double x) const;
  double clamp(double x) const;

  static const interval empty, universe;
};

const static interval empty(+infinity, -infinity);
const static interval universe(-infinity, +infinity);
