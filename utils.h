#pragma once

struct Vector3 {
    float x, y, z;

    Vector3 operator+(const Vector3& other) const {
        return {x+other.x,y+other.y,z+other.z};
    }

    
    Vector3& operator+=(const Vector3& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
};

