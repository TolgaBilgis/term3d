#ifndef TERM3D_MAT4_H
#define TERM3D_MAT4_H

#include <stdbool.h>

#include "vec3.h"

typedef struct {
    float m[4][4];
} Mat4;

Mat4 mat4_identity(void);
Mat4 mat4_multiply(Mat4 a, Mat4 b);
Mat4 mat4_translation(float x, float y, float z);
Mat4 mat4_scale(float x, float y, float z);
Mat4 mat4_rotation_x(float radians);
Mat4 mat4_rotation_y(float radians);
Mat4 mat4_rotation_z(float radians);
Mat4 mat4_look_at(Vec3 eye, Vec3 target, Vec3 up);
Mat4 mat4_perspective(float fov_y_radians, float aspect, float near_plane, float far_plane);
Vec3 mat4_transform_point(Mat4 matrix, Vec3 point);
bool mat4_project_point(Mat4 matrix, Vec3 point, Vec3 *projected);

#endif
