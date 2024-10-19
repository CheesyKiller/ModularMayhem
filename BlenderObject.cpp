import BlenderObject;
import <algorithm>;
import <glm/gtc/matrix_transform.hpp>;
#include <KHR/khrplatform.h>
#include <glad/glad.h>

BlenderObject::BlenderObject(const BlenderObjectData& blenderObjectData)
    : blenderData(blenderObjectData) {
    setupMesh();
}

BlenderObject::~BlenderObject() {
    // Cleanup OpenGL buffers
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void BlenderObject::setupMesh() {
    // Convert vertices to GLfloat array
    std::vector<float> vertexData = blenderData.vertices;

    // Generate and bind buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    // Vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), vertexData.data(), GL_STATIC_DRAW);

    // Element buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, blenderData.indices.size() * sizeof(unsigned int), blenderData.indices.data(), GL_STATIC_DRAW);

    // Vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // Positions
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void BlenderObject::draw(GLuint shaderProgram) const {
    // Draw the mesh
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(blenderData.indices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void BlenderObject::addTransformKeyframe(float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl) {
    TransformKeyframe keyframe = { frame, pos, rot, scl };
    blenderData.transformKeyframes.push_back(keyframe);

    // Sort keyframes by frame number for easier interpolation
    std::sort(blenderData.transformKeyframes.begin(), blenderData.transformKeyframes.end(),
        [](const TransformKeyframe& a, const TransformKeyframe& b) {
            return a.frame < b.frame;
        });
}

void BlenderObject::addShapeKey(const std::string& name) {
    ShapeKey newKey;
    newKey.name = name;
    blenderData.shapeKeys.push_back(newKey);
}

void BlenderObject::addShapeKeyframe(const std::string& shapeKeyName, float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl) {
    auto it = std::find_if(blenderData.shapeKeys.begin(), blenderData.shapeKeys.end(),
        [&shapeKeyName](const ShapeKey& key) {
            return key.name == shapeKeyName;
        });

    if (it != blenderData.shapeKeys.end()) {
        ShapeKeyframe keyframe = { frame, pos, rot, scl };
        it->keyframes.push_back(keyframe);

        // Sort keyframes by frame number for easier interpolation
        std::sort(it->keyframes.begin(), it->keyframes.end(),
            [](const ShapeKeyframe& a, const ShapeKeyframe& b) {
                return a.frame < b.frame;
            });
    }
}

void BlenderObject::addVertexAnimation(size_t shapeKeyIndex, const std::vector<glm::vec3>& vertices) {
    if (shapeKeyIndex < blenderData.shapeKeys.size()) {
        blenderData.vertexAnimations[shapeKeyIndex] = vertices;
    }
}

void BlenderObject::setVertices(const std::vector<float>& verts) {
    blenderData.vertices = verts;

    // Update VBO with new vertex data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(float), verts.data(), GL_STATIC_DRAW);
}

void BlenderObject::setColors(const std::vector<float>& vertColors) {
    blenderData.colors = vertColors;

    // If you need a separate color buffer, update that here
}

void BlenderObject::setIndices(const std::vector<unsigned int>& inds) {
    blenderData.indices = inds;

    // Update EBO with new index data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, inds.size() * sizeof(unsigned int), inds.data(), GL_STATIC_DRAW);
}

void BlenderObject::addMaterial(const Material& material) {
    blenderData.materials.push_back(material);
    // You may also want to store the full Material object if needed.
}

std::vector<Triangle> BlenderObject::GetTransformedTrianglesAtFrame(float frame) const {
    // Convert vertices to glm::vec3
    auto vertexPositions = ConvertVerticesToVec3(blenderData.vertices);

    // Apply transform keyframes
    if (!blenderData.transformKeyframes.empty()) {
        TransformKeyframe transform = InterpolateTransformKeyframes(blenderData.transformKeyframes, frame);
        glm::mat4 transformation = ComputeTransformationMatrix(transform.position, transform.rotation, transform.scale);
        ApplyTransformationToVertices(vertexPositions, transformation);
    }
    else {
        // Apply default transformation
        glm::mat4 transformation = ComputeTransformationMatrix(
            blenderData.position, blenderData.rotation, blenderData.scale);
        ApplyTransformationToVertices(vertexPositions, transformation);
    }

    // Apply shape keys
    ApplyShapeKeys(vertexPositions, blenderData.shapeKeys, frame);

    // Construct triangles
    return ConstructTriangles(vertexPositions, blenderData.indices);
}

std::vector<glm::vec3> ConvertVerticesToVec3(const std::vector<float>& vertices) {
    std::vector<glm::vec3> vertexPositions;
    vertexPositions.reserve(vertices.size() / 3);

    for (size_t i = 0; i < vertices.size(); i += 3) {
        glm::vec3 position(vertices[i], vertices[i + 1], vertices[i + 2]);
        vertexPositions.push_back(position);
    }
    return vertexPositions;
}

TransformKeyframe InterpolateTransformKeyframes(
    const std::vector<TransformKeyframe>& keyframes, float frame) {

    if (keyframes.empty()) return {};

    // Find the two keyframes surrounding the target frame
    TransformKeyframe before = keyframes.front();
    TransformKeyframe after = keyframes.back();

    for (size_t i = 0; i < keyframes.size() - 1; ++i) {
        if (keyframes[i].frame <= frame && keyframes[i + 1].frame >= frame) {
            before = keyframes[i];
            after = keyframes[i + 1];
            break;
        }
    }

    float t = (after.frame - before.frame) != 0.0f ? (frame - before.frame) / (after.frame - before.frame) : 0.0f;
    TransformKeyframe interpolated;
    interpolated.frame = frame;
    interpolated.position = glm::mix(before.position, after.position, t);
    interpolated.rotation = glm::mix(before.rotation, after.rotation, t);
    interpolated.scale = glm::mix(before.scale, after.scale, t);
    return interpolated;
}

glm::mat4 ComputeTransformationMatrix(
    const glm::vec3& position,
    const glm::vec3& rotation, // Euler angles in radians
    const glm::vec3& scale) {

    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    model = glm::rotate(model, rotation.x, glm::vec3(1, 0, 0));
    model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
    model = glm::rotate(model, rotation.z, glm::vec3(0, 0, 1));
    model = glm::scale(model, scale);
    return model;
}

void ApplyTransformationToVertices(
    std::vector<glm::vec3>& vertices, const glm::mat4& transformation) {
    for (auto& vertex : vertices) {
        glm::vec4 transformedVertex = transformation * glm::vec4(vertex, 1.0f);
        vertex = glm::vec3(transformedVertex);
    }
}

void ApplyShapeKeys(
    std::vector<glm::vec3>& vertices,
    const std::vector<ShapeKey>& shapeKeys,
    float frame) {

    for (const auto& shapeKey : shapeKeys) {
        // Interpolate shape keyframes
        ShapeKeyframe before = shapeKey.keyframes.front();
        ShapeKeyframe after = shapeKey.keyframes.back();

        for (size_t i = 0; i < shapeKey.keyframes.size() - 1; ++i) {
            if (shapeKey.keyframes[i].frame <= frame && shapeKey.keyframes[i + 1].frame >= frame) {
                before = shapeKey.keyframes[i];
                after = shapeKey.keyframes[i + 1];
                break;
            }
        }

        float t = (after.frame - before.frame) != 0.0f ? (frame - before.frame) / (after.frame - before.frame) : 0.0f;
        glm::vec3 position = glm::mix(before.position, after.position, t);
        glm::vec3 rotation = glm::mix(before.rotation, after.rotation, t);
        glm::vec3 scale = glm::mix(before.scale, after.scale, t);

        glm::mat4 shapeTransformation = ComputeTransformationMatrix(position, rotation, scale);
        ApplyTransformationToVertices(vertices, shapeTransformation);
    }
}

std::vector<Triangle> ConstructTriangles(
    const std::vector<glm::vec3>& vertexPositions,
    const std::vector<unsigned int>& indices) {

    std::vector<Triangle> triangles;
    triangles.reserve(indices.size() / 3);

    for (size_t i = 0; i < indices.size(); i += 3) {
        Triangle tri;
        tri.vertices[0] = vertexPositions[indices[i]];
        tri.vertices[1] = vertexPositions[indices[i + 1]];
        tri.vertices[2] = vertexPositions[indices[i + 2]];
        triangles.push_back(tri);
    }
    return triangles;
}