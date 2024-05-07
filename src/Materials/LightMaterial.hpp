/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** LightMaterial
*/

#pragma once

#include "AMaterial.hpp"
#include "Color.hpp"
#include "HitRecord.hpp"
#include "Math/MathsUtils.hpp"
#include "Math/Point3D.hpp"
#include "Ray.hpp"
#include "Textures/ITexture.hpp"
#include "Textures/SolidColorTexture.hpp"
#include <memory>

class LightMaterial : public AMaterial {
public:
    LightMaterial(std::unique_ptr<ITexture> tex):
        texture(std::move(tex))
    {
    }
    LightMaterial(const Color &emit):
        texture(std::make_unique<SolidColorTexture>(emit))
    {
    }

    Color emitted(float u, float v, const Point3D &p) const override { return texture->value(u, v, p); }

private:
    std::unique_ptr<ITexture> texture;
};
