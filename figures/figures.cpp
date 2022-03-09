#include "figures.h"

std::vector<Triangle> Triangle::triangles;

Triangle::Triangle(Vector3f x, Vector3f y, Vector3f z)
    : m_x(x), m_y(y), m_z(z) {
  m_id = Triangle::triangles.size();
  Triangle::triangles.push_back(std::move(*this));
}

void Triangle::FillVertexArray(Vector3f *Vertices) {
  for (int i = 0; i < Triangle::triangles.size(); ++i) {
    Triangle::triangles[i].FillVertexArrayCT(Vertices);
  }
}
void Triangle::DrawArrays() {
  for (int i = 0; i < Triangle::triangles.size(); ++i) {
    Triangle::triangles[i].DrawArraysCT();
  }
}

void Triangle::FillVertexArrayCT(Vector3f *Vertices) {
  Vertices[m_id * 3] = m_x;
  Vertices[m_id * 3 + 1] = m_y;
  Vertices[m_id * 3 + 2] = m_z;
}
void Triangle::DrawArraysCT() { glDrawArrays(GL_TRIANGLES, m_id * 3, 3); }
