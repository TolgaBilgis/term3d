#ifndef TERM3D_FRAMEBUFFER_H
#define TERM3D_FRAMEBUFFER_H

#include <stdbool.h>

typedef struct {
    int width;
    int height;
    char *cells;
} Framebuffer;

bool framebuffer_init(Framebuffer *buffer, int width, int height);
void framebuffer_free(Framebuffer *buffer);
void framebuffer_clear(Framebuffer *buffer, char fill);
void framebuffer_put(Framebuffer *buffer, int x, int y, char glyph);
void framebuffer_present(const Framebuffer *buffer);

#endif
