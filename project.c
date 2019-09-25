#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "j-yuv.h"
#include "CameralOpt.h"
#include "FrameBufferOpt.h"

#define    WIDTH   640
#define    HIGHT   480

int main(void)
{
    char yuyv[WIDTH*HIGHT*2];
    char bmp[WIDTH*HIGHT*3];

//  set_bmp_header((struct bmp_header_t *)bmp, WIDTH, HIGHT);

    Init_Cameral(WIDTH , HIGHT );

    Init_FrameBuffer(WIDTH , HIGHT );


    Start_Cameral();

    int count = 0 ;
    while(1)
    {
        Get_Picture(yuyv);
        yuyv2rgb24(yuyv, bmp, WIDTH, HIGHT);
        Write_FrameBuffer(bmp);
//      printf("count:%d \n" , count++);
    }

    Stop_Cameral();

    Exit_Framebuffer();
   
    Exit_Cameral();

    return 0;
}

