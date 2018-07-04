//
// Created by mySabrehawk on 2018/7/4.
//

#include "vector3.h"

vector3::vector3() {

}

vector3::vector3(double _n0,double _n1,double _n2) {
    this->vec3[0] = _n0;
    this->vec3[1] = _n1;
    this->vec3[2] = _n2;
}

double vector3::x() const {
    return this->vec3[0];
}

double vector3::y() const {
    return this->vec3[1];
}

double vector3::z() const{
    return this->vec3[2];
}

double vector3::r() const {
    return this->vec3[0];
}

double vector3::g() const {
    return this->vec3[1];
}

double vector3::b() const{
    return this->vec3[2];
}