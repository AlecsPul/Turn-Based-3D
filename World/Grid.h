#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Mesh;
class Shader;
class Renderer;

class Grid {
public:
    Grid(int width, int height);
    ~Grid();

    void SetPosition(const glm::vec3& position) {
        m_Position = position;
        UpdateModelMatrix();
    }

    void SetRotation(const glm::vec3& rotation) {
        m_Rotation = rotation;
        UpdateModelMatrix();
    }

    void SetScale(const glm::vec3& scale) {
        m_Scale = scale;
        UpdateModelMatrix();
    }

    glm::vec3 GetPosition() const { return m_Position; }
    glm::vec3 GetRotation() const { return m_Rotation; }
    glm::vec3 GetScale() const { return m_Scale; }

    const glm::mat4& GetModelMatrix() const { return m_ModelMatrix; }

    void Draw(Renderer& renderer);

private:
    void UpdateModelMatrix() {
        m_ModelMatrix = glm::mat4(1.0f);
        m_ModelMatrix = glm::translate(m_ModelMatrix, m_Position);
        m_ModelMatrix = glm::rotate(m_ModelMatrix, m_Rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
        m_ModelMatrix = glm::rotate(m_ModelMatrix, m_Rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
        m_ModelMatrix = glm::rotate(m_ModelMatrix, m_Rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
        m_ModelMatrix = glm::scale(m_ModelMatrix, m_Scale);
    }

    Mesh* m_GridMesh = nullptr;
    Shader* m_GridShader = nullptr;
    glm::mat4 m_ModelMatrix = glm::mat4(1.0f);
    glm::vec3 m_Position = glm::vec3(0.0f);
    glm::vec3 m_Rotation = glm::vec3(0.0f); // Euler angles in radians
    glm::vec3 m_Scale = glm::vec3(1.0f);
};