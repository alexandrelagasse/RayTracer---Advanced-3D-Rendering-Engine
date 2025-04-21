/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Skybox
*/

#pragma once

#include <iostream>
#include <jpeglib.h>
#include <jerror.h>
#include <vector>
#include "Color.hpp"
#include "ASkybox.hpp"
#include "Vector3f.hpp"

namespace Raytracer {

    class Skybox : public Raytracer::ASkybox {
    public:
        explicit Skybox(const std::string &filename);

        ~Skybox() override;

        Component::Color getColorFromRay(const Component::Vector3f &direction) override;

    private:
        int m_width;
        int  m_height;
        int m_channels;
        std::vector<unsigned char> m_data;

        unsigned char* getPixel(float u, float v);
    };
}
