import ALL_MODULES;
import BlenderObject;
import Shader_Vertex;
import Shader_Fragment;

float PointToTriangleDistance(const glm::vec3& p, const Triangle& tri) {
    const glm::vec3& A = tri.vertices[0];
    const glm::vec3& B = tri.vertices[1];
    const glm::vec3& C = tri.vertices[2];

    // Compute edges
    glm::vec3 AB = B - A;
    glm::vec3 AC = C - A;
    glm::vec3 AP = p - A;

    // Compute normal
    glm::vec3 normal = glm::normalize(glm::cross(AB, AC));

    // Project point onto triangle plane
    float distancePlane = glm::dot(AP, normal);
    glm::vec3 Pplane = p - distancePlane * normal;

    // Check if the projected point is inside the triangle using barycentric coordinates
    glm::vec3 v0 = B - A;
    glm::vec3 v1 = C - A;
    glm::vec3 v2 = Pplane - A;

    float d00 = glm::dot(v0, v0);
    float d01 = glm::dot(v0, v1);
    float d11 = glm::dot(v1, v1);
    float d20 = glm::dot(v2, v0);
    float d21 = glm::dot(v2, v1);

    float denom = d00 * d11 - d01 * d01;
    if (denom == 0.0f) {
        // Degenerate triangle
        return std::numeric_limits<float>::max();
    }
    float v = (d11 * d20 - d01 * d21) / denom;
    float w = (d00 * d21 - d01 * d20) / denom;
    float u = 1.0f - v - w;

    if (u >= 0 && v >= 0 && w >= 0) {
        // Inside the triangle
        return std::abs(distancePlane);
    }
    else {
        // Outside the triangle, compute distance to edges
        auto ClosestPointOnLine = [](const glm::vec3& p, const glm::vec3& a, const glm::vec3& b) -> glm::vec3 {
            glm::vec3 ab = b - a;
            float t = glm::dot(p - a, ab) / glm::dot(ab, ab);
            t = glm::clamp(t, 0.0f, 1.0f);
            return a + t * ab;
            };

        glm::vec3 ClosestAB = ClosestPointOnLine(p, A, B);
        glm::vec3 ClosestBC = ClosestPointOnLine(p, B, C);
        glm::vec3 ClosestCA = ClosestPointOnLine(p, C, A);

        float distAB = glm::length(p - ClosestAB);
        float distBC = glm::length(p - ClosestBC);
        float distCA = glm::length(p - ClosestCA);

        return std::min({ distAB, distBC, distCA });
    }
}

bool RayIntersectsTriangle(
    const glm::vec3& orig, const glm::vec3& dir, const Triangle& tri, float& t) {
    const float EPSILON = 1e-8f;
    glm::vec3 vertex0 = tri.vertices[0];
    glm::vec3 vertex1 = tri.vertices[1];
    glm::vec3 vertex2 = tri.vertices[2];

    glm::vec3 edge1 = vertex1 - vertex0;
    glm::vec3 edge2 = vertex2 - vertex0;

    glm::vec3 h = glm::cross(dir, edge2);
    float a = glm::dot(edge1, h);
    if (std::abs(a) < EPSILON)
        return false; // This ray is parallel to this triangle.

    float f = 1.0f / a;
    glm::vec3 s = orig - vertex0;
    float u = f * glm::dot(s, h);
    if (u < 0.0f || u > 1.0f)
        return false;

    glm::vec3 q = glm::cross(s, edge1);
    float v = f * glm::dot(dir, q);
    if (v < 0.0f || u + v > 1.0f)
        return false;

    t = f * glm::dot(edge2, q);
    if (t > EPSILON) // Ray intersection
        return true;

    return false;
}

bool IsPointInsideMesh(const glm::vec3& p, const std::vector<Triangle>& mesh) {
    glm::vec3 rayDir = glm::vec3(1.0f, 0.0f, 0.0f); // Arbitrary direction
    int intersections = 0;
    float t;

    for (const auto& tri : mesh) {
        if (RayIntersectsTriangle(p, rayDir, tri, t)) {
            intersections++;
        }
    }

    // If intersections are odd, point is inside
    return (intersections % 2) == 1;
}

float SignedDistance(const glm::vec3& p, const std::vector<Triangle>& mesh) {
    float minDist = std::numeric_limits<float>::max();

    // Compute the minimum distance
    for (const auto& tri : mesh) {
        float dist = PointToTriangleDistance(p, tri);
        if (dist < minDist) {
            minDist = dist;
        }
    }

    // Determine the sign
    bool inside = IsPointInsideMesh(p, mesh);
    return inside ? -minDist : minDist;
}

