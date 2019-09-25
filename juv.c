#include "j-yuv.h"

#define BIT_COUNT   24

void set_bmp_header(struct bmp_header_t *header, u32 width, u32 height)
{
    header->magic = 0x4d42;
    header->image_size = width * height * BIT_COUNT/8;
    header->file_size = header->image_size + 54;
    header->RESERVED1 = 0;
    header->offset = 54;

    header->head_num = 40;
    header->width = width;
    header->height = height;
    header->color_planes = 1;
    header->bit_count = BIT_COUNT;
    header->bit_compression = 0;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->color_num = 0;
    header->important_colors = 0;
}

int yuyv2rgb24(u8 *yuyv, u8 *rgb, u32 width, u32 height)
{
    u32 i, in, rgb_index = 0;
    u8 y0, u0, y1, v1;
    int r, g, b;
    u32 out = 0, x, y;

    for(in = 0; in < width * height * 2; in += 4)
    {
    y0 = yuyv[in+0];
    u0 = yuyv[in+1];
    y1 = yuyv[in+2];
    v1 = yuyv[in+3];

    for (i = 0; i < 2; i++)
    {
        if (i)
            y = y1;
        else
            y = y0;
        r = y + (140 * (v1-128))/100;  //r
        g = y - (34 * (u0-128))/100 - (71 * (v1-128))/100; //g
        b = y + (177 * (u0-128))/100; //b
        if(r > 255)   r = 255;
            if(g > 255)   g = 255;
            if(b > 255)   b = 255;
            if(r < 0)     r = 0;
            if(g < 0)     g = 0;
            if(b < 0)     b = 0;

        y = height - rgb_index/width -1;
        x = rgb_index%width;
        rgb[(y*width+x)*3+0] = b;
        rgb[(y*width+x)*3+1] = g;
        rgb[(y*width+x)*3+2] = r;
        rgb_index++;
    }
    }
    return 0;
}

