#pragma once
#include <glm/glm.hpp>
#include "../utils.h"

class Camera {
public:
    Camera();
    ~Camera();
    Vector3 camera_position;
    // Camera properties will be added later
    Vector3 target = {0,0,0};
    Vector3 base_offset;
    Vector3 rotated_offset;
    Vector3 up = {0,1,0};
    float horizontal_rotation = 0; //(yaw) Angle in radians 
    float vertical_angle = 0; //(pitch) Either fixed value or clamp it decide on implement
    float rotation_speed;
    float distance_from_target;
    void Update();
   

    float fov;
    float aspect_ratio;

    float near_plane;
    float far_plane;

private:
    Vector3 rotate(Vector3, float, float);
    

   
    glm::mat4 view_matrix;

   
};
