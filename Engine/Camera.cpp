#include "Camera.h"
#include <cmath>
#include <algorithm> // for std::clamp
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
}
Camera::~Camera() {
    // Cleanup code if needed
}

Vector3 Camera::rotate(Vector3 vector, float y, float x) {
    float x1 = vector.z * sin(x) * cos(y);
    float z1 = vector.z * cos(x) * cos(y);
    float y1 = vector.z * sin(y);
    return {x1, y1, z1};
}


void Camera::Update(){
    base_offset = {0,0,distance_from_target};
    rotated_offset = rotate(base_offset,vertical_angle,horizontal_rotation);
    camera_position = target + rotated_offset;
    view_matrix = glm::lookAt(
        glm::vec3(camera_position.x, camera_position.y, camera_position.z),
        glm::vec3(target.x, target.y, target.z),
        glm::vec3(up.x, up.y, up.z)
    );

    
}