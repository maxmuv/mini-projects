#pragma once
#include <vector>

struct Vector3f {
  float x;
  float y;
  float z;
  Vector3f() {}
  Vector3f(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
  }
};

class Triangle {
 public:
  Triangle(Vector3f x, Vector3f y, Vector3f z);
  void FillVertexArray();
  void DrawArrays();

  int id;

 private:
  Vector3f m_x, m_y, m_z;
};

std::vector<Triangle> triangles;
