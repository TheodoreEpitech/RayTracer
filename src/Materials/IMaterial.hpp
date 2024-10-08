/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IMarterial
*/

#pragma once

#include "Color.hpp"
#include "Math/Point3D.hpp"
#include "Ray.hpp"

class HitRecord;

class IMaterial {
public:
    virtual ~IMaterial() = default;

    virtual Color emitted(float u, float v, const Point3D &point) const = 0;

    virtual bool scatter(const Ray &r_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const = 0;
};
