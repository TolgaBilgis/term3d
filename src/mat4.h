#ifndef TERM3D_MAT4_H
#define TERM3D_MAT4_H

typedef struct {
    float m[4][4];
} Mat4;

Mat4 mat4_identity(void);
Mat4 mat4_multiply(Mat4 a, Mat4 b);

#endif
