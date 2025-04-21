/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Sphere
*/

#include <iostream>
#include <map>
#include "Api.hpp"
#include "Sphere.hpp"

static const std::string SPHERE = "sphere";

Plugin::Sphere::Sphere(const Component::Vector3f &position, const Component::Vector3f &rotation, double radius) : APrimitive(SPHERE, position, rotation), _radius(radius)
{

}

double Plugin::Sphere::intersect(const Raytracer::Ray &ray) const
{
    Component::Vector3f L = ray.origin - getPosition();
    double a = ray.direction.dot(ray.direction);
    double b = 2 * ray.direction.dot(L);
    double c = L.dot(L) - _radius * _radius;
    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        return -1;
    }

    double t1 = (-b - sqrt(delta)) / (2 * a);
    double t2 = (-b + sqrt(delta)) / (2 * a);

    if (t1 > 0 && t2 > 0) {
        return std::min(t1, t2);
    } else if (t1 > 0) {
        return t1;
    } else if (t2 > 0) {
        return t2;
    } else {
        return -1;
    }
}

Component::Vector3f Plugin::Sphere::getNormal(const Component::Vector3f &hitPoint) const
{
    Component::Vector3f normal = hitPoint - getPosition();
    return normal.normalize();
}

extern "C" {

    Raytracer::IEntity *createEntity(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting) {
        Component::Vector3f position(std::get<double>(setting.find("position_x")->second),
                                     std::get<double>(setting.find("position_y")->second),
                                     std::get<double>(setting.find("position_z")->second));
        double radius = std::get<double>(setting.find("radius")->second);
        Component::Vector3f rotation(std::get<double>(setting.find("rotation_x")->second), std::get<double>(setting.find("rotation_y")->second), std::get<double>(setting.find("rotation_z")->second));
        std::cout << std::endl << std::endl << std::endl << "Sphere created" << std::endl;
        std::cout << "position: " << position.x << " " << position.y << " " << position.z << std::endl;
        std::cout << "radius: " << radius << std::endl << std::endl << std::endl << std::endl;
        return new Plugin::Sphere(position, rotation, radius);
    }

    const char *getName() {
        return SPHERE.c_str();
    }

    LibType getType() {
        return LibType::ENTITY;
    }

    void destroyEntity(Raytracer::IEntity *entity) {
        std::cout << "destroy sphere" << std::endl;
        delete entity;
    }
}
