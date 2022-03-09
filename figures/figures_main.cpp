#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include "figures.h"

GLuint VBO;
double p;

void displayMe(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

  Triangle::DrawArrays();

  glDisableVertexAttribArray(0);

  glutSwapBuffers();
}

void InitializeGlutCallbacks() { glutDisplayFunc(displayMe); }

void CreateVertexBuffer() {
  uint triangles_size = 3 * Triangle::triangles.size();
  Vector3f* Vertices = new Vector3f[triangles_size];
  Triangle::FillVertexArray(Vertices);

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, triangles_size * sizeof(Vector3f), Vertices,
               GL_STATIC_DRAW);
}

int main(int argc, char** argv) {
  for (float x = -0.95; x < 0.95; x += 0.1) {
    Vector3f a(x, x, 0);
    Vector3f b(x, x + 0.05, 0);
    Vector3f c(x + 0.05, x + 0.05, 0);
    new Triangle(a, b, c);
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Hello, world!");

  InitializeGlutCallbacks();

  // Must be done after glut is initialized!
  GLenum res = glewInit();
  if (res != GLEW_OK) {
    std::cout << glewGetErrorString(res);
    return 1;
  }

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  CreateVertexBuffer();

  glutMainLoop();
  return 0;
}
// ToDO: Makes libs with figures, and draw them
