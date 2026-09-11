#include "mesh.h"

static const Vec3 CUBE_VERTICES[] = {
    {-1.0f, -1.0f, -1.0f},
    { 1.0f, -1.0f, -1.0f},
    { 1.0f,  1.0f, -1.0f},
    {-1.0f,  1.0f, -1.0f},
    {-1.0f, -1.0f,  1.0f},
    { 1.0f, -1.0f,  1.0f},
    { 1.0f,  1.0f,  1.0f},
    {-1.0f,  1.0f,  1.0f}
};

static const MeshEdge CUBE_EDGES[] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {4, 5}, {5, 6}, {6, 7}, {7, 4},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

static const Mesh CUBE = {
    CUBE_VERTICES,
    sizeof(CUBE_VERTICES) / sizeof(CUBE_VERTICES[0]),
    CUBE_EDGES,
    sizeof(CUBE_EDGES) / sizeof(CUBE_EDGES[0])
};

const Mesh *mesh_cube(void)
{
    return &CUBE;
}
