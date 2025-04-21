/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** DirectionalLight
*/

#include <iostream>
#include <map>
#include "Api.hpp"
#include "DirectionalLight.hpp"

static const std::string DIRECTIONALLIGHT = "DirectionalLight";

Plugin::DirectionalLight::DirectionalLight(const Component::Vector3f &position, const Component::Vector3f &rotation, const Component::Color &color, double intensity, const Component::Vector3f &direction)
        : Raytracer::ALight(DIRECTIONALLIGHT, position, rotation, color, intensity) , _direction(direction)
{
}

bool Plugin::DirectionalLight::isIlluminating(const Component::Vector3f &origin, const Component::Vector3f &direction) const
{
    return direction.dot(_direction) > 0;
}

extern "C" {

    Raytracer::IEntity *createEntity(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting) {
        Component::Vector3f position(std::get<double>(setting.find("position_x")->second),
                                     std::get<double>(setting.find("position_y")->second),
                                     std::get<double>(setting.find("position_z")->second));
        Component::Vector3f direction(std::get<double>(setting.find("direction_x")->second),
                                      std::get<double>(setting.find("direction_y")->second),
                                      std::get<double>(setting.find("direction_z")->second));
        Component::Color color(std::get<double>(setting.find("color_r")->second),
                               std::get<double>(setting.find("color_g")->second),
                               std::get<double>(setting.find("color_b")->second));
        Component::Vector3f rotation(std::get<double>(setting.find("rotation_x")->second), std::get<double>(setting.find("rotation_y")->second), std::get<double>(setting.find("rotation_z")->second));
        double intensity = std::get<double>(setting.find("intensity")->second);
        return new Plugin::DirectionalLight(position, rotation, color, intensity, direction);
    }

    const char *getName() {
        return DIRECTIONALLIGHT.c_str();
    }

    LibType getType() {
        return LibType::ENTITY;
    }

    void destroyEntity(Raytracer::IEntity *entity) {
        std::cout << "destroying light" << std::endl;
        delete entity;
    }
}