std::vector<glm::vec3> GenerateGridPoints(
    const glm::vec3& minBound, const glm::vec3& maxBound, float voxelSize) {

    std::vector<glm::vec3> gridPoints;

    int resX = static_cast<int>((maxBound.x - minBound.x) / voxelSize) + 1;
    int resY = static_cast<int>((maxBound.y - minBound.y) / voxelSize) + 1;
    int resZ = static_cast<int>((maxBound.z - minBound.z) / voxelSize) + 1;

    gridPoints.reserve(resX * resY * resZ);

    for (int i = 0; i < resX; ++i) {
        for (int j = 0; j < resY; ++j) {
            for (int k = 0; k < resZ; ++k) {
                float x = minBound.x + i * voxelSize;
                float y = minBound.y + j * voxelSize;
                float z = minBound.z + k * voxelSize;
                gridPoints.emplace_back(x, y, z);
            }
        }
    }

    return gridPoints;
}

std::vector<float> ComputeSDF(
    const std::vector<glm::vec3>& gridPoints, const std::vector<Triangle>& mesh) {

    const size_t numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    std::vector<float> sdfValues(gridPoints.size());
    std::atomic<size_t> currentIndex{ 0 };

    auto worker = [&](size_t /*threadId*/) {
        size_t index;
        while ((index = currentIndex.fetch_add(1)) < gridPoints.size()) {
            sdfValues[index] = SignedDistance(gridPoints[index], mesh);
        }
        };

    // Launch threads
    for (size_t i = 0; i < numThreads; ++i) {
        threads.emplace_back(worker, i);
    }

    // Join threads
    for (auto& thread : threads) {
        thread.join();
    }

    return sdfValues;
}

GLuint CreateSDFTexture(
    const std::vector<float>& sdfValues, int resX, int resY, int resZ) {

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_3D, textureID);

    glTexImage3D(
        GL_TEXTURE_3D, 0, GL_R32F, resX, resY, resZ,
        0, GL_RED, GL_FLOAT, sdfValues.data()
    );

    // Texture parameters
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}

GLuint compileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    // Check for compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader Compilation Error:\n" << infoLog << std::endl;
    }
    return shader;
}

GLuint createShaderProgram() {
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    // Link shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "Shader Linking Error:\n" << infoLog << std::endl;
    }

    // Clean up shaders (no longer needed after linking)
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Configure GLFW (OpenGL 3.3 Core)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // For Mac OS X
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "SDF Visualization", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD before calling any OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    // Viewport setup
    glViewport(0, 0, 800, 600);

    // Prepare BlenderObject data
    BlenderObjectData blenderObjectData;
    // Load or set up your mesh data here (vertices, indices, etc.)

    // Example: Hardcoded triangle (for illustration)
    blenderObjectData.vertices = {
        0.0f, 0.5f, 0.0f,   // Vertex 0
       -0.5f, -0.5f, 0.0f,  // Vertex 1
        0.5f, -0.5f, 0.0f   // Vertex 2
    };
    blenderObjectData.indices = { 0, 1, 2 }; // Single triangle

    // Initialize BlenderObject
    BlenderObject myBlenderObject(blenderObjectData);

    // Define the frame at which to compute the SDF
    float frame = 0.0f;

    // Get transformed triangles
    std::vector<Triangle> triangles = myBlenderObject.GetTransformedTrianglesAtFrame(frame);

    // Define grid parameters
    glm::vec3 minBound(-1.0f, -1.0f, -1.0f);
    glm::vec3 maxBound(1.0f, 1.0f, 1.0f);
    float voxelSize = 0.05f;

    // Generate grid points
    std::vector<glm::vec3> gridPoints = GenerateGridPoints(minBound, maxBound, voxelSize);

    // Compute grid resolution
    int resX = static_cast<int>((maxBound.x - minBound.x) / voxelSize) + 1;
    int resY = static_cast<int>((maxBound.y - minBound.y) / voxelSize) + 1;
    int resZ = static_cast<int>((maxBound.z - minBound.z) / voxelSize) + 1;

    // Compute SDF
    std::vector<float> sdfValues = ComputeSDF(gridPoints, triangles);

    // Create OpenGL texture
    GLuint sdfTexture = CreateSDFTexture(sdfValues, resX, resY, resZ);

    // Compile shaders and create shader program
    GLuint shaderProgram = createShaderProgram();

    // Set up transformation matrices
    glm::mat4 model = glm::mat4(1.0f); // Adjust as needed
    glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 2.0f), // Camera position
        glm::vec3(0.0f, 0.0f, 0.0f), // Look at point
        glm::vec3(0.0f, 1.0f, 0.0f)  // Up vector
    );
    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f),
        800.0f / 600.0f,
        0.1f,
        100.0f
    );

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Input handling
        glfwPollEvents();

        // Render
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use shader program
        glUseProgram(shaderProgram);

        // Set uniforms
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniform3fv(glGetUniformLocation(shaderProgram, "minBound"), 1, glm::value_ptr(minBound));
        glUniform3fv(glGetUniformLocation(shaderProgram, "maxBound"), 1, glm::value_ptr(maxBound));
        glUniform1f(glGetUniformLocation(shaderProgram, "isovalue"), 0.0f);

        // Bind the SDF texture
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_3D, sdfTexture);
        glUniform1i(glGetUniformLocation(shaderProgram, "sdfTexture"), 0);

        // Draw the object
        myBlenderObject.draw(shaderProgram);

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}