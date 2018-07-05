//
// Created by mySabrehawk on 2018/7/4.
//

#ifndef MATRIXOPERATION_CPP_VECTOR3_H
#define MATRIXOPERATION_CPP_VECTOR3_H


#include <iosfwd>

class vector3 {
private:
    double vec3[3];
public:
    vector3();

    vector3(double, double, double);

    inline double x() const;

    inline double y() const;

    inline double z() const;

    inline double r() const;

    inline double g() const;

    inline double b() const;

    inline const vector3 &operator+() const;

    inline const vector3 &operator-();

    inline double operator[](int) const;

    inline double &operator[](int);

    inline vector3 &operator+=(const vector3 &);

    inline vector3 &operator-=(const vector3 &);

    inline vector3 &operator*=(const vector3 &);

    inline vector3 &operator*=(const double &);

    inline vector3 &operator/=(const vector3 &);

    inline vector3 &operator/=(const double &);

    inline double length() const;

    inline const vector3 & normalize();

};

inline std::istream &operator>>(std::istream &, vector3 &);

inline std::ostream &operator<<(std::ostream &, const vector3 &);

inline double dot(const vector3 &, const vector3 &);

inline vector3 cross(const vector3 &, const vector3 &);

inline vector3 operator+(const vector3 &, const vector3 &);

inline vector3 operator-(const vector3 &, const vector3 &);

inline vector3 operator*(const vector3 &, const vector3 &);

inline vector3 operator*(const vector3 &, const double &);

inline vector3 operator/(const vector3 &, const vector3 &);

inline vector3 operator/(const vector3 &

.const double &);

#endif //MATRIXOPERATION_CPP_VECTOR3_H
