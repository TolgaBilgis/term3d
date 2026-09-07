#include "mat4.h"

#include <math.h>

Mat4 mat4_identity(void)
{
    Mat4 result = {0};

    for (int i = 0; i < 4; ++i) {
        result.m[i][i] = 1.0f;
    }

    return result;
}

Mat4 mat4_multiply(Mat4 a, Mat4 b)
{
    Mat4 result = {0};

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            for (int k = 0; k < 4; ++k) {
                result.m[row][col] += a.m[row][k] * b.m[k][col];
            }
        }
    }

    return result;
}

Mat4 mat4_translation(float x, float y, float z)
{
    Mat4 result = mat4_identity();
    result.m[0][3] = x;
    result.m[1][3] = y;
    result.m[2][3] = z;
    return result;
}

Mat4 mat4_scale(float x, float y, float z)
{
    Mat4 result = mat4_identity();
    result.m[0][0] = x;
    result.m[1][1] = y;
    result.m[2][2] = z;
    return result;
}

Mat4 mat4_rotation_x(float radians)
{
    const float c = cosf(radians);
    const float s = sinf(radians);
    Mat4 result = mat4_identity();

    result.m[1][1] = c;
    result.m[1][2] = -s;
    result.m[2][1] = s;
    result.m[2][2] = c;
    return result;
}

Mat4 mat4_rotation_y(float radians)
{
    const float c = cosf(radians);
    const float s = sinf(radians);
    Mat4 result = mat4_identity();

    result.m[0][0] = c;
    result.m[0][2] = s;
    result.m[2][0] = -s;
    result.m[2][2] = c;
    return result;
}

Mat4 mat4_rotation_z(float radians)
{
    const float c = cosf(radians);
    const float s = sinf(radians);
    Mat4 result = mat4_identity();

    result.m[0][0] = c;
    result.m[0][1] = -s;
    result.m[1][0] = s;
    result.m[1][1] = c;
    return result;
}

Mat4 mat4_look_at(Vec3 eye, Vec3 target, Vec3 up)
{
    const Vec3 forward = vec3_normalize(vec3_sub(target, eye));
    const Vec3 right = vec3_normalize(vec3_cross(forward, up));
    const Vec3 camera_up = vec3_cross(right, forward);
    Mat4 result = mat4_identity();

    result.m[0][0] = right.x;
    result.m[0][1] = right.y;
    result.m[0][2] = right.z;
    result.m[0][3] = -vec3_dot(right, eye);

    result.m[1][0] = camera_up.x;
    result.m[1][1] = camera_up.y;
    result.m[1][2] = camera_up.z;
    result.m[1][3] = -vec3_dot(camera_up, eye);

    result.m[2][0] = -forward.x;
    result.m[2][1] = -forward.y;
    result.m[2][2] = -forward.z;
    result.m[2][3] = vec3_dot(forward, eye);

    return result;
}

Vec3 mat4_transform_point(Mat4 matrix, Vec3 point)
{
    return (Vec3){
        matrix.m[0][0] * point.x + matrix.m[0][1] * point.y +
            matrix.m[0][2] * point.z + matrix.m[0][3],
        matrix.m[1][0] * point.x + matrix.m[1][1] * point.y +
            matrix.m[1][2] * point.z + matrix.m[1][3],
        matrix.m[2][0] * point.x + matrix.m[2][1] * point.y +
            matrix.m[2][2] * point.z + matrix.m[2][3]
    };
}
