#include <stdio.h>

#include "framebuffer.h"
#include "mat4.h"
#include "vec3.h"

#define VIEW_WIDTH 64
#define VIEW_HEIGHT 24

static int screen_x(float ndc_x)
{
    return (int)((ndc_x + 1.0f) * 0.5f * (float)(VIEW_WIDTH - 1));
}

static int screen_y(float ndc_y)
{
    return (int)((1.0f - ndc_y) * 0.5f * (float)(VIEW_HEIGHT - 1));
}

int main(void)
{
    Framebuffer buffer = {0};
    if (!framebuffer_init(&buffer, VIEW_WIDTH, VIEW_HEIGHT)) {
        fputs("term3d: failed to allocate framebuffer\n", stderr);
        return 1;
    }

    const Vec3 points[] = {
        {-1.0f, -1.0f, -3.0f},
        { 1.0f, -1.0f, -3.0f},
        { 1.0f,  1.0f, -3.0f},
        {-1.0f,  1.0f, -3.0f},
        { 0.0f,  0.0f, -2.0f}
    };
    const Mat4 projection = mat4_perspective(
        1.0471975512f,
        (float)VIEW_WIDTH / (float)VIEW_HEIGHT,
        0.1f,
        100.0f
    );

    for (size_t i = 0; i < sizeof(points) / sizeof(points[0]); ++i) {
        Vec3 projected;
        if (mat4_project_point(projection, points[i], &projected)) {
            framebuffer_put(&buffer, screen_x(projected.x), screen_y(projected.y), '*');
        }
    }

    framebuffer_present(&buffer);
    framebuffer_free(&buffer);
    return 0;
}
