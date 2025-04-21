    /*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Plane
*/

#include <iostream>
#include <map>
#include "Api.hpp"
#include "Plane.hpp"

static const std::string PLANE = "Plane";

Plugin::Plane::Plane(const Component::Vector3f &position, const Component::Vector3f &rotation, const Component::Vector3f &normal)
        : APrimitive(PLANE, position, rotation), _normal(normal.normalize()) {}

double Plugin::Plane::intersect(const Raytracer::Ray &ray) const
{
    double denom = _normal.dot(ray.direction);

    if (std::abs(denom) < 1e-6) {
        return -1.0f;
    }
    double t = (_position - ray.origin).dot(_normal) / denom;
    return t >= 0 ? t : -1.0f;
}

Component::Vector3f Plugin::Plane::getNormal(const Component::Vector3f &hitPoint) const
{
    return _normal;
}

extern "C" {

    Raytracer::IEntity *createEntity(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting) {
        Component::Vector3f position(std::get<double>(setting.find("position_x")->second),
                                     std::get<double>(setting.find("position_y")->second),
                                     std::get<double>(setting.find("position_z")->second));
        Component::Vector3f normal(std::get<double>(setting.find("normal_x")->second),
                                   std::get<double>(setting.find("normal_y")->second),
                                   std::get<double>(setting.find("normal_z")->second));
        Component::Vector3f rotation(std::get<double>(setting.find("rotation_x")->second), std::get<double>(setting.find("rotation_y")->second), std::get<double>(setting.find("rotation_z")->second));
        std::cout << std::endl << std::endl << std::endl << "Plane created" << std::endl;
        std::cout << "position: " << position.x << " " << position.y << " " << position.z << std::endl;
        std::cout << "normal: " << normal.x << " " << normal.y << " " << normal.z << std::endl << std::endl << std::endl
                  << std::endl;
        return new Plugin::Plane(position, rotation, normal);
    }

    void destroyEntity(Raytracer::IEntity *entity) {
        delete entity;
    }

    const char *getName() {
        return PLANE.c_str();
    }

    LibType getType() {
        return LibType::ENTITY;
    }
}
