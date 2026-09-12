#ifndef TERM3D_RASTER_H
#define TERM3D_RASTER_H

#include "framebuffer.h"

void raster_line(Framebuffer *buffer, int x0, int y0, int x1, int y1, char glyph);
void raster_triangle_wireframe(
    Framebuffer *buffer,
    int x0, int y0,
    int x1, int y1,
    int x2, int y2,
    char glyph
);

#endif
