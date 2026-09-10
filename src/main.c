#include <stdio.h>

#include "framebuffer.h"
#include "mat4.h"
#include "raster.h"
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

    const Vec3 vertices[] = {
        {-1.0f, -1.0f, -4.0f},
        { 1.0f, -1.0f, -4.0f},
        { 1.0f,  1.0f, -4.0f},
        {-1.0f,  1.0f, -4.0f},
        {-1.0f, -1.0f, -6.0f},
        { 1.0f, -1.0f, -6.0f},
        { 1.0f,  1.0f, -6.0f},
        {-1.0f,  1.0f, -6.0f}
    };
    const unsigned int edges[][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}
    };
    Vec3 projected[sizeof(vertices) / sizeof(vertices[0])];
    const Mat4 projection = mat4_perspective(
        1.0471975512f,
        (float)VIEW_WIDTH / (float)VIEW_HEIGHT,
        0.1f,
        100.0f
    );

    for (size_t i = 0; i < sizeof(vertices) / sizeof(vertices[0]); ++i) {
        if (!mat4_project_point(projection, vertices[i], &projected[i])) {
            framebuffer_free(&buffer);
            return 1;
        }
    }

    for (size_t i = 0; i < sizeof(edges) / sizeof(edges[0]); ++i) {
        const Vec3 a = projected[edges[i][0]];
        const Vec3 b = projected[edges[i][1]];
        raster_line(
            &buffer,
            screen_x(a.x), screen_y(a.y),
            screen_x(b.x), screen_y(b.y),
            '#'
        );
    }

    framebuffer_present(&buffer);
    framebuffer_free(&buffer);
    return 0;
}
