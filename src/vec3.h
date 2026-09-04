#ifndef TERM3D_VEC3_H
#define TERM3D_VEC3_H

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_sub(Vec3 a, Vec3 b);
Vec3 vec3_scale(Vec3 v, float scalar);

#endif
