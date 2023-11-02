#include "vec3.h"

vec3& vec3::operator+=(const vec3 &v)
{
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vec3& vec3::operator*=(double t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vec3& vec3::operator/=(double t)
{
    return *this *= 1/t;
}

double vec3::length() const
{
    return std::sqrt(length_squared());
}

double vec3::length_squared() const 
{
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];

}

vec3 vec3::random()
{
    return vec3(random_double(), random_double(), random_double());
}

vec3 vec3::random(double min, double max)
{
    return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
}

std::ostream& operator<<(std::ostream &out, const vec3 &v)
{
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

vec3 operator+(const vec3 &u, const vec3 &v)
{
    return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

vec3 operator-(const vec3 &u, const vec3 &v)
{
    return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

vec3 operator*(const vec3 &u, const vec3 &v)
{
    return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

vec3 operator*(double t, const vec3 &v)
{
    return vec3(t * v.x(), t * v.y(), t * v.z());
}

vec3 operator*(const vec3 &v, double t){
    return t * v;
}

vec3 operator/(const vec3 &v, double t){
    return (1/t) * v;
}

double dot(const vec3 &u, const vec3 &v)
{
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.z());
}


vec3 unit_vector(const vec3 &v)
{
    return v / v.length();
}

vec3 random_in_unit_sphere()
{
    while (true)
    {
        auto p{vec3::random(-1, 1)};
        if (p.length_squared() < 1)
            return p;
    }
}

vec3 random_unit_vector()
{
    return unit_vector(random_in_unit_sphere());
}

vec3 random_on_hemisphere(const vec3 &normal)
{
    vec3 on_unit_sphere{random_unit_vector()};
    if (dot(on_unit_sphere, normal) > 0.0)
        return on_unit_sphere;
    else
        return -on_unit_sphere;;
}
