#include "Mesh.h"

Mesh::Mesh(const std::vector<glm::vec3>& vertices) {
    m_VertexCount = vertices.size();

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);

    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &m_VBO);
    glDeleteVertexArrays(1, &m_VAO);
}

void Mesh::Draw() const {
    glBindVertexArray(m_VAO);
    glDrawArrays(GL_LINES, 0, m_VertexCount); // GL_LINES for grid lines
    glBindVertexArray(0);
}
