export module BlenderObject_BlenderObjectData;

export import BlenderObject_ShapeKey;
export import BlenderObject_TransformKeyFrame;
export import BlenderObject_Material;

export struct BlenderObjectData {
    std::string name;
    std::vector<float> vertices;           // Flat array: x1, y1, z1, x2, y2, z2, ...
    std::vector<float> colors;             // Vertex colors if any
    std::vector<unsigned int> indices;     // Triangle indices
    glm::vec3 position = glm::vec3(0.0f);
    glm::vec3 rotation = glm::vec3(0.0f);  // Euler angles in radians
    glm::vec3 scale = glm::vec3(1.0f);
    std::vector<Material> materials;

    std::vector<TransformKeyframe> transformKeyframes; // Transform animations
    std::vector<ShapeKey> shapeKeys;                   // Shape key animations
    std::vector<std::vector<glm::vec3>> vertexAnimations; // Vertex animations per shape key
};