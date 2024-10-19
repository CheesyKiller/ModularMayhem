export module BlenderObject_ShapeKeyFrame;

export import <glm/vec3.hpp>;

export struct ShapeKeyframe {
    float frame;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};