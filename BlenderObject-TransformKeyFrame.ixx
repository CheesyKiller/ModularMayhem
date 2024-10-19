export module BlenderObject_TransformKeyFrame;

export import <glm/vec3.hpp>;

export struct TransformKeyframe {
    float frame;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};