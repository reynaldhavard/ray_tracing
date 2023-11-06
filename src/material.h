#pragma once

#include "color.h"
#include "hittable_list.h"
#include "rtweekend.h"

class material
{
public:
    virtual ~material() = default;

    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};

class lambertian : public material
{
public:
    lambertian(const color& a)
        : albedo{a} {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

private:
    color albedo;
};

class metal : public material
{
public:
    metal(const color& a, double f)
        : albedo{a}, fuzz{f < 1 ? f : 1} {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

private:
    color albedo;
    double fuzz;
};

class dielectric : public material
{
public:
    dielectric(double index_of_refraction)
        : ir{index_of_refraction} {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;
private:
    double ir;
    
    static double reflectance(double cosine, double ref_idx);
};
