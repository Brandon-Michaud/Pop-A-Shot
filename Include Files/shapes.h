// Define a function that rotates an x cordinate at a given angle
double xR(double x0, double y0, double r) {
  
  // Return the rotated x cordinate
  return (x0*cos(r) + y0*sin(r));
  
}

// Define a function that rotates an y cordinate at a given angle
double yR(double x0, double y0, double r) {
  
  // Return the rotated y cordinate
  return (y0*cos(r) - x0*sin(r));
  
}

// Define a function that rotates an x cordinate about a reference at a given angle
int xRotate(double x0, double y0, double x_ref, double y_ref, double r) {
  
  // Return the rotated x cordinate about the reference point
  return x_ref + xR(x0 - x_ref, y0 - y_ref, r);
  
}

// Define a function that rotates an y cordinate about a reference at a given angle
int yRotate(double x0, double y0, double x_ref, double y_ref, double r) {
  
  // Return the rotated y cordinate about the reference point
  return y_ref + yR(x0 - x_ref, y0 - y_ref, r);
  
}

// Define a function that draws a filled-in quarter-circle at a given point, color, radius, and angle
void drawQuarterCircleFill(int x, int y, int radius, double a, int r, int g, int b) {
  
  // Convert the given angle to radians
  a = a * (PI / 180.0);
  
  // Declare a variable for iterating through angles
  int i; 
  
  // Draw a line rotated the given angle for every angle
  for (i = 0; i <= 90; ++i) {
    
    // Draw a line rotated the given angle from the bottom of the quarter-circle to the top of the quarter circle
    graphics_line(xRotate(x + (radius * cos(i * (PI / 180.0))), y, x, y, a), yRotate(x + (radius * cos(i * (PI / 180.0))), y, x, y, a),
                  xRotate(x + (radius * cos(i * (PI / 180.0))), y - (radius * sin(i * (PI / 180.0))), x, y, a),
                  yRotate(x + (radius * cos(i * (PI / 180.0))), y - (radius * sin(i * (PI / 180.0))), x, y, a), r, g, b);
    
  }
  
}

// Define a function that draws a hollow quarter-circle at a given point, color, radius, and angle
void drawQuarterCircle(int x, int y, int radius, double a, int r, int g, int b) {
  
  // Convert the given angle to radians
  a = a * (PI / 180.0);
  
  // Declare a variable for iterating through angles
  int i; 
  
  // Draw each pixel on the edge of the quarter-circle
  for (i = 0; i <= 90; ++i) {
    
    // Draw the pixel at the current angle
    graphics_pixel(xRotate(x + (radius * cos(i * (PI / 180.0))), y - (radius * sin(i * (PI / 180.0))), x, y, a),
                   yRotate(x + (radius * cos(i * (PI / 180.0))), y - (radius * sin(i * (PI / 180.0))), x, y, a), r, g, b);
    
  }
  
}

// Define a function that draws a quarter-washer at a given point, color, inside radius, outside radius, and angle
void drawQuarterWasherFill(int x, int y, int r1, int r2, double a, int r, int g, int b) {
  
  // Convert the given angle to radians
  a = a * (PI / 180.0);
  
  // Declare a variable for iterating through angles
  double i; 
  
  // For each angle in the quarter-washer, draw rotated lines from the inner radius to the outer radius
  for (i = 0.0; i <= 90; i = i + 0.5) {
    
    // Draw a vertical line rotated the given angle from the inner radius to the outer radius
    graphics_line(xRotate(x + (r1 * cos(i * (PI / 180.0))), y - (r1 * sin(i * (PI / 180.0))), x, y, a), 
                  yRotate(x + (r1 * cos(i * (PI / 180.0))), y - (r1 * sin(i * (PI / 180.0))), x, y, a), 
                  xRotate(x + (r1 * cos(i * (PI / 180.0))), y - (r2 * sin(i * (PI / 180.0))), x, y, a), 
                  yRotate(x + (r1 * cos(i * (PI / 180.0))), y - (r2 * sin(i * (PI / 180.0))), x, y, a), r, g, b);
    
    // Draw a horizontal line rotated the given angle from the inner radius to the outer radius
    graphics_line(xRotate(x + (r1 * cos(i * (PI / 180.0))), y - (r1 * sin(i * (PI / 180.0))), x, y, a), 
                  yRotate(x + (r1 * cos(i * (PI / 180.0))), y - (r1 * sin(i * (PI / 180.0))), x, y, a), 
                  xRotate(x + (r2 * cos(i * (PI / 180.0))), y - (r1 * sin(i * (PI / 180.0))), x, y, a), 
                  yRotate(x + (r2 * cos(i * (PI / 180.0))), y - (r1 * sin(i * (PI / 180.0))), x, y, a), r, g, b);
    
    // Draw a vertical line rotated the given angle from the outer radius to the inner radius
    graphics_line(xRotate(x + (r2 * cos(i * (PI / 180.0))), y - (r1 * sin(i * (PI / 180.0))), x, y, a), 
                  yRotate(x + (r2 * cos(i * (PI / 180.0))), y - (r1 * sin(i * (PI / 180.0))), x, y, a), 
                  xRotate(x + (r2 * cos(i * (PI / 180.0))), y - (r2 * sin(i * (PI / 180.0))), x, y, a), 
                  yRotate(x + (r2 * cos(i * (PI / 180.0))), y - (r2 * sin(i * (PI / 180.0))), x, y, a), r, g, b);
    
    // Draw a horizontal line rotated the given angle from the outer radius to the inner radius
    graphics_line(xRotate(x + (r1 * cos(i * (PI / 180.0))), y - (r2 * sin(i * (PI / 180.0))), x, y, a), 
                  yRotate(x + (r1 * cos(i * (PI / 180.0))), y - (r2 * sin(i * (PI / 180.0))), x, y, a), 
                  xRotate(x + (r2 * cos(i * (PI / 180.0))), y - (r2 * sin(i * (PI / 180.0))), x, y, a), 
                  yRotate(x + (r2 * cos(i * (PI / 180.0))), y - (r2 * sin(i * (PI / 180.0))), x, y, a), r, g, b);
    
  }
  
}

// Define a function for drawing a quadrilateral given its four vertices and a color
void drawQuadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int r, int g, int b) {
  
  // Draw the first triangle in the quadrilateral
  graphics_triangle_fill(x1, y1, x2, y2, x3, y3, r, g, b);
  
  // Draw the second triangle in the quadrilateral
  graphics_triangle_fill(x1, y1, x4, y4, x3, y3, r, g, b);
  
}