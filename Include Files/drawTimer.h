#define TIMER_X WIDTH / 2
#define TIMER_Y 5

// Define a struct to represent a timer
typedef struct timer_struct {
  int sec;
  int begin;
  int totalSec;
} timer;

// Define a function to draw a given timer
void drawTimer(shotCounter sc, timer t) {
  
  // Define a constant to hold the scale of the text
  const double SCALE = 5.0;
  
  // Define constants to hold the left, right, and bottom bounds of the timer background
  const int TIMER_LEFT_X = TIMER_X - 100;
  const int TIMER_RIGHT_X = TIMER_X + 100;
  const int TIMER_BOTTOM_Y = TIMER_Y + 60;
  
  // Define constants to hold the rgb values of the background color
  const int TIMER_R = 120;
  const int TIMER_G = 120;
  const int TIMER_B = 120;
  
  // Draw the background of the timer
  graphics_triangle_fill(TIMER_LEFT_X, TIMER_Y, TIMER_LEFT_X, TIMER_BOTTOM_Y, TIMER_RIGHT_X, TIMER_Y, TIMER_R, TIMER_G, TIMER_B);
  graphics_triangle_fill(TIMER_RIGHT_X, TIMER_Y, TIMER_RIGHT_X, TIMER_BOTTOM_Y, TIMER_LEFT_X, TIMER_BOTTOM_Y, TIMER_R, TIMER_G, TIMER_B);
  
  // Define constants to hold the x and y positions of the minute value
  const int MIN_X = TIMER_X - (7 * SCALE * 2) + ((SCALE * 3) / 2);
  const int MIN_Y = TIMER_Y + 5 + SCALE;
  
  // Define constants to hold the rgb values of the numbers
  const int NUM_R = 255;
  const int NUM_G = 255;
  const int NUM_B = 255;
  
  // If there are 0 minutes left, draw 0 in the minutes position
  if ((t.totalSec - t.sec) / 60 < 1) {
    
    // Draw 0 in the minutes position
    g_printString("0", MIN_X, MIN_Y, NUM_R, NUM_G, NUM_B, SCALE);
    
  }
  
  // If there are 1 or more minutes left, draw the minutes left
  else {
    
    // Draw the minutes left
    g_printInt((t.totalSec - t.sec) / 60, 0, MIN_X, MIN_Y, NUM_R, NUM_G, NUM_B, SCALE);
    
  }
  
  // Define a constant to hold the x position of the seconds value
  const int SEC_X = MIN_X + (7 * 2 * SCALE);
  
  // If there are no seconds left, draw 00 in the seconds positon
  if ((t.totalSec - t.sec) % 60 < 1) {
    
    // Draw 00 in the seconds positon
	g_printString("00", SEC_X, MIN_Y, NUM_R, NUM_G, NUM_B, SCALE);
    
  }
  
  // If there are less than 10 seconds left, draw 0 in the first digit of the seconds positon and the seconds in the second position
  else if ((((t.totalSec - t.sec) % 60) / 10) < 1) {
    
    // Draw 0 in the first digit of the seconds positon and the seconds in the second position
	g_printString("0", SEC_X, MIN_Y, NUM_R, NUM_G, NUM_B, SCALE);
    g_printInt((t.totalSec - t.sec) % 60, 0, SEC_X + (7 * SCALE), MIN_Y, NUM_R, NUM_G, NUM_B, SCALE);
    
  }
  
  // If there are greater than or equal to ten seconds left, draw the seconds
  else {
    
    // Draw the seconds
    g_printInt((t.totalSec - t.sec) % 60, 0, SEC_X, MIN_Y, NUM_R, NUM_G, NUM_B, SCALE);
    
  }
  
  // Define constants to hold the x and y positons of the colon dots
  const int TOP_COLON_X = MIN_X + (7 * 1.5 * SCALE) - ((SCALE * 3) / 2);
  const int TOP_COLON_Y = MIN_Y - SCALE + 17;
  const int BOTTOM_COLON_Y = MIN_Y - SCALE + 33;
  const int COLON_RADIUS = 3;
  
  // Draw the colon dots
  graphics_circle_fill(TOP_COLON_X, TOP_COLON_Y, COLON_RADIUS, NUM_R, NUM_G, NUM_B);
  graphics_circle_fill(TOP_COLON_X, BOTTOM_COLON_Y, COLON_RADIUS, NUM_R, NUM_G, NUM_B);
  
  // Draw the score counter
  drawScore(sc);
  
}