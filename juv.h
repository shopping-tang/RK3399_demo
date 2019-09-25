#ifndef __JYUV_H
#define __JYUV_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#pragma pack(1)

struct bmp_header_t{
    u16        magic;
    u32       file_size;
    u32       RESERVED1;
    u32       offset;         //54 bytes 

    u32       head_num;    //40
    u32       width;
    u32       height;
    u16       color_planes; //1
    u16       bit_count;
    u32       bit_compression; //0
    u32       image_size; //except the size of header
    u32       h_resolution;
    u32       v_resolution;
    u32       color_num;
    u32       important_colors;
};

#pragma pack()

void set_bmp_header(struct bmp_header_t * header, u32 width, u32 height);
int yuyv2rgb24(u8 *yuyv, u8 *rgb, u32 width, u32 height);

#endif /* __JYUV_H */
