#pragma once

#include "AMaterial.hpp"

namespace Plugin
{
    class PlaneMaterial : public Raytracer::AMaterial
    {
    public:

        PlaneMaterial(const Component::Color &color1, const Component::Color &color2, double squareSize,
                      double diffuseFactor, double reflectivity, double refractivity, double refractiveIndex,
                      const Component::Color &diffuse, double specular, double shininess);

        ~PlaneMaterial() override = default;

    private:
        Component::Color _color1;
        Component::Color _color2;
        double _squareSize;

        [[nodiscard]] Component::Color computeColor(const Component::Vector3f &hitPoint, const Component::Vector3f &normal,
                                                    const Component::Vector3f &lightDirection, double lightIntensity,
                                                    const Component::Color &ambientLightColor, double ambientLightIntensity) const override;
    };
}
