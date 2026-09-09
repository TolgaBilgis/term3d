#include "framebuffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool framebuffer_init(Framebuffer *buffer, int width, int height)
{
    if (!buffer || width <= 0 || height <= 0) {
        return false;
    }

    buffer->cells = malloc((size_t)width * (size_t)height);
    if (!buffer->cells) {
        buffer->width = 0;
        buffer->height = 0;
        return false;
    }

    buffer->width = width;
    buffer->height = height;
    framebuffer_clear(buffer, ' ');
    return true;
}

void framebuffer_free(Framebuffer *buffer)
{
    if (!buffer) {
        return;
    }

    free(buffer->cells);
    buffer->cells = NULL;
    buffer->width = 0;
    buffer->height = 0;
}

void framebuffer_clear(Framebuffer *buffer, char fill)
{
    if (!buffer || !buffer->cells) {
        return;
    }

    memset(buffer->cells, fill, (size_t)buffer->width * (size_t)buffer->height);
}

void framebuffer_put(Framebuffer *buffer, int x, int y, char glyph)
{
    if (!buffer || !buffer->cells || x < 0 || y < 0 ||
        x >= buffer->width || y >= buffer->height) {
        return;
    }

    buffer->cells[y * buffer->width + x] = glyph;
}

void framebuffer_present(const Framebuffer *buffer)
{
    if (!buffer || !buffer->cells) {
        return;
    }

    for (int y = 0; y < buffer->height; ++y) {
        fwrite(&buffer->cells[y * buffer->width], sizeof(char), (size_t)buffer->width, stdout);
        putchar('\n');
    }
}
