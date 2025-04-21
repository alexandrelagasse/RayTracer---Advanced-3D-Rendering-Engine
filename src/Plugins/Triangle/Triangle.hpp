/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Triangle
*/

#pragma once

#include "APrimitive.hpp"
#include "Matrix.hpp"

namespace Plugin {
    class Triangle : public Raytracer::APrimitive {
        public:
            Triangle(Component::Matrix3x3 &matrix, Component::Vector3f &position, Component::Vector3f &rotation);
            ~Triangle() override = default;

            [[nodiscard]] double intersect(const Raytracer::Ray &ray) const override;
            
            [[nodiscard]] Component::Vector3f getNormal(const Component::Vector3f &hitPoint) const override;

        protected:
        private:
            Component::Matrix3x3 _matrix;
    };
}
