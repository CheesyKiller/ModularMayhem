export module BlenderObject_Material;

export import <string>;
export import <glm/vec3.hpp>;

export struct Material {
    std::string name;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
};