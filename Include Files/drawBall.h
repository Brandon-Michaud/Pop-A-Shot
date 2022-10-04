#define BALL_RADIUS 13

// Define a struct to represent a ball
typedef struct ball_struct {
  
  // Declare variables to hold the coordinates of the ball
  double x;
  double y;
  
  // Declare variables the color of the ball and its index in the color array
  rgb ball;
  int ballIdx;
  
  // Declare variables the color of the seam and its index in the color array
  rgb seam;
  int seamIdx;
  
} ball;

// Define a function to initialize the colors of a given ball
void ballInitializer(ball* b) {
  
  // Declare an array to hold colors
  rgb colors[100];
  
  // Populate the array with colors
  getColors(colors);
  
  // Define variables to hold the default color of the ball and its index in the color array
  b->ballIdx = 28;
  b->ball = colors[28];
  
  // Define variables to hold the default color of the seam and its index in the color array
  b->seamIdx = 27;
  b->seam = colors[27];
  
}

// Define a function to draw a given ball at a given rotation
void drawBall(ball* b, double a) {
  
  // Convert the given angle into radians
  double r = a * (PI / 180.0);
  
  // Define a constant to hold the radius of the ball
  const int RADIUS = BALL_RADIUS;
  
  // Draw the ball at its position, radius, and color
  graphics_circle_fill(b->x, b->y, RADIUS, b->ball.r, b->ball.g, b->ball.b);
  
  // Draw the two cross seams of the ball
  graphics_line(xRotate(b->x, b->y + RADIUS, b->x, b->y, r), yRotate(b->x, b->y + RADIUS, b->x, b->y, r), 
                xRotate(b->x, b->y - RADIUS, b->x, b->y, r), yRotate(b->x, b->y - RADIUS, b->x, b->y, r), 
                b->seam.r, b->seam.g, b->seam.b);
  graphics_line(xRotate(b->x + RADIUS, b->y, b->x, b->y, r), yRotate(b->x + RADIUS, b->y, b->x, b->y, r), 
                xRotate(b->x - RADIUS, b->y, b->x, b->y, r), yRotate(b->x - RADIUS, b->y, b->x, b->y, r), 
                b->seam.r, b->seam.g, b->seam.b);
  
  // Define constants to hold the x positions of the center of the left seam and right seam circles
  const int LEFT_SEAM_X = b->x - (RADIUS * 1.3);
  const int RIGHT_SEAM_X = b->x + (RADIUS * 1.3);
  
  // Define a variable to iterate through every angle
  int angle = 0;
  
  // For every angle, draw the pixel if it is within the bounds
  while (angle < 360) {
    
    // Define x and y shifts
    int x = cos(angle * (PI / 180.0)) * RADIUS;
    int y = sin(angle * (PI / 180.0)) * RADIUS;
    
    // Define the bound x and y shifts
    int bx = cos((angle * -1) * (PI / 180.0)) * RADIUS;
    int by = sin((angle * -1) * (PI / 180.0)) * RADIUS;
    
    // Declare variable to hold the left, right, upper, and bottom bounds
    int LB, RB, UB, BB;
    
    // If the angle is greater than -180, set the bounds accordingly
    if ((angle * -1) > -180) {

      // Set the bounds accordingly
      UB = b->y + by;
      BB = b->y - by;
      
    }
    
    // If the angle is less than or equal to -180, set the bounds accordingly
    else {

      // Set the bounds accordingly
      UB = b->y - by;
      BB = b->y + by;
      
    }
    
    // If the angle is greater than -270 and less than -90, set the bounds accordingly
    if ((angle * -1) < -90 && (angle * -1) > -270){
      
      // Set the bounds accordingly
      LB = b->x + bx;
      RB = b->x - bx;
      
    }
    
    // If the angle is less than or equal to -270 or greater than or equal to -90, set the bounds accordingly
    else {
      
      // Set the bounds accordingly
      LB = b->x - bx;
      RB = b->x + bx;
      
    }
    
    // If the current left seam pixel is within the bounds, fill it with the seam color
    if (((((x + LEFT_SEAM_X) <= RB) && ((x + LEFT_SEAM_X) >= LB)) && ((y + b->y) <= BB)) && ((y + b->y) >= UB)) {
      
      // Fill the current left seam pixel with the seam color
      graphics_pixel(xRotate(x + LEFT_SEAM_X, y + b->y, b->x, b->y, r), yRotate(x + LEFT_SEAM_X, y + b->y, b->x, b->y, r), 
                     b->seam.r, b->seam.g, b->seam.b);
      
    }
    
    // If the current right seam pixel is within the bounds, fill it with the seam color
    if (((((x + RIGHT_SEAM_X) <= RB) && ((x + RIGHT_SEAM_X) >= LB)) && ((y + b->y) <= BB)) && ((y + b->y) >= UB)) {
      
      // Fill the current right seam pixel with the seam color
      graphics_pixel(xRotate(x + RIGHT_SEAM_X, y + b->y, b->x, b->y, r), yRotate(x + RIGHT_SEAM_X, y + b->y, b->x, b->y, r), 
                     b->seam.r, b->seam.g, b->seam.b);
      
    }
    
    // Increment the angle
    ++angle;
    
  }
  
}