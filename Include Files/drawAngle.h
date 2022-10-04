#define ANGLE_METER_X 45
#define ANGLE_METER_Y 65

// Define a function that draws an angle meter given an angle
void drawAngle(double a) {
  
  // Convert the given angle to radians
  double r = a * (PI / 180.0);
  
  // Define constants to hold the rgb values of the angle meter background
  const int METER_R = 255;
  const int METER_G = 255;
  const int METER_B = 255;
  
  // Define constants to hold the rgb values of the angle meter border
  const int BORDER_R = 0;
  const int BORDER_G = 0;
  const int BORDER_B = 0;
  
  // Define constants to hold the rgb values of the angle meter hashes
  const int HASH_R = 133;
  const int HASH_G = 133;
  const int HASH_B = 133;
  
  // Define a constant to hold the radius of the angle meter
  const int METER_RADIUS = 60;
  
  // Define constants to hold the hash insets
  const int HASH_INSET_SHORT = METER_RADIUS / 10;
  const int HASH_INSET_LONG = (METER_RADIUS / 5) * 3;
  
  // Declare a variable to iterate through angles
  int i;
  
  // Draw the angle meter background and border
  for (i = 0; i <= 90; ++i) {
    
    // Draw a vertical line at the current x cordinate from the top of the angle meter to the bottom
    graphics_line(ANGLE_METER_X + (METER_RADIUS * cos(i * (PI / 180.0))), ANGLE_METER_Y, 
                  ANGLE_METER_X + (METER_RADIUS * cos(i * (PI / 180.0))), ANGLE_METER_Y - (METER_RADIUS * sin(i * (PI / 180.0))), 
                  METER_R, METER_G, METER_B);
    
    // Draw a pixel at the border
    graphics_pixel(ANGLE_METER_X + (METER_RADIUS * cos(i * (PI / 180.0))) + 1, ANGLE_METER_Y - (METER_RADIUS * sin(i * (PI / 180.0))),
                   BORDER_R, BORDER_G, BORDER_B);
    
  }
  
  // Define the angle to start at 15
  i = 15;
  
  // Draw the hashes
  while (i < 90) {
    
    // Draw the hash at the given angle
    graphics_line(xRotate(ANGLE_METER_X, ANGLE_METER_Y - HASH_INSET_LONG, ANGLE_METER_X, ANGLE_METER_Y, i * (PI / -180.0)), 
                  yRotate(ANGLE_METER_X, ANGLE_METER_Y - HASH_INSET_LONG, ANGLE_METER_X, ANGLE_METER_Y, i * (PI / -180.0)), 
                  xRotate(ANGLE_METER_X, ANGLE_METER_Y - METER_RADIUS + HASH_INSET_SHORT, ANGLE_METER_X, ANGLE_METER_Y, i * (PI / -180.0)), 
                  yRotate(ANGLE_METER_X, ANGLE_METER_Y - METER_RADIUS + HASH_INSET_SHORT, ANGLE_METER_X, ANGLE_METER_Y, i * (PI / -180.0)),
                  HASH_R, HASH_G, HASH_B);
    
    // Increment the angle by 15
    i = i + 15;
    
  }
  
  // Draw the straight borders of the angle meter
  graphics_line(ANGLE_METER_X, ANGLE_METER_Y, ANGLE_METER_X, ANGLE_METER_Y - METER_RADIUS, BORDER_R, BORDER_G, BORDER_B);
  graphics_line(ANGLE_METER_X, ANGLE_METER_Y, ANGLE_METER_X + METER_RADIUS, ANGLE_METER_Y, BORDER_R, BORDER_G, BORDER_B);
 
  // Define constants to hold the rgb values of the arrow
  const int ARROW_R = 0;
  const int ARROW_G = 0;
  const int ARROW_B = 0;
  
  // Define constants to hold the bounds of the arrow
  const int TOP_ARROW_Y = ANGLE_METER_Y - METER_RADIUS;
  const int BOTTOM_TIP_Y = TOP_ARROW_Y + 7;
  const int BOTTOM_TIP_LEFT_X = ANGLE_METER_X - 3;
  const int BOTTOM_TIP_RIGHT_X = ANGLE_METER_X + 3;
  
  // Draw the body of the arrow
  graphics_line(ANGLE_METER_X, ANGLE_METER_Y, xRotate(ANGLE_METER_X, TOP_ARROW_Y, ANGLE_METER_X, ANGLE_METER_Y, r), 
                yRotate(ANGLE_METER_X, TOP_ARROW_Y, ANGLE_METER_X, ANGLE_METER_Y, r), ARROW_R, ARROW_G, ARROW_B);
  
  // Draw the tip of the arrow
  graphics_triangle_fill(xRotate(ANGLE_METER_X, TOP_ARROW_Y, ANGLE_METER_X, ANGLE_METER_Y, r), 
                         yRotate(ANGLE_METER_X, TOP_ARROW_Y, ANGLE_METER_X, ANGLE_METER_Y, r), 
                    	 xRotate(BOTTOM_TIP_LEFT_X, BOTTOM_TIP_Y, ANGLE_METER_X, ANGLE_METER_Y, r), 
                         yRotate(BOTTOM_TIP_LEFT_X, BOTTOM_TIP_Y, ANGLE_METER_X, ANGLE_METER_Y, r), 
                   	 	 xRotate(BOTTOM_TIP_RIGHT_X, BOTTOM_TIP_Y, ANGLE_METER_X, ANGLE_METER_Y, r), 
                         yRotate(BOTTOM_TIP_RIGHT_X, BOTTOM_TIP_Y, ANGLE_METER_X, ANGLE_METER_Y, r), ARROW_R, ARROW_G, ARROW_B);
  
}