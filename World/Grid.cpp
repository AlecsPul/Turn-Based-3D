#include "Grid.h"
#include "../Rendering/Mesh.h"
#include "../Rendering/Shader.h"
#include "../Rendering/Renderer.h"
#include <vector>

Grid::Grid(int width, int height) 
    : m_ModelMatrix(1.0f), m_Position(0.0f), m_Rotation(0.0f), m_Scale(1.0f) {
    
    // Generate grid vertices
    std::vector<glm::vec3> gridVertices;
    int size = width;
    for(int i = -size; i <= size; i++) {
        // Vertical lines
        gridVertices.push_back({(float)i, 0.f, (float)-size});
        gridVertices.push_back({(float)i, 0.f, (float)size});
        // Horizontal lines
        gridVertices.push_back({(float)-size, 0.f, (float)i});
        gridVertices.push_back({(float)size, 0.f, (float)i});
    }

    m_GridMesh = new Mesh(gridVertices);

    // Create shader with model matrix support
    const char* vertexSrc = R"(
    #version 330 core
    layout(location = 0) in vec3 aPos;
    uniform mat4 uView;
    uniform mat4 uProjection;
    uniform mat4 uModel;
    void main() {
        gl_Position = uProjection * uView * uModel * vec4(aPos, 1.0);
    })";

    const char* fragmentSrc = R"(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(0.8, 0.8, 0.8, 1.0);
    })";

    m_GridShader = new Shader(vertexSrc, fragmentSrc);
}

Grid::~Grid() {
    delete m_GridMesh;
    delete m_GridShader;
}

void Grid::Draw(Renderer& renderer) {
    if (m_GridMesh && m_GridShader) {
        renderer.DrawMesh(*m_GridMesh, *m_GridShader, m_ModelMatrix);
    }
}
