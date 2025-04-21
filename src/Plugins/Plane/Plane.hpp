/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane
*/

#pragma once

#include "APrimitive.hpp"
#include "Ray.hpp"
#include "Vector3f.hpp"

namespace Plugin {
    class Plane : public Raytracer::APrimitive {
    public:
        Plane(const Component::Vector3f &position, const Component::Vector3f &rotation, const Component::Vector3f &normal);
        ~Plane() override = default;

        [[nodiscard]] double intersect(const Raytracer::Ray &ray) const override;
        [[nodiscard]] Component::Vector3f getNormal(const Component::Vector3f &hitPoint) const override;

    private:
        Component::Vector3f _normal;
    };
}

