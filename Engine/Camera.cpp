#include "Camera.h"
#include <cmath>
#include <algorithm> // for std::clamp
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
}
Vector3 Camera::rotate(Vector3 vector, float y, float x){
    float cosH = std::cos(x);
    float sinH = std::sin(x);
    float cosV = std::cos(y);
    float sinV = std::sin(y);

    float x1 = vector.x * cosH - vector.z * sinH;
    float z1 = vector.x * sinH + vector.z * cosH;
    float y1 = vector.y;

    float x2 = x1;
    float z2 = y1 * sinV + z1*cosV;
    float y2 = y1 * cosV - z1*sinV;
    
    return {x2,y2,z2};
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