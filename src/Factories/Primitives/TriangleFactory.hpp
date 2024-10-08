/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** TriangleFactory
*/

#pragma once

#include "Primitives/Triangle.hpp"
#include "Factories/Math/Point3DFactory.hpp"
#include "Factories/MaterialFactory.hpp"
#include <list>
#include <boost/property_tree/ptree.hpp>

class TriangleFactory : public MaterialFactory, public Point3DFactory {
public:
    TriangleFactory() = default;
    ~TriangleFactory() = default;

    std::unique_ptr<Triangle> createTriangle(const boost::property_tree::ptree &pt) const;

private:
    const std::list<std::string> valid_transformations = {
        "translation",
        "rotation"
    };
};
