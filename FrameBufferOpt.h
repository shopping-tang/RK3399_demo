#ifndef  _FRAMEBUFFEROPT_H
#define  _FRAMEBUFFEROPT_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>


#define    RGB(r,g,b)       ((r<<16)|(g<<8)|b)


int Init_FrameBuffer(int Width , int Higth);


int Write_FrameBuffer(const char *buffer);


int Exit_Framebuffer(void);



#endif //_FRAMEBUFFEROPT_H
