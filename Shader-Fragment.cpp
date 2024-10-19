import Shader_Fragment;

const char* fragmentShaderSource = R"glsl(
#version 330 core
in vec3 fragPos;
out vec4 FragColor;

uniform sampler3D sdfTexture;
uniform vec3 minBound;
uniform vec3 maxBound;
uniform float isovalue;

void main()
{
    // Normalize fragPos to [0, 1] for texture coordinates
    vec3 texCoords = (fragPos - minBound) / (maxBound - minBound);

    // Sample the SDF
    float sdfValue = texture(sdfTexture, texCoords).r;

    // Render if sdfValue is close to the isovalue
    float threshold = 0.01;
    if (abs(sdfValue - isovalue) < threshold) {
        FragColor = vec4(1.0, 0.0, 0.0, 1.0); // Red color for the surface
    } else {
        discard;
    }
}
)glsl";