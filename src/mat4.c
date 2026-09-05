#include "mat4.h"

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
