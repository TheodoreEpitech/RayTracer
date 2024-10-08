/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-raytracer-leo.wehrle [WSL: Ubuntu]
** File description:
** Point3D
*/

#pragma once
#include "Vector3D.hpp"
#include <iostream>

#ifndef USING_POINT3D
using Point3D = class Vector3D;
#else
class Point3D {
public:
    float _x = 0;
    float _y = 0;
    float _z = 0;

    Point3D() = default;
    Point3D(float x, float y, float z):
        _x(x),
        _y(y),
        _z(z) {};

    inline Point3D operator+(const Vector3D &vector) const
    {
        return Point3D(_x + vector._x, _y + vector._y, _z + vector._z);
    }

    inline Point3D &operator+=(const Point3D &dot)
    {
        _x += dot._x;
        _y += dot._y;
        _z += dot._z;

        return (*this);
    }

    inline Point3D operator-(const Vector3D &vector) const
    {
        return Point3D(_x - vector._x, _y - vector._y, _z - vector._z);
    }

    inline Vector3D operator-(const Point3D &point) const
    {
        return Vector3D(_x - point._x, _y - point._y, _z - point._z);
    }

    inline Point3D operator*(float scalar) const { return Point3D(_x * scalar, _y * scalar, _z * scalar); }

    inline Point3D operator+(const Point3D &point) const
    {
        return Point3D(_x + point._x, _y + point._y, _z + point._z);
    }

    friend std::ostream &operator<<(std::ostream &os, const Point3D &point);
};
#endif // USING_POINT3D
