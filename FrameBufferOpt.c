#include "FrameBufferOpt.h"

static int Frame_fd ;
static int *FrameBuffer = NULL ;
static int W , H ;


int Init_FrameBuffer(int Width , int Higth)
{
    W = Width ;
    H = Higth ;
    Frame_fd = open("/dev/fb0" , O_RDWR);
    if(-1 == Frame_fd)
    {
        perror("open frame buffer fail");
        return -1 ;
    }


FrameBuffer = mmap(0, 1280*1024*4 , PROT_READ | PROT_WRITE , MAP_SHARED , Frame_fd ,0 );
    if(FrameBuffer == (void *)-1)
    {
        perror("memory map fail");
        return -2 ;
    }
    return 0 ;
}

int Write_FrameBuffer(const char *buffer)
{
    int row  , col ;
    char *p = NULL ;
    for(row = 0 ; row <1024 ; row++)
    {
        for(col = 0 ; col < 1280 ;  col++)
        {
            if((row < H)  && (col < W))
            {
                p = (char *)(buffer + (row * W+ col ) * 3);
                FrameBuffer[row*1280+col] = RGB((unsigned char)(*(p+2)),(unsigned char)(*(p+1)),(unsigned char )(*p));
            }
        }
    }
    return 0 ;
}


int Exit_Framebuffer(void)
{
    munmap(FrameBuffer ,  W*H*4);
    close(Frame_fd);
    return 0 ;
}

