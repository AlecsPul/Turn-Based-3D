#pragma once
#include <algorithm>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

struct Vector3 {
    float x, y, z;

    Vector3 operator+(const Vector3& other) const {
        return {x+other.x,y+other.y,z+other.z};
    }
};

class Camera {
public:
    Camera();
    ~Camera();
   

private:
    Vector3 rotate(Vector3, float, float);
    void Update();

    Vector3 camera_position;
    // Camera properties will be added later
    Vector3 target = {0,0,0};
    Vector3 base_offset;
    Vector3 rotated_offset;
    Vector3 up = {0,1,0};
    
    glm::mat4 view_matrix;

    float distance_from_target;
    
    float horizontal_rotation = 0; //(yaw) Angle in radians 
    float vertical_angle = 0; //(pitch) Either fixed value or clamp it decide on implement
    float rotation_speed;

    float fov;
    float aspect_ratio;

    float near_plane;
    float far_plane;
};
