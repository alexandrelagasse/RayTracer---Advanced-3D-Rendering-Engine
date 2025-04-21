/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight
*/

#pragma once

#include "ALight.hpp"

namespace Plugin {
    class DirectionalLight : public Raytracer::ALight {
        public:

        DirectionalLight(const Component::Vector3f &position, const Component::Vector3f &rotation, const Component::Color &color, double intensity,
                         const Component::Vector3f &direction);

        ~DirectionalLight() override = default;

            [[nodiscard]] bool isIlluminating(const Component::Vector3f &origin, const Component::Vector3f &direction) const override;
        private:
            Component::Vector3f _direction;
    };
}

