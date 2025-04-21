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
#include "SimpleMaterial.hpp"
#include "AMaterial.hpp"

static const std::string SIMPLEMATERIAL = "SimpleMaterial";

Plugin::SimpleMaterial::SimpleMaterial(const Component::Color &baseColor, double diffuseFactor, double reflectivity, double refractivity, double refractiveIndex,
const Component::Color &diffuse, double specular, double shininess)
        : Raytracer::AMaterial(SIMPLEMATERIAL, refractivity, refractiveIndex, reflectivity, diffuseFactor, diffuse, specular, shininess), _baseColor(baseColor) {}

Component::Color Plugin::SimpleMaterial::computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                      const Component::Vector3f &lightDirection, double lightIntensity,
                                                      const Component::Color &ambientLightColor,
                                                      double ambientLightIntensity) const
{
    double cosTheta = std::max(0.0, normal.dot(lightDirection));

    Component::Color ambientColor = _baseColor * ambientLightIntensity * lightIntensity;

    Component::Color color = _baseColor * (_diffuseFactor * cosTheta * lightIntensity);

    color = color + ambientColor;

    return color;
}

extern "C" {
    Raytracer::IMaterial *
    createMaterial(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting) {
        Component::Color baseColor(std::get<double>(setting.find("baseColor_r")->second),
                                   std::get<double>(setting.find("baseColor_g")->second),
                                   std::get<double>(setting.find("baseColor_b")->second));
        Component::Color colorDiffuse(std::get<double>(setting.find("diffuse_r")->second),
                                      std::get<double>(setting.find("diffuse_g")->second),
                                      std::get<double>(setting.find("diffuse_b")->second));
        double diffuseFactor = std::get<double>(setting.find("diffuseFactor")->second);
        double reflectivity = std::get<double>(setting.find("reflectivity")->second);
        double refractivity = std::get<double>(setting.find("refractivity")->second);
        double refractiveIndex = std::get<double>(setting.find("refractiveIndex")->second);
        double specular = std::get<double>(setting.find("specular")->second);
        double shininess = std::get<double>(setting.find("shininess")->second);

        std::cout << std::endl << std::endl << std::endl << "SimpleMaterial created" << std::endl;
        std::cout << "baseColor: " << baseColor.r << " " << baseColor.g << " " << baseColor.b << std::endl;
        std::cout << "diffuse: " << colorDiffuse.r << " " << colorDiffuse.g << " " << colorDiffuse.b << std::endl;
        std::cout << "diffuseFactor: " << diffuseFactor << std::endl;
        std::cout << "reflectivity: " << reflectivity << std::endl;
        std::cout << "refractivity: " << refractivity << std::endl;
        std::cout << "refractiveIndex: " << refractiveIndex << std::endl;
        std::cout << "specular: " << specular << std::endl;
        std::cout << "shininess: " << shininess << std::endl << std::endl << std::endl;
        return new Plugin::SimpleMaterial(baseColor, diffuseFactor, reflectivity, refractivity, refractiveIndex,
                                          colorDiffuse, specular, shininess);
    }

    const char *getName() {
        return SIMPLEMATERIAL.c_str();
    }

    LibType getType() {
        return LibType::MATERIAL;
    }

    void destroyMaterial(Raytracer::IMaterial *material) {
        delete material;
    }

}
