/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cylinder
*/

#pragma once

#include "APrimitive.hpp"
#include "Vector3f.hpp"

namespace Plugin {
    class Cylinder : public Raytracer::APrimitive {
        public:
            Cylinder(const Component::Vector3f &position, const Component::Vector3f &rotation, double radius, double height,
                    Component::Vector3f &basePoint, Component::Vector3f &topPoint);

            ~Cylinder() override;

            [[nodiscard]] double intersect(const Raytracer::Ray &ray) const override;

            [[nodiscard]] Component::Vector3f getNormal(const Component::Vector3f &hitPoint) const override;

        protected:
        private:
            static Component::Vector3f calculateCylinderAxis(const Component::Vector3f &basePoint, const Component::Vector3f &topPoint);

            double _radius;
            double _height;
            Component::Vector3f _axis;
    };
}
