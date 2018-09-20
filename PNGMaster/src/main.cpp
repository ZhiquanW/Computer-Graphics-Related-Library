//
// Created by ZhiquanWang on 2018/7/9.
//
#include "PNGMaster.h"
int main(){
    //生成对象,设置图片大小:高*宽
    //像素标记方式,从上到下,从左到右
    PNGMaster new_pic(255,255);
    for(int i = 0;i < 255;++ i){
        for(int j = 0;j < 255;++ j){
            //设置指定位置的像素
            //setpixel()参数:(横坐标,纵坐标,R,G,B)
            new_pic.setPixel(i,j,i,(255-j),(i+j)/2);
        }
    }
    //设置名称,并生成图片
    //注意文件后缀名'.png'
    new_pic.genPNG("test.png");
    return 0;
}
