#pragma once

#include <cmath>

struct Vector3 {
    float x, y, z;

    // Helper operators
    Vector3 operator+(const Vector3& other) const { return {x + other.x, y + other.y, z + other.z}; }
    Vector3 operator-(const Vector3& other) const { return {x - other.x, y - other.y, z - other.z}; }
    Vector3 operator*(float scalar) const { return {x * scalar, y * scalar, z * scalar}; }
    Vector3& operator+=(const Vector3& other) { x+=other.x; y+=other.y; z+=other.z; return *this; }
    Vector3& operator-=(const Vector3& other) { x-=other.x; y-=other.y; z-=other.z; return *this; }
};

// Normalize a vector
inline Vector3 normalize(const Vector3& v) {
    float len = std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    if (len == 0.0f) return {0,0,0};
    return {v.x/len, v.y/len, v.z/len};
}

// Cross product
inline Vector3 cross(const Vector3& a, const Vector3& b) {
    return {
        a.y*b.z - a.z*b.y,
        a.z*b.x - a.x*b.z,
        a.x*b.y - a.y*b.x
    };
}
