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
    metal(const color& a)
        : albedo{a} {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

private:
    color albedo;
};
