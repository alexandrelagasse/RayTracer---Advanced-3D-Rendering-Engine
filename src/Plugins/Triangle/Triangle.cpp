/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Triangle
*/

#include <iostream>
#include <libconfig.h++>
#include <map>
#include "Api.hpp"
#include "Triangle.hpp"

static const std::string triangleName = "Triangle";

namespace Plugin {
    Triangle::Triangle(Component::Matrix3x3 &matrix, Component::Vector3f &position, Component::Vector3f &rotation)
        : APrimitive(triangleName, position, rotation), _matrix(matrix)
    {
    }

    double Triangle::intersect(const Raytracer::Ray &ray) const
    {
        const float epsilon = 0.0000001;
        Component::Vector3f edge1 = {_matrix.m[3] - _matrix.m[0], _matrix.m[4] - _matrix.m[1], _matrix.m[5] - _matrix.m[2]};
        Component::Vector3f edge2 = {_matrix.m[6] - _matrix.m[0], _matrix.m[7] - _matrix.m[1], _matrix.m[8] - _matrix.m[2]};
        Component::Vector3f h = ray.direction.cross(edge2);
        double a = edge1.dot(h);

        if (a > -epsilon && a < epsilon) {
            return false;
        }

        Component::Vector3f vector = {_matrix.m[0], _matrix.m[1], _matrix.m[2]};
        double f = 1.0 / a;
        Component::Vector3f s = ray.origin - vector;
        double u = f * s.dot(h);

        if (u < 0.0 || u > 1.0) {
            return false;
        }

        Component::Vector3f q = s.cross(edge1);
        double v = f * ray.direction.dot(q);

        if (v < 0.0 || u + v > 1.0) {
            return false;
        }

        double t = f * edge2.dot(q);

        if (t > epsilon) {
            return t;
        }
        return (true);
    }

    Component::Vector3f Triangle::getNormal(const Component::Vector3f &hitPoint) const
    {
        Component::Vector3f edge1 = {_matrix.m[3] - _matrix.m[0], _matrix.m[4] - _matrix.m[1], _matrix.m[5] - _matrix.m[2]};
        Component::Vector3f edge2 = {_matrix.m[6] - _matrix.m[0], _matrix.m[7] - _matrix.m[1], _matrix.m[8] - _matrix.m[2]};
        Component::Vector3f normal = edge1.cross(edge2);
        return normal.normalize();
    }
}

Raytracer::IEntity *createEntity(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting)
{
    Component::Matrix3x3 matrix(std::get<double>(setting.find("matrixA_pos_x")->second),
                                std::get<double>(setting.find("matrixA_pos_y")->second),
                                std::get<double>(setting.find("matrixA_pos_z")->second),
                                std::get<double>(setting.find("matrixB_pos_x")->second),
                                std::get<double>(setting.find("matrixB_pos_y")->second),
                                std::get<double>(setting.find("matrixB_pos_z")->second),
                                std::get<double>(setting.find("matrixC_pos_x")->second),
                                std::get<double>(setting.find("matrixC_pos_y")->second),
                                std::get<double>(setting.find("matrixC_pos_z")->second)
                                );
    Component::Vector3f rotation(std::get<double>(setting.find("rotation_x")->second), std::get<double>(setting.find("rotation_y")->second), std::get<double>(setting.find("rotation_z")->second));
    Component::Vector3f position(std::get<double>(setting.find("position_x")->second), std::get<double>(setting.find("position_y")->second), std::get<double>(setting.find("position_z")->second));

    return new Plugin::Triangle(matrix, position, rotation);
}

const char *getName()
{
    return triangleName.c_str();
}

LibType getType()
{
    return LibType::ENTITY;
}

void destroyEntity(Raytracer::IEntity *entity)
{
    std::cout << "destroy triangle" << std::endl;
    delete entity;
}
