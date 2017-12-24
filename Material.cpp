//
// Created by rostard on 18.12.17.
//

#include "Material.h"

const Vector3f &Material::getColor() const {
    return color;
}

void Material::setColor(const Vector3f &color) {
    Material::color = color;
}
