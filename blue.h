#ifndef BLUE_H
#define BLUE_H

#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

struct Color{
  float RED;
  float GREEN;
  float BLUE;
  float ALPHA;
};

struct Window {
  unsigned int WINW;
  unsigned int WINH;
  struct Color BACKGROUND_COLOR;
  void (*ptr)();
  char TITLE[16];
};

void error_callback(int error, const char* description){
  fprintf(stderr, "ERROR: %s\n", description);
}

//How do I add a function to the struct myWindow so I can edit the logic of the OpenGL loop.

//const char* getRunPtr(){
//  return *run();
//}

void createWindow(struct Window window){
  glfwSetErrorCallback(error_callback);

  if(!glfwInit()){
    exit(1);
  }

  GLFWwindow* win = glfwCreateWindow(window.WINW, window.WINH, window.TITLE, NULL, NULL);

  if(!win){
    glfwDestroyWindow(win);
    glfwTerminate();
    exit(1);
  }
  
  glfwMakeContextCurrent(win);

  while(!glfwWindowShouldClose(win)){
    glClear(GL_COLOR_BUFFER_BIT);
    window.ptr();
    glClearColor(window.BACKGROUND_COLOR.RED, window.BACKGROUND_COLOR.GREEN, window.BACKGROUND_COLOR.BLUE, window.BACKGROUND_COLOR.ALPHA);

    glfwSwapBuffers(win);
    glfwPollEvents();
  }
  
  glfwDestroyWindow(win);
  glfwTerminate();
  exit(1);
}

#endif
