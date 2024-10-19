export module BlenderObject;

export import <GLFW/glfw3.h>;
export import BlenderObject_Triangle;
export import BlenderObject_BlenderObjectData;

export class BlenderObject {
public:
    BlenderObject(const BlenderObjectData& blenderObjectData);
    ~BlenderObject();

    void draw(GLuint shaderProgram) const;

    void addTransformKeyframe(float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl);
    void addShapeKey(const std::string& name);
    void addShapeKeyframe(const std::string& shapeKeyName, float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl);
    void addVertexAnimation(size_t shapeKeyIndex, const std::vector<glm::vec3>& vertices);
    void setVertices(const std::vector<float>& verts);
    void setColors(const std::vector<float>& vertColors);
    void setIndices(const std::vector<unsigned int>& inds);
    void addMaterial(const Material& material);

    // Method to get transformed triangles at a specific frame
    std::vector<Triangle> GetTransformedTrianglesAtFrame(float frame) const;

private:
    BlenderObjectData blenderData;
    GLuint VAO, VBO, EBO;

    void setupMesh();
};

export {
    std::vector<glm::vec3> ConvertVerticesToVec3(const std::vector<float>& vertices);
    TransformKeyframe InterpolateTransformKeyframes(const std::vector<TransformKeyframe>& keyframes, float frame);
    glm::mat4 ComputeTransformationMatrix(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale);
    void ApplyTransformationToVertices(std::vector<glm::vec3>& vertices, const glm::mat4& transformation);
    void ApplyShapeKeys(std::vector<glm::vec3>& vertices, const std::vector<ShapeKey>& shapeKeys, float frame);
    std::vector<Triangle> ConstructTriangles(const std::vector<glm::vec3>& vertexPositions, const std::vector<unsigned int>& indices);
}