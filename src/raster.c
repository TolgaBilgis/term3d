#include "raster.h"

#include <stdlib.h>

void raster_line(Framebuffer *buffer, int x0, int y0, int x1, int y1, char glyph)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;

    for (;;) {
        framebuffer_put(buffer, x0, y0, glyph);
        if (x0 == x1 && y0 == y1) {
            break;
        }

        int doubled = 2 * error;
        if (doubled >= dy) {
            error += dy;
            x0 += sx;
        }
        if (doubled <= dx) {
            error += dx;
            y0 += sy;
        }
    }
}

void raster_triangle_wireframe(
    Framebuffer *buffer,
    int x0, int y0,
    int x1, int y1,
    int x2, int y2,
    char glyph
)
{
    raster_line(buffer, x0, y0, x1, y1, glyph);
    raster_line(buffer, x1, y1, x2, y2, glyph);
    raster_line(buffer, x2, y2, x0, y0, glyph);
}
