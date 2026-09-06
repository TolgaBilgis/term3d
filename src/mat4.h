#ifndef TERM3D_MAT4_H
#define TERM3D_MAT4_H

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

#endif
