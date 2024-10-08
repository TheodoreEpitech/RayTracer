/*
** EPITECH PROJECT, 2024
** RayBan
** File description:
** Sphere
*/

#include "Sphere.hpp"

bool Sphere::hits(const Ray &ray, Interval ray_d, HitRecord &hitrec) const
{
    /* formula:
        * ray = origin + t * direction
        * sphere = (x - center)^2 + (y - center)^2 + (z - center)^2 = radius^2
        * substitute ray into sphere equation
        * (origin + t * direction - center)^2 = radius^2
        * a = direction * direction
        * b = 2 * direction * (origin - center)
        * c = (origin - center) * (origin - center) - radius^2
        * discriminant = b^2 - 4ac
        * if discriminant < 0, no real roots
        * if discriminant = 0, one real root
        * if discriminant > 0, two real roots
        * roots = (-b +- sqrt(discriminant)) / 2a
        */
        Vector3D oc = origin - ray.origin();
        float a = ray.direction().length_squared();
        float b = ray.direction().dot(oc);
        float c = oc.length_squared() - _radius * _radius;

        float discriminant = b * b - a * c;
        if (discriminant < 0) {
            return false;
        }

        float sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        float root = (b - sqrtd) / a;
        if (!ray_d.surrounds(root)) {
            root = (b + sqrtd) / a;
            if (!ray_d.surrounds(root))
                return false;
        }

        hitrec.t = root;
        hitrec.p = ray.at(hitrec.t);
        Vector3D outward_normal = (hitrec.p - origin) / _radius;
        hitrec.set_face_normal(ray, outward_normal);
        get_sphere_uv(outward_normal, hitrec.u, hitrec.v);
        hitrec.material = material;

        return true;
}

void Sphere::get_sphere_uv(const Vector3D &p, float &u, float &v) const
{
    float theta = std::acos(-p._y);
    float phi = std::atan2(-p._z, p._x) + M_PIf;

    u = phi / (2 * M_PIf);
    v = theta / M_PIf;
}

void Sphere::translate(const Point3D &trans)
{
    origin += trans;
}
