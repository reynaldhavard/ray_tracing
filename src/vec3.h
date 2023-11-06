#pragma once

#include <cmath>
#include <iostream>
#include <ostream>

class vec3 
{
public:
    vec3()
        : e{0, 0, 0} {}

    vec3(double e0, double e1, double e2)
        : e{e0, e1, e2} {}

    double x() const {return e[0];}
    double y() const {return e[1];}
    double z() const {return e[2];}

    vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]);}
    double operator[](int i) const {return e[i];}
    double& operator[](int i) {return e[i];}

    vec3& operator+=(const vec3 &v);
    vec3& operator*=(double t);
    vec3& operator/=(double t);
    double length() const;
    double length_squared() const;
    bool near_zero() const;
    static vec3 random();
    static vec3 random(double min, double max);

private:
    double e[3];
};

// point3 is just an alias for vec3
using point3 = vec3;

// Forward declare random_double, from rtweekend.h
double random_double();
double random_double(double min, double max);

// Vector utility functions
std::ostream& operator<<(std::ostream &out, const vec3 &v);
vec3 operator+(const vec3 &u, const vec3 &v);
vec3 operator-(const vec3 &u, const vec3 &v);
vec3 operator*(const vec3 &u, const vec3 &v);
vec3 operator*(double t, const vec3 &v);
vec3 operator*(const vec3 &v, double t);
vec3 operator/(const vec3 &v, double t);
double dot(const vec3 &u, const vec3 &v);
vec3 cross(const vec3 &u, const vec3 &v);
vec3 unit_vector(const vec3 &v);
vec3 random_in_unit_sphere();
vec3 random_unit_vector();
vec3 random_on_hemisphere(const vec3& normal);
vec3 reflect(const vec3& v, const vec3& n);
vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat);
