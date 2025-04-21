/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SimpleMaterial
*/

#include <iostream>
#include <map>
#include "Api.hpp"
#include "IEntity.hpp"
#include "PlaneMaterial.hpp"
#include "AMaterial.hpp"

static const std::string PLANEMATERIAL = "PlaneMaterial";

Plugin::PlaneMaterial::PlaneMaterial(const Component::Color &color1, const Component::Color &color2, double squareSize, double diffuseFactor, double reflectivity, double refractivity, double refractiveIndex,
                                     const Component::Color &diffuse, double specular, double shininess)
        : _color1(color1), _color2(color2), _squareSize(squareSize), Raytracer::AMaterial(PLANEMATERIAL, refractivity, refractiveIndex, reflectivity, diffuseFactor, diffuse, specular, shininess) {}


Component::Color Plugin::PlaneMaterial::computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                            const Component::Vector3f &lightDirection, double lightIntensity,
                                                            const Component::Color &ambientLightColor, double ambientLightIntensity) const
{
    int ix = static_cast<int>(floor(hitPoint.x / _squareSize));
    int iz = static_cast<int>(floor(hitPoint.z / _squareSize));

    Component::Color baseColor;

    if ((ix + iz) % 2 == 0)
    {
        baseColor = _color1;
    }
    else
    {
        baseColor = _color2;
    }

    double cosTheta = std::max(0.0, normal.dot(lightDirection));

    Component::Color ambientColor = baseColor * ambientLightIntensity * lightIntensity;

    Component::Color color = baseColor * (_diffuseFactor * cosTheta * lightIntensity);

    color = color + ambientColor;

    return color;
}

extern "C" {

    Raytracer::IMaterial *
    createMaterial(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting) {
        Component::Color baseColor(std::get<double>(setting.find("baseColor_r")->second),
                                   std::get<double>(setting.find("baseColor_g")->second),
                                   std::get<double>(setting.find("baseColor_b")->second));
        Component::Color baseColorSecond(std::get<double>(setting.find("baseColorSecond_r")->second),
                                         std::get<double>(setting.find("baseColorSecond_g")->second),
                                         std::get<double>(setting.find("baseColorSecond_b")->second));
        Component::Color colorDiffuse(std::get<double>(setting.find("diffuse_r")->second),
                                      std::get<double>(setting.find("diffuse_g")->second),
                                      std::get<double>(setting.find("diffuse_b")->second));
        double squareSize = std::get<double>(setting.find("squareSize")->second);
        double diffuseFactor = std::get<double>(setting.find("diffuseFactor")->second);
        double reflectivity = std::get<double>(setting.find("reflectivity")->second);
        double refractivity = std::get<double>(setting.find("refractivity")->second);
        double refractiveIndex = std::get<double>(setting.find("refractiveIndex")->second);
        double specular = std::get<double>(setting.find("specular")->second);
        double shininess = std::get<double>(setting.find("shininess")->second);

        std::cout << std::endl << std::endl << std::endl << "Creating PlaneMaterial" << std::endl;
        std::cout << "baseColor: " << baseColor.r << " " << baseColor.g << " " << baseColor.b << std::endl;
        std::cout << "baseColorSecond: " << baseColorSecond.r << " " << baseColorSecond.g << " " << baseColorSecond.b
                  << std::endl;
        std::cout << "colorDiffuse: " << colorDiffuse.r << " " << colorDiffuse.g << " " << colorDiffuse.b << std::endl;
        std::cout << "squareSize: " << squareSize << std::endl;
        std::cout << "diffuseFactor: " << diffuseFactor << std::endl;
        std::cout << "reflectivity: " << reflectivity << std::endl;
        std::cout << "refractivity: " << refractivity << std::endl;
        std::cout << "refractiveIndex: " << refractiveIndex << std::endl;
        std::cout << "specular: " << specular << std::endl;
        std::cout << "shininess: " << shininess << std::endl;
        return new Plugin::PlaneMaterial(baseColor, baseColorSecond, squareSize, diffuseFactor, reflectivity, refractivity,
                                         refractiveIndex, colorDiffuse, specular, shininess);
    }

    const char *getName() {
        return PLANEMATERIAL.c_str();
    }

    LibType getType() {
        return LibType::MATERIAL;
    }

    void destroyMaterial(Raytracer::IMaterial *material) {
        delete material;
    }
}
