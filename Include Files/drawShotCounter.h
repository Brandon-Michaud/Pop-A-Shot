#define SHOT_COUNTER_X WIDTH / 2
#define SHOT_COUNTER_Y 5

// Define a function that draws the shot counter
void drawShotCounter(shotCounter sc) {
  
  // Define constants to hold the rgb values of the background color of the shot counter
  const int BACKGROUND_R = 120;
  const int BACKGROUND_G = 120;
  const int BACKGROUND_B = 120;
  
  // Define constants to hold the left, right, and bottom bounds of the shot counter
  const int SHOT_COUNTER_BOTTOM_Y = SHOT_COUNTER_Y + 60;
  const int SHOT_COUNTER_LEFT_X = SHOT_COUNTER_X - 100;
  const int SHOT_COUNTER_RIGHT_X = SHOT_COUNTER_X + 100;
  
  // Draw the background of tbe shot counter
  graphics_triangle_fill(SHOT_COUNTER_LEFT_X, SHOT_COUNTER_Y, SHOT_COUNTER_LEFT_X, SHOT_COUNTER_BOTTOM_Y, 
                         SHOT_COUNTER_RIGHT_X, SHOT_COUNTER_Y, BACKGROUND_R, BACKGROUND_G, BACKGROUND_B);
  graphics_triangle_fill(SHOT_COUNTER_RIGHT_X, SHOT_COUNTER_Y, SHOT_COUNTER_RIGHT_X, SHOT_COUNTER_BOTTOM_Y,
                         SHOT_COUNTER_LEFT_X, SHOT_COUNTER_BOTTOM_Y, BACKGROUND_R, BACKGROUND_G, BACKGROUND_B);
  
  // Define a constant to hold the margins of the shot counter
  const int MARGIN = 5;
  
  // Define constants to hold the rgb values of the numbers
  const int NUM_R = 255;
  const int NUM_G = 255;
  const int NUM_B = 255;
  
  // Define a constant to hold the scale of the numbers
  const double SCALE = 5.0;
  
  // Define constants to hold x and y positions of the first number and second number
  const int FIRST_NUM_X = SHOT_COUNTER_LEFT_X + MARGIN + ((SCALE * 3) / 2);
  const int FIRST_NUM_Y = SHOT_COUNTER_Y + MARGIN + SCALE;
  const int SECOND_NUM_X = FIRST_NUM_X + (7 * SCALE);
  
  // If the number of taken shots is single-digits, draw the taken shots at the second number position
  if ((sc.takenShots / 10) < 1) {
    
    // Draw the taken shots at the second number position
  	g_printInt(sc.takenShots, 1, SECOND_NUM_X, FIRST_NUM_Y, NUM_R, NUM_G, NUM_B, SCALE);
    
  }
  
  // If the number of taken shots is double-digits, draw the taken shots at the first number position
  else {
    
    // Draw the taken shots at the first number position
  	g_printInt(sc.takenShots, 0, FIRST_NUM_X, FIRST_NUM_Y, NUM_R, NUM_G, NUM_B, SCALE);
    
  }
  
  // Define a constant to hold the x position of the third number
  const int THIRD_NUM_X = SHOT_COUNTER_RIGHT_X - MARGIN + ((SCALE * 3) / 2) - (7 * 2 * SCALE);
  
  // Draw the total shots at the third number position
  g_printInt(sc.totalShots, 0, THIRD_NUM_X, FIRST_NUM_Y, NUM_R, NUM_G, NUM_B, SCALE);
  
  // Draw the slash inbetween the taken shots and made shots
  graphics_line(SECOND_NUM_X + (7 * SCALE) - ((SCALE * 3) / 2) + MARGIN, FIRST_NUM_Y + (SCALE * 8), 
                THIRD_NUM_X - ((SCALE * 3) / 2) - MARGIN, FIRST_NUM_Y, NUM_R, NUM_G, NUM_B);
  
  // Draw the score counter
  drawScore(sc);
  
}