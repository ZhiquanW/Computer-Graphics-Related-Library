//
// Created by ZhiquanWang on 2018/7/9.
//
#ifndef _SH_PNGMASTER_
#define _SH_PNGMASTER_


#include "svpng.inc"

#include <cstring>
#include <iostream>

using namespace std;


class PNGMaster{
  private:
    unsigned int height;          //图片像素高度
    unsigned int width;           //图片像素宽度
    unsigned char *data;         //存储颜色信息指针
    const unsigned int dimension; //颜色维度

  public:

    PNGMaster(unsigned  int _h, unsigned int _w) : dimension(4){
        height  = _h;
        width = _w;
        data = new unsigned char[_h*_w*dimension];
    }

    void setPixel(int _x, int _y, int _r, int _g, int _b, int _a = 1){
        data[_x * height + _y * 4] = (unsigned char)_r;
        data[_x * height + _y * 4 + 1] = (unsigned char)_g;
        data[_x * height + _y * 4 + 2] = (unsigned char)_b;
        data[_x * height + _y * 4 + 3] = (unsigned char)_a;
    }

    void genPNG(const char * _name){
        FILE *fp = fopen(_name, "wb");
        unsigned char * tmp_p = data;
        for (int x = 0; x < height; x++){
            for (int y = 0; y < width; y++){
                *tmp_p++ = (unsigned char)x;
                *tmp_p++ = (unsigned char)y;
                *tmp_p++ = (unsigned char)128;
                *tmp_p++ = (unsigned char)((x + y) / 2);
            }
        }
        svpng(fp, height, width, data, 1);
        fclose(fp);
    }

    ~PNGMaster(){
        delete[] data;
    }
};
#endif
