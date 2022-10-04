#define SCORE_X 407
#define SCORE_Y 5

// Define a struct to represent the shot counter
typedef struct shotCounter_struct {
  
  // Declare a variable to represent the number of taken shots
  int takenShots;
  
  // Declare a variable to represent the number of total shots
  int totalShots;
  
  // Declare a variable to represent the number of made shots
  int madeShots;
  
  // Declare a variable to represent the high score
  int high;
  
  // Declare a variable to represent the game mode
  int mode;
  
} shotCounter;

// Define a function that draws the score counter given a shot counter
void drawScore(shotCounter sc) {
  
  // Define constants to hold the right and bottom bounds of the score counter
  const int SCORE_RIGHT_X = WIDTH - 5;
  const int SCORE_BOTTOM_Y = SCORE_Y + 60;
  
  // Define constants to hold the rgb values of the score counter background
  const int SCORE_R = 120;
  const int SCORE_G = 120;
  const int SCORE_B = 120;
  
  // Draw the score counter background
  graphics_triangle_fill(SCORE_X, SCORE_Y, SCORE_X, SCORE_BOTTOM_Y, SCORE_RIGHT_X, SCORE_Y,SCORE_R, SCORE_G, SCORE_B);
  graphics_triangle_fill(SCORE_RIGHT_X, SCORE_Y, SCORE_RIGHT_X, SCORE_BOTTOM_Y, SCORE_X, SCORE_BOTTOM_Y, SCORE_R, SCORE_G, SCORE_B);
  
  // Define a constant to hold the scale of the text
  const double SCALE = 3.0;
  
  // Define constants to hold the rgb values of the text
  const int CHAR_R = 255;
  const int CHAR_G = 255;
  const int CHAR_B = 255;
  
  // Draw the text to indicate the current score and the high score
  g_printString("SCORE:", SCORE_X + ((SCALE * 3) / 2), SCORE_Y + SCALE, CHAR_R, CHAR_G, CHAR_B, SCALE);
  g_printString("HIGH:", SCORE_X + ((SCALE * 3) / 2), SCORE_Y + SCALE + ((SCORE_BOTTOM_Y - SCORE_Y) / 2), CHAR_R, CHAR_G, CHAR_B, SCALE);
  
  // Define a constant to hold the x position of the numbers
  const int NUM_X = SCORE_X + (7 * 6 * SCALE);
  
  // If there are single-digit made shots draw the made shots shifted
  if ((sc.madeShots / 10) < 1) {
    
    // Draw the made shots shifted
	g_printInt(sc.madeShots, 1, NUM_X + (7 * SCALE), SCORE_Y + SCALE, CHAR_R, CHAR_G, CHAR_B, SCALE);
    
  }
  
  // If there are double-digit made shots draw the made shots
  else {
    
    // Draw the made shots
    g_printInt(sc.madeShots, 0, NUM_X, SCORE_Y + SCALE, CHAR_R, CHAR_G, CHAR_B, SCALE);
    
  }
  
  // If the high score is single-digits, draw the high score shifted
  if ((sc.high / 10) < 1) {
    
    // Draw the high score shifted
	g_printInt(sc.high, 1, NUM_X + (7 * SCALE), SCORE_Y + SCALE + ((SCORE_BOTTOM_Y - SCORE_Y) / 2), CHAR_R, CHAR_G, CHAR_B, SCALE);
    
  }
  
  // If the high score is double-digits, draw the high score
  else {
    
    // Draw the high score
    g_printInt(sc.high, 0, NUM_X, SCORE_Y + SCALE + ((SCORE_BOTTOM_Y - SCORE_Y) / 2), CHAR_R, CHAR_G, CHAR_B, SCALE);
    
  }
  
}