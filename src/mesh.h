#ifndef TERM3D_MESH_H
#define TERM3D_MESH_H

#include <stddef.h>

#include "vec3.h"

typedef struct {
    unsigned int a;
    unsigned int b;
} MeshEdge;

typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int c;
} MeshTriangle;

typedef struct {
    const Vec3 *vertices;
    size_t vertex_count;
    const MeshEdge *edges;
    size_t edge_count;
    const MeshTriangle *triangles;
    size_t triangle_count;
} Mesh;

const Mesh *mesh_cube(void);

#endif
