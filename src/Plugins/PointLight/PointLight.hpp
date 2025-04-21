/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight
*/

#pragma once

#include "ALight.hpp"

namespace Plugin {
    class PointLight : public Raytracer::ALight {
    public:
        PointLight(const Component::Vector3f &position, const Component::Vector3f &rotation, const Component::Color &color, double intensity);

        ~PointLight() override = default;

        [[nodiscard]] bool isIlluminating(const Component::Vector3f &origin, const Component::Vector3f &direction) const override;
    };
}

