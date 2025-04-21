/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cone
*/

#pragma once

#include "APrimitive.hpp"
#include "Ray.hpp"
#include "Vector3f.hpp"
#include "Api.hpp"

namespace Plugin {
    class Cone : public Raytracer::APrimitive {
        public:
            Cone(const Component::Vector3f &position, const Component::Vector3f &rotation, double angleM);
            ~Cone() override;

            [[nodiscard]] double intersect(const Raytracer::Ray &ray) const override;

            [[nodiscard]] Component::Vector3f getNormal(const Component::Vector3f &hitPoint) const override;

        protected:
        private:
            double _angleM;
    };
}
