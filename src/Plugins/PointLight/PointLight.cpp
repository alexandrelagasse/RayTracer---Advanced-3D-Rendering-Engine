/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PointLight
*/

#include <iostream>
#include <map>
#include "Api.hpp"
#include "PointLight.hpp"

static const std::string POINTLIGHT = "PointLight";

Plugin::PointLight::PointLight(const Component::Vector3f &position, const Component::Vector3f &rotation, const Component::Color &color, double intensity)
        : Raytracer::ALight(POINTLIGHT, position, rotation, color, intensity)
{
}

bool Plugin::PointLight::isIlluminating(const Component::Vector3f &origin, const Component::Vector3f &direction) const
{
    return true;
}

extern "C" {

    Raytracer::IEntity *createEntity(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting) {
        Component::Vector3f position(std::get<double>(setting.find("position_x")->second),
                                     std::get<double>(setting.find("position_y")->second),
                                     std::get<double>(setting.find("position_z")->second));
        Component::Color color(std::get<double>(setting.find("color_r")->second),
                               std::get<double>(setting.find("color_g")->second),
                               std::get<double>(setting.find("color_b")->second));
        double intensity = std::get<double>(setting.find("intensity")->second);
        Component::Vector3f rotation(std::get<double>(setting.find("rotation_x")->second), std::get<double>(setting.find("rotation_y")->second), std::get<double>(setting.find("rotation_z")->second));
        return new Plugin::PointLight(position, rotation, color, intensity);
    }

    const char *getName() {
        return POINTLIGHT.c_str();
    }

    LibType getType() {
        return LibType::ENTITY;
    }

    void destroyEntity(Raytracer::IEntity *entity) {
        std::cout << "destroying light" << std::endl;
        delete entity;
    }
}
