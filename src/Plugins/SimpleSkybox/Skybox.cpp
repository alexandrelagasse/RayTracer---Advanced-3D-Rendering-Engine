/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** SimpleMaterial
*/

#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include "stb_image.h"
#include "Color.hpp"
#include "Api.hpp"
#include "Vector3f.hpp"
#include "Skybox.hpp"

static const std::string SIMPLESKYBOX = "SimpleSkybox";

Raytracer::Skybox::Skybox(const std::string &filename) : ASkybox(SIMPLESKYBOX)
{
    int width, height, channels;
    unsigned char *image_data = stbi_load(filename.c_str(), &width, &height, &channels, STBI_rgb_alpha);

    if (image_data) {
        m_width = width;
        m_height = height;
        m_channels = channels;
        m_data.assign(image_data, image_data + width * height * channels);
        stbi_image_free(image_data);
        _isLoaded = true;
    } else {
        throw std::runtime_error("Failed to load skybox image");
    }
}

Component::Color Raytracer::Skybox::getColorFromRay(const Component::Vector3f &direction)
{
    if (!ASkybox::isLoaded())
        return {0, 0, 0};
    float theta = std::acos(direction.y);
    float phi = std::atan2(direction.z, direction.x) + M_PI;

    float u = phi / (2 * M_PI);
    float v = theta / M_PI;

    unsigned char *pixel = getPixel(u, v);

    unsigned char r = pixel[0];
    unsigned char g = pixel[1];
    unsigned char b = pixel[2];
    unsigned char a = pixel[3];

    Component::Color finalColor(r, g, b);

    return finalColor;
}

unsigned char *Raytracer::Skybox::getPixel(float u, float v)
{
    int x = static_cast<int>(u * m_width) % m_width;
    int y = static_cast<int>(v * m_height) % m_height;
    int index = (x + y * m_width) * m_channels;
    return &m_data[index];
}

Raytracer::Skybox::~Skybox()
{
    m_data.clear();
}

extern "C" {

    Raytracer::ISkybox *createSkybox(const std::map<std::string, std::variant<double, int, std::string, bool>> &setting)
    {
        std::string filename = std::get<std::string>(setting.at("filename"));
        return new Raytracer::Skybox(filename);
    }

    const char *getName()
    {
        return SIMPLESKYBOX.c_str();
    }

    LibType getType()
    {
        return LibType::SKYBOX;
    }

    void destroySkybox(Raytracer::ISkybox *skybox)
    {
        delete skybox;
    }
}
