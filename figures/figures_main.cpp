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

  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDrawArrays(GL_TRIANGLES, 3, 3);

  glDisableVertexAttribArray(0);

  glutSwapBuffers();
}

void InitializeGlutCallbacks() { glutDisplayFunc(displayMe); }

void CreateVertexBuffer() {
  Vector3f Vertices[6];
  Vertices[0] = Vector3f(p, p, 0.0f);
  Vertices[1] = Vector3f(1.0f, p, 0.0f);
  Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);
  Vertices[3] = Vector3f(-p, -p, 0.0f);
  Vertices[4] = Vector3f(-1.0f, -p, 0.0f);
  Vertices[5] = Vector3f(0.0f, -1.0f, 0.0f);

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

int main(int argc, char** argv) {
  std::cin >> p;
  std::cout << "entered the number";
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
