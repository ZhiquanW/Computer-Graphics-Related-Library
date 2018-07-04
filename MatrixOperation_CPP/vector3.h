//
// Created by mySabrehawk on 2018/7/4.
//

#ifndef MATRIXOPERATION_CPP_VECTOR3_H
#define MATRIXOPERATION_CPP_VECTOR3_H


class vector3 {
private:
    double vec3[3];
public:
    vector3();
    vector3(double,double,double);

    inline double x() const;
    inline double y() const;
    inline double z() const;
    inline double r() const;
    inline double g() const;
    inline double b() const;

    inline const vector3 &operator + () const;
    inline const vector3 &operator - () ;
    inline double operator[] (int _i) const;
    inline double& operator[] (int _i);

    inline vector3 &operator += (const vector3& _v);
    inline vector3 &operator -= (const vector3& _v);
    inline vector3 &operator *= (const vector3& _v);
    inline vector3 &operator *= (const float f);
    inline vector3 &operator /= (const vector3& _v);
    inline vector3 &operator /= (const float f);

    inline double length() const;
    inline void normalize();
    
};


#endif //MATRIXOPERATION_CPP_VECTOR3_H
