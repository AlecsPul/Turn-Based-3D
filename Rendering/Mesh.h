#pragma once
#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>

class Mesh {
public:
    Mesh(const std::vector<glm::vec3>& vertices);
    ~Mesh();

    void Draw() const;

private:
    unsigned int m_VAO, m_VBO;
    unsigned int m_VertexCount;
};
