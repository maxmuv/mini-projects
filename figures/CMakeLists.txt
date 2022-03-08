project(Figures)

add_library(FIGURES figures.h figures.cpp)

add_executable(Figures figures_main.cpp)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
add_dependencies(Figures OpenGL::OpenGL)
include_directories(${GLUT_INCLUDE_DIRS})

target_link_libraries(Figures OpenGL::OpenGL ${GLUT_LIBRARY} ${GLEW_LIBRARIES} FIGURES)
