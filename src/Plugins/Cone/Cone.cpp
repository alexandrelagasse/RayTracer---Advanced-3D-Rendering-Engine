/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Cone
*/

#include <iostream>
#include <map>
#include "Cone.hpp"

static const std::string coneName = "Cone";

namespace Plugin {
    Cone::Cone(const Component::Vector3f &position, const Component::Vector3f &rotation, double angleM)
        : APrimitive(coneName, position, rotation), _angleM(angleM)
    {
    }

    Cone::~Cone() = default;

    double Cone::intersect(const Raytracer::Ray &ray) const
    {
        double tanTheta = std::tan(_angleM);
        Component::Vector3f origin = ray.origin;
        Component::Vector3f direction = ray.direction;

        double a = direction.x * direction.x + direction.z * direction.z - (direction.y * direction.y) / (tanTheta * tanTheta);
        double b = 2 * (origin.x * direction.x + origin.z * direction.z - (origin.y * direction.y) / (tanTheta * tanTheta));
        double c = origin.x * origin.x + origin.z * origin.z - (origin.y * origin.y) / (tanTheta * tanTheta);
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return -1;
        }

        double t1 = (-b - std::sqrt(discriminant)) / (2*a);
        double t2 = (-b + std::sqrt(discriminant)) / (2*a);

        Component::Vector3f intersect1 = origin + direction * t1;
        Component::Vector3f intersect2 = origin + direction * t2;

        if (t1 > 0 && intersect1.y <= 0 && (t2 <= 0 || t1 < t2)) {
            return t1;
        } else if (t2 > 0 && intersect2.y <= 0) {
            return t2;
        }
        return -1;
    }

    Component::Vector3f Cone::getNormal(const Component::Vector3f &hitPoint) const
    {
        double tanTheta = std::tan(_angleM);
        Component::Vector3f P = hitPoint;
        return Component::Vector3f(2 * P.x, -2 * P.y/(tanTheta * tanTheta), 2 * P.z);
    }
}

extern "C" {

    Raytracer::IEntity *createEntity(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting) {
        Component::Vector3f position(std::get<double>(setting.find("position_x")->second),
                                     std::get<double>(setting.find("position_y")->second),
                                     std::get<double>(setting.find("position_z")->second));
        Component::Vector3f rotation(std::get<double>(setting.find("rotation_x")->second),
                                    std::get<double>(setting.find("rotation_y")->second),
                                    std::get<double>(setting.find("rotation_z")->second));
        double angle = std::get<double>(setting.find("angle")->second);
        return new Plugin::Cone(position, rotation, angle);
    }

    const char *getName() {
        return coneName.c_str();
    }

    LibType getType() {
        return LibType::ENTITY;
    }

    void destroyEntity(Raytracer::IEntity *entity) {
        std::cout << "destroy cone" << std::endl;
        delete entity;
    }
}
