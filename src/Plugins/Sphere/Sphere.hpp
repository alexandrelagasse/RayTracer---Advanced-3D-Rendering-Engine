/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#pragma once

#include "APrimitive.hpp"
#include "Ray.hpp"
#include "Vector3f.hpp"

namespace Plugin {
    class Sphere : public Raytracer::APrimitive {
        public:
            Sphere(const Component::Vector3f &position, const Component::Vector3f &rotation, double radius);

            ~Sphere() override = default;

            [[nodiscard]] double intersect(const Raytracer::Ray &ray) const override;

            [[nodiscard]] Component::Vector3f getNormal(const Component::Vector3f &hit_point) const override;

        protected:

        private:
            double _radius;

    };
}
