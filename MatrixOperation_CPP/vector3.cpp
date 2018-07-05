//
// Created by mySabrehawk on 2018/7/4.
//

#include "vector3.h"
#include <cmath>

vector3::vector3() {

}

vector3::vector3(double _n0, double _n1, double _n2) {
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

double vector3::z() const {
    return this->vec3[2];
}

double vector3::r() const {
    return this->vec3[0];
}

double vector3::g() const {
    return this->vec3[1];
}

double vector3::b() const {
    return this->vec3[2];
}

inline const vector3 &vector3::operator+() const {
    return *this;
}

inline const vector3 &vector3::operator-() {
    return *this * -1;
}

inline double vector3::operator[](int _i) const {
    return this->vec3[_i];
}

inline double &vector3::operator[](int _i) {
    return this->vec3[_i];
}

inline vector3 &vector3::operator+=(const vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        this->vec3[i] += _v[i];
    }
    return *this;
}

inline vector3 &vector3::operator-=(const vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        this->vec3[i] -= _v[i];
    }
    return *this;
}

inline vector3 &vector3::operator*=(const vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        this->vec3[i] *= _v[i];
    }
    return *this;
}

inline vector3 &vector3::operator*=(const double &_d) {
    for (double &data:this->vec3) {
        data *= _d;
    }
    return *this;
}

inline vector3 &vector3::operator/=(const vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        this->vec3[i] /= _v[i];
    }
    return *this;
}

inline vector3 &vector3::operator/=(const double &_d) {
    for (double &data : this->vec3) {
        data /= _d;
    }
    return *this;
}

inline double vector3::length() const {
    return sqrt(this->vec3[0] * this->vec3[0] + this->vec3[1] * this->vec3[1] + this->vec3[2] * this->vec3[2]);
}

inline const vector3 &vector3::normalize() {
    for (double &data:this->vec3) {
        data /= length();
    }
    return *this;
}
