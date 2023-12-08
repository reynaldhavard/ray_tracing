#pragma once

#include "color.h"
#include "hit_record.h"
#include "rtweekend.h"

class lambertian
{
public:
    lambertian() {};
    lambertian(const color& a)
        : albedo{a} {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const;

private:
    color albedo;
};

class metal
{
public:
    metal() {};
    metal(const color& a, double f)
        : albedo{a}, fuzz{f < 1 ? f : 1} {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const;

private:
    color albedo;
    double fuzz;
};

class dielectric
{
public:
    dielectric() {};
    dielectric(double index_of_refraction)
        : ir{index_of_refraction} {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const;
private:
    double ir;
    
    static double reflectance(double cosine, double ref_idx);
};
