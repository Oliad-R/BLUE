#include "blue.h"
#include <stdio.h>

struct Color background = {0.5f, 0.5f, 0.5f, 1.0f};

void run(){
  //Any logic + rendering necessary
}

int main(){
  struct Window myWindow = {600, 400, background, run, "Test"};

  createWindow(myWindow);
  return 0;
}
