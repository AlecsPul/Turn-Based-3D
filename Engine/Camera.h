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
    float distance_from_target = 5.0f; // zoom distance
    float horizontal_rotation = 0.0f;  // yaw (radians)
    float vertical_angle = 1.0f;       // pitch (radians)
    float rotation_speed = 1.0f;
    void Update();
   

    float fov = 45.0f;
    float aspect_ratio = 16.f / 9.f;
    float near_plane = 0.1f;
    float far_plane = 100.f;

    glm::mat4 GetViewMatrix() const { return view_matrix; }

private:
    Vector3 rotate(Vector3, float, float);
    

   
    glm::mat4 view_matrix;
    glm::mat4 projection_matrix;

   
};
