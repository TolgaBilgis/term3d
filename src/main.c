#include <stdio.h>

#include "framebuffer.h"
#include "mat4.h"
#include "mesh.h"
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

    const Mesh *mesh = mesh_cube();
    Vec3 projected[mesh->vertex_count];
    const Mat4 model = mat4_translation(0.0f, 0.0f, -5.0f);
    const Mat4 projection = mat4_perspective(
        1.0471975512f,
        (float)VIEW_WIDTH / (float)VIEW_HEIGHT,
        0.1f,
        100.0f
    );

    for (size_t i = 0; i < mesh->vertex_count; ++i) {
        const Vec3 world = mat4_transform_point(model, mesh->vertices[i]);
        if (!mat4_project_point(projection, world, &projected[i])) {
            framebuffer_free(&buffer);
            return 1;
        }
    }

    for (size_t i = 0; i < mesh->edge_count; ++i) {
        const MeshEdge edge = mesh->edges[i];
        const Vec3 a = projected[edge.a];
        const Vec3 b = projected[edge.b];
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
