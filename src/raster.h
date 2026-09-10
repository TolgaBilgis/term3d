#ifndef TERM3D_RASTER_H
#define TERM3D_RASTER_H

#include "framebuffer.h"

void raster_line(Framebuffer *buffer, int x0, int y0, int x1, int y1, char glyph);

#endif
