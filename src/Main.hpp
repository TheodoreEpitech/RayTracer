/*
** EPITECH PROJECT, 2024
** B-OOP-400-TLS-4-1-raytracer-leo.wehrle [WSL: Ubuntu]
** File description:
** Main
*/

#pragma once
#include "Camera.hpp"
#include "Parameters.hpp"
#include "Primitives/Sphere.hpp"
#include "Scene/IncrementalImage.hpp"
#include "Scene/World.hpp"

class Main {
public:
    Main(int ac, char *av[]):
        _ac(ac),
        _av(av)
    {
    }
    ~Main() = default;

    int _ac;
    char **_av;
    Parameters _params;
    Camera _camera;
    World _world;
    IncrementalImage _image;

    auto run() -> int;
    auto render_real_time(WorldCreator &creator) -> void;
    auto arg_parse() -> bool;

protected:
private:
};
