/*
** EPITECH PROJECT, 2024
** RayBan
** File description:
** Triangle
*/

#include "Triangle.hpp"

bool Triangle::hits(const Ray &ray, Interval ray_d, HitRecord &hitrec) const
{
    const float EPSILON = std::numeric_limits<float>::epsilon();
        Vector3D edge1 = _v1 - _v0;
        Vector3D edge2 = _v2 - _v0;

        Vector3D pvec = ray.direction().cross(edge2);
        float det = edge1.dot(pvec);
        if (det > -EPSILON && det < EPSILON)
            return false;

        float inv_det = static_cast<float>(1.0 / det);
        Vector3D tvec = ray.origin() - _v0;
        float u = inv_det * tvec.dot(pvec);
        if (u < 0.0 || u > 1.0)
            return false;

        Vector3D qvec = tvec.cross(edge1);
        float v = inv_det * ray.direction().dot(qvec);
        if (v < 0.0 || u + v > 1.0)
            return false;

        float t = inv_det * edge2.dot(qvec);
        if (t > EPSILON && ray_d.surrounds(t)) {
            hitrec.t = t;
            hitrec.p = ray.at(t);
            hitrec.normal = _normal;
            hitrec.material = _material;
            return true;
        }
    return false;
}

void Triangle::translate(const Point3D &trans)
{
    _v0 += trans;
    _v1 += trans;
    _v2 += trans;
}
