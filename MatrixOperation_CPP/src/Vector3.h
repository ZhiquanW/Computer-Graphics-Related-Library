//
// Created by ZhiquanWang on 2018/7/4.
//

#ifndef MATRIXOPERATION_CPP_Vector3_H
#define MATRIXOPERATION_CPP_Vector3_H


#include <iostream>
#include <cmath>

class Vector3 {
private:
    double vec3[3]{};
public:
    Vector3();

    Vector3(const Vector3 &);

    Vector3(double, double, double);

    inline void setVector(double,double,double);

    inline double x() const;

    inline double y() const;

    inline double z() const;

    inline double r() const;

    inline double g() const;

    inline double b() const;

    inline const Vector3 &operator+() const;

    inline Vector3 operator-();

    inline double operator[](int) const;

    inline double &operator[](int);

    inline Vector3 &operator+=(const Vector3 &);

    inline Vector3 &operator-=(const Vector3 &);

    inline Vector3 &operator*=(const Vector3 &);

    inline Vector3 &operator*=(const double &);

    inline Vector3 &operator/=(const Vector3 &);

    inline Vector3 &operator/=(const double &);

    inline bool operator==(const Vector3 &);

    inline bool operator!=(const Vector3 &);

    inline double length() const;

    inline const Vector3 &normalize();

};

Vector3::Vector3() = default;

Vector3::Vector3(const Vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        this->vec3[i] = _v[i];
    }
}

Vector3::Vector3(double _n0, double _n1, double _n2) {
    this->vec3[0] = _n0;
    this->vec3[1] = _n1;
    this->vec3[2] = _n2;
}

inline void Vector3::setVector(double _p0, double _p1, double _p2) {
    vec3[0] = _p0;
    vec3[1] = _p1;
    vec3[2] = _p2;
}

double Vector3::x() const {
    return this->vec3[0];
}

double Vector3::y() const {
    return this->vec3[1];
}

double Vector3::z() const {
    return this->vec3[2];
}

double Vector3::r() const {
    return this->vec3[0];
}

double Vector3::g() const {
    return this->vec3[1];
}

double Vector3::b() const {
    return this->vec3[2];
}

inline const Vector3 &Vector3::operator+() const {
    return *this;
}

inline Vector3 Vector3::operator-() {
    return Vector3(-1*this->vec3[0],-1*this->vec3[1],-1*this->vec3[2]);
}

inline double Vector3::operator[](int _i) const {
    return this->vec3[_i];
}

inline double &Vector3::operator[](int _i) {
    return this->vec3[_i];
}

inline Vector3 &Vector3::operator+=(const Vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        this->vec3[i] += _v[i];
    }
    return *this;
}

inline Vector3 &Vector3::operator-=(const Vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        this->vec3[i] -= _v[i];
    }
    return *this;
}

inline Vector3 &Vector3::operator*=(const Vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        this->vec3[i] *= _v[i];
    }
    return *this;
}

inline Vector3 &Vector3::operator*=(const double &_d) {
    for (double &data:this->vec3) {
        data *= _d;
    }
    return *this;
}

inline Vector3 &Vector3::operator/=(const Vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        this->vec3[i] /= _v[i];
    }
    return *this;
}

inline Vector3 &Vector3::operator/=(const double &_d) {
    for (double &data : this->vec3) {
        data /= _d;
    }
    return *this;
}

inline double Vector3::length() const {
    return sqrt(this->vec3[0] * this->vec3[0] + this->vec3[1] * this->vec3[1] + this->vec3[2] * this->vec3[2]);
}

inline const Vector3 &Vector3::normalize() {
    double tmp_len = this->length();
    for (double &data:this->vec3) {
        data /= tmp_len;
    }
    return *this;
}

inline bool Vector3::operator==(const Vector3 &_v) {
    for (int i = 0; i < 3; ++i) {
        if (this->vec3[i] != _v[i]) {
            return false;
        }
    }
    return true;
}

inline bool Vector3::operator!=(const Vector3 &_v) {
    return !(*this == _v);
}


inline std::istream &operator>>(std::istream &_is, Vector3 &_v) {
    _is >> _v[0] >> _v[1] >> _v[2];
    return _is;
}

inline std::ostream &operator<<(std::ostream &_os, const Vector3 &_v) {
    _os << "(" << _v[0] << "," << _v[1] << "," << _v[2] << ")";
    return _os;
}

inline double dot(const Vector3 &_v0, const Vector3 &_v1) {
    double tmp_result = 0;
    for (int i = 0; i < 3; ++i) {
        tmp_result += _v0[i] * _v1[i];
    }
    return tmp_result;
}

inline Vector3 cross(const Vector3 &_v0, const Vector3 _v1) {
    return {_v0[1] * _v1[2] - _v0[2] * _v1[1], _v0[2] * _v1[0] - _v0[0] * _v1[2], _v0[0] * _v1[1] - _v0[1] * _v1[0]};
}

inline Vector3 operator+(const Vector3 &_v0, const Vector3 &_v1) {
    return {_v0[0] + _v1[0], _v0[1] + _v1[1], _v0[2] + _v1[2]};
}

inline Vector3 operator-(const Vector3 &_v0, const Vector3 &_v1) {
    return {_v0[0] - _v1[0], _v0[1] - _v1[1], _v0[2] - _v1[2]};
}

inline Vector3 operator*(const Vector3 &_v0, const Vector3 &_v1) {
    return {_v0[0] * _v1[0], _v0[1] * _v1[1], _v0[2] * _v1[2]};
}

inline Vector3 operator*(const Vector3 &_v0, const double &_d) {
    return {_v0[0] * _d, _v0[1] * _d, _v0[2] * _d};
}

inline Vector3 operator*(const double &_d, const Vector3 &_v0) {
    return {_v0[0] * _d, _v0[1] * _d, _v0[2] * _d};
}

inline Vector3 operator/(const Vector3 &_v0, const Vector3 &_v1) {
    return {_v0[0] / _v1[0], _v0[1] / _v1[1], _v0[2] / _v1[2]};
}

inline Vector3 operator/(const Vector3 &_v0, const double &_d) {
    return {_v0[0] / _d, _v0[1] / _d, _v0[2] / _d};
}

#endif //MATRIXOPERATION_CPP_Vector3_H
