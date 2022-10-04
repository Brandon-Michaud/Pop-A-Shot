#include <time.h>
#define WIDTH 575
#define HEIGHT 525
#define PI 3.14159265358979
#include <kipr/graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a function that delays execution for the given number of seconds
void delay(double s) {
  
  // Start the clock
  clock_t start = clock();
  
  // Until the given number of seconds have passed, do nothing
  while (clock() < start + (1000 * s)) {
  
  }
  
}