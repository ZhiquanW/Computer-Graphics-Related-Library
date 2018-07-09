//
// Created by ZhiquanWang on 2018/7/9.
//
#include <iostream>
#include "../src/Vector3.h"

using namespace std;

int main() {
    //创建三个Vector3 向量对象
    Vector3 v1(-1.2, 5, 199.9);
    Vector3 v2(1, 1, 2);
    Vector3 v3(1.4, 5, 7.6);
    //输入输出流
    Vector3 tmp_v;
    cin >> tmp_v;
    cout << tmp_v << endl;
    //算术运算:加,减,乘,除
    cout << v1 << " + " << v2 << " = " << v1 + v2 << endl;
    cout << v1 << " - " << v2 << " = " << v1 - v2 << endl;
    cout << v1 << " * " << v2 << " = " << v1 * v2 << endl;
    cout << v1 << " / " << v2 << " = " << v1 / v2 << endl;
    //取负
    cout << "-" << v1 << " = " << -v1 << endl;
    //关系运算符
    cout << v1 << " == " << v2 << " : " << (v1 == v2) << endl;
    cout << v1 << " == " << v1 << " : " << (v1 == v1) << endl;
    cout << v1 << " != " << v2 << " : " << (v1 != v2) << endl;
    cout << v1 << " != " << v1 << " : " << (v1 != v1) << endl;
    //赋值运算符
    cout << "= : " << v3 << " = " << v1 << " : ";
    v3 = v1;
    cout << v3 << endl;

    cout << "+= : " << v3 << " += " << v1 << " : ";
    v3 += v1;
    cout << v3 << endl;

    cout << "-= : " << v3 << " -= " << v1 << " : ";
    v3 -= v1;
    cout << v3 << endl;

    cout << "*= : " << v3 << " *= " << v1 << " : ";
    v3 *= v1;
    cout << v3 << endl;

    cout << "*= : " << v3 << " *= " << -0.5 << " : ";
    v3 *= -0.5;
    cout << v3 << endl;

    cout << "/= : " << v3 << " /= " << v1 << " : ";
    v3 /= v1;
    cout << v3 << endl;

    cout << "/= : " << v3 << " /= " << -0.5 << " : ";
    v3 /= -0.5;
    cout << v3 << endl;
    //RGB
    cout << "R: " << v1.r() << " G: " << v1.g() << " B: " << v1.b() << endl;
    //XYZ
    cout << "X: " << v1.x() << " Y: " << v1.y() << " Z: " << v1.z() << endl;
    //索引
    for(int i = 0; i< 3;++ i){
        cout <<"vec[" << i <<"]: " << v1[i] << " ";
    }cout << endl;
    cout<<"索引赋值 : ";
    for(int i =0 ;i < 3;++ i){
        v1[i] = 2.0;
    }
    cout << v1 << endl;
    //长度与归一化
    cout << "Length: " << v1.length() << endl;
    cout << "Normalize: " << v1.normalize() << endl;

}