#define POWER_MAX 20.0
#define POWER_BAR_X 5
#define POWER_BAR_Y 5

// Define a function that draws the power meter at a given power
void drawPower(double r) {
 
  // Define constants to hold the bounds of power meter
  const int LEFT_X = POWER_BAR_X;
  const int TOP_Y = POWER_BAR_Y;
  const int RIGHT_X = POWER_BAR_X + 35;
  const int BOTTOM_Y = POWER_BAR_Y + 204;
  
  // Define constants to hold the rgb values of the power meter border
  const int BORDER_R = 0;
  const int BORDER_G = 0;
  const int BORDER_B = 0;
  
  // Draw the border rectangle of the power meter
  graphics_triangle_fill(LEFT_X, TOP_Y, LEFT_X, BOTTOM_Y, RIGHT_X, TOP_Y, BORDER_R, BORDER_G, BORDER_B);
  graphics_triangle_fill(RIGHT_X, TOP_Y, RIGHT_X, BOTTOM_Y, LEFT_X, BOTTOM_Y, BORDER_R, BORDER_G, BORDER_B);
  
  // Define  a constant to hold the number of colors in the power meter
  const int NUM_COLORS = 50;
  
  // Define a constant to hold the inset for the colors
  const int INSET = 2;
  
  // Define constants to hold the bounds of the colors
  const int COLORS_TOP_Y = TOP_Y + INSET;
  const int COLORS_BOTTOM_Y = BOTTOM_Y - INSET;
  const int COLORS_LEFT_X = LEFT_X + INSET;
  const int COLORS_RIGHT_X = RIGHT_X - INSET;
  
  // Define a constant to hold the height of the individual colors
  const int Y_INCREMENT = (COLORS_BOTTOM_Y - COLORS_TOP_Y) / NUM_COLORS;
  
  // Define a constant to hold the increment to the rgb values
  const int COLOR_INCREMENT = (255 / (NUM_COLORS / 2.0)) + 1;
  
  // Define an rgb object to hold the color of the first rectangle
  rgb color;
  color.r = 0;
  color.g = 255;
  color.b = 0;
  
  // Define a variable to start from the top of power meter
  int i = 0;
  
  // Draw the colors
  for (i = 0; i < NUM_COLORS; ++i) {
    
    // Draw the rectangle of the current color
    graphics_triangle_fill(COLORS_LEFT_X, (i * Y_INCREMENT) + COLORS_TOP_Y, COLORS_RIGHT_X, (i * Y_INCREMENT) + COLORS_TOP_Y,
                           COLORS_LEFT_X, ((i + 1) * Y_INCREMENT) + COLORS_TOP_Y, color.r, color.g, color.b);
    graphics_triangle_fill(COLORS_RIGHT_X, (i * Y_INCREMENT) + COLORS_TOP_Y, COLORS_RIGHT_X, ((i + 1) * Y_INCREMENT) + COLORS_TOP_Y,
                           COLORS_LEFT_X, ((i + 1) * Y_INCREMENT) + COLORS_TOP_Y, color.r, color.g, color.b);
    
    // If the color is before the half way mark, increase the red value
    if (i < (NUM_COLORS / 2)) {
      
      // Increase the red value
      color.r += COLOR_INCREMENT;
      
      // If the red value is over the maximum, set it to the maximum
      if (color.r > 255) {
        
        // Set the red value to the maximum
        color.r = 255;
        
      }
      
    }
    
    // If the color is after the half way mark, decrease the green value
    else {
      
      // Decrease the green value
      color.g -= COLOR_INCREMENT;
      
      // If the green value is below the minimum, set it to the minimum
      if (color.g < 0) {
        
        // Set the green value to the minimum
        color.g = 0;
        
      }
      
    }
    
  }
  
  // Define constants to hold the rgb values of the power indicator
  const int INDICATOR_R = 0;
  const int INDICATOR_G = 0;
  const int INDICATOR_B = 0;
  
  // Define a constant to hold the side of the triangles in the power indicator
  const int INDICATOR_SIDE = 4;
  
  // Redefine r as the y increment
  r = (r / POWER_MAX) * ((COLORS_BOTTOM_Y - COLORS_TOP_Y) - INDICATOR_SIDE);
  
  // Draw the triangles on the side of the power indicator
  graphics_triangle_fill(COLORS_LEFT_X, COLORS_BOTTOM_Y - r, COLORS_LEFT_X, COLORS_BOTTOM_Y - r - INDICATOR_SIDE, 
                         COLORS_LEFT_X + INDICATOR_SIDE, COLORS_BOTTOM_Y - r - (INDICATOR_SIDE / 2), 
                         INDICATOR_R, INDICATOR_G, INDICATOR_B);
  graphics_triangle_fill(COLORS_RIGHT_X, COLORS_BOTTOM_Y - r, COLORS_RIGHT_X, COLORS_BOTTOM_Y - r - INDICATOR_SIDE,
                         COLORS_RIGHT_X - INDICATOR_SIDE, COLORS_BOTTOM_Y - r - (INDICATOR_SIDE / 2), 
                         INDICATOR_R, INDICATOR_G, INDICATOR_B);
  
  // Draw the power indicator line
  graphics_line(COLORS_LEFT_X + INDICATOR_SIDE, COLORS_BOTTOM_Y - r - (INDICATOR_SIDE / 2), 
                COLORS_RIGHT_X - INDICATOR_SIDE, COLORS_BOTTOM_Y - r - (INDICATOR_SIDE / 2), INDICATOR_R, INDICATOR_G, INDICATOR_B);
  
}