#include "vec3.h"

#include <math.h>

Vec3 vec3_add(Vec3 a, Vec3 b)
{
    return (Vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec3 vec3_sub(Vec3 a, Vec3 b)
{
    return (Vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

Vec3 vec3_scale(Vec3 v, float scalar)
{
    return (Vec3){v.x * scalar, v.y * scalar, v.z * scalar};
}

float vec3_dot(Vec3 a, Vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 vec3_cross(Vec3 a, Vec3 b)
{
    return (Vec3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

float vec3_length_squared(Vec3 v)
{
    return vec3_dot(v, v);
}

float vec3_length(Vec3 v)
{
    return sqrtf(vec3_length_squared(v));
}

Vec3 vec3_normalize(Vec3 v)
{
    const float length = vec3_length(v);

    if (length == 0.0f) {
        return (Vec3){0.0f, 0.0f, 0.0f};
    }

    return vec3_scale(v, 1.0f / length);
}
