/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Camera
*/

#include <iostream>
#include <map>
#include "Api.hpp"
#include "Camera.hpp"

static const std::string CAMERA = "camera";

Plugin::Camera::Camera(const Component::Vector3f &position, const Component::Vector3f &rotation, bool isEdited, double fieldOfView, const Component::Vector3f &resolution)
        : Raytracer::ACam(CAMERA, position, rotation, isEdited, fieldOfView, resolution)
{
}

extern "C" {

    Raytracer::IEntity *createEntity(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting) {
        std::cout << std::endl << std::endl << std::endl << std::endl << "Creating camera" << std::endl;
        std::cout << "variant index = " << setting.find("position_x")->second.index() << std::endl;
        Component::Vector3f position(std::get<double>(setting.find("position_x")->second),
                                     std::get<double>(setting.find("position_y")->second),
                                     std::get<double>(setting.find("position_z")->second));
        std::cout << "position : x = " << position.x << " y = " << position.y << " z = " << position.z << std::endl;
        Component::Vector3f rotation(std::get<double>(setting.find("rotation_x")->second),
                                     std::get<double>(setting.find("rotation_y")->second),
                                     std::get<double>(setting.find("rotation_z")->second));
        std::cout << "rotation: x = " << rotation.x << " y = " << rotation.y << " z = " << rotation.z << std::endl;
        Component::Vector3f resolution(std::get<int>(setting.find("resolution_width")->second),
                                       std::get<int>(setting.find("resolution_height")->second), 0);
        std::cout << "resolution: width = " << resolution.x << " height = " << resolution.y << std::endl;
        double fieldOfView = std::get<double>(setting.find("fieldOfView")->second);
        std::cout << "fieldOfView = " << fieldOfView << std::endl << std::endl << std::endl << std::endl << std::endl;

        return new Plugin::Camera(position, rotation, false, fieldOfView, resolution);
    }

    const char *getName() {
        return CAMERA.c_str();
    }

    LibType getType() {
        return LibType::ENTITY;
    }

    void destroyEntity(Raytracer::IEntity *entity) {
        std::cout << "destroying camera" << std::endl;
        delete entity;
    }
}
