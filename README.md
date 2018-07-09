# Computer-Graphics-Related-Library

---

计算机图形学编程相关库 C++

### 1) PNGMaster

#### 特性

* 用于生成PNG图片,支持RGB或RGBA两种形式
* 对SVPNG的二次封装,更加简单

#### 样例

将*PNGMaster.h* 与*svpng.inc* 添加到工程中

> \#include "PNGMaster.h"
>
> int main(){
>
> ​    //生成对象,设置图片大小:高*宽
>
> ​    //像素标记方式,从上到下,从左到右
>
> ​    PNGMaster new_pic(255,255);
>
> ​    for(int i = 0;i < 255;++ i){
>
> ​        for(int j = 0;j < 255;++ j){
>
> ​            //设置指定位置的像素
>
> ​            //setpixel()参数:(横坐标,纵坐标,R,G,B)
>
> ​            new_pic.setPixel(i,j,i,(255-j),(i+j)/2);
>
> ​        }
>
> ​    }
>
> ​    //设置名称,并生成图片
>
> ​    //注意文件后缀名'.png'
>
> ​    new_pic.genPNG("test.png");
>
> ​    return 0;
>
> }

#### 编译运行

* Ubuntu : 

  > g++ main.cpp -o exc && ./exc

* 其余IDE编译运行即可