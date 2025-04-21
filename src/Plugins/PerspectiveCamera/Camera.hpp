/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#pragma once

#include "Vector3f.hpp"
#include "ACam.hpp"

namespace Plugin {
    class Camera : public Raytracer::ACam {
    public:
        Camera(const Component::Vector3f &position, const Component::Vector3f &rotation, bool isEdited, double fieldOfView, const Component::Vector3f &resolution);

        ~Camera() override = default;
    };
}
