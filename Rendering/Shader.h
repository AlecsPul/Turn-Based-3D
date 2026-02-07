#pragma once
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader {
    public:
        Shader(const char* vertexSrc, const char* fragmentSrc);
        ~Shader();

        void Use() const;
        void SetMat4(const std::string& name, const glm::mat4& mat) const;
        unsigned int ID() const {return m_ID;}

    private:
        unsigned int m_ID;
        glm::mat4 uModel;
};